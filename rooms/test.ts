import { Room, Client } from 'colyseus';
import { CombatDataSchema, PositionSchema, DirectionSchema, SelectedEquipmentSchema, ChangingAbilitySchema,
         CreatureSchema, CombatSchema } from '../states/combat';
import { Loader } from '../loader';
import { Vector2, CombatSystem, UniversalTileMap, CreatureCombatData, CombatAbilities, CombatEquipment, CombatSpell, VectorCombatSpell,
         CombatTalent, VectorCombatTalent, AbilityChangeSource, CreatureHPChangedCallback, CreatureMPChangedCallback,
         CreatureMissCallback, CreatureFullDefCallback, CreatureCritReceivedCallback, CreatureKilledCallback,
         EffectPlayRequestedCallback, FoFSprite } from '../FoFcombat/FoFcombat';

export class TestRoom extends Room
{
	static POSITION_VALIDATION_ENABLED = true;
	static POSITION_VALIDATION_INTERVAL: number = 0.2;
	static POSITION_VALIDATION_ERROR_FACTOR: number = 1.2;

	state: CombatSchema;

	isLoaded: boolean = false;

	universalTileMap: UniversalTileMap = null;
	combatSystem: CombatSystem = null;

	totalTime: number = 0;

	onCreate(options: any)
	{
		console.log('TestRoom created!');
	}

	onJoin(client: Client, options: any)
	{
		console.log(`Client ${client.sessionId} joined TestRoom.`);

		this.send(client, {
			'message': 'load',
			'map': 'test' // map name is constant for now
		});

		this.load();
	}

	onLeave(client: Client, consented: boolean)
	{
		console.log(`Client ${client.sessionId} left TestRoom.`);
		
		this.combatSystem.removeCreature(client.sessionId);
		delete this.state.creatures[client.sessionId];
	}

	onMessage(client: Client, data: object)
	{
		switch (data.message)
		{
			case 'addPlayer':
				this.handlePlayerAdd(client, data);
			break;
			case 'position':
				this.handlePosition(client, data);
			break;
			case 'swapWeapon':
				this.handleWeaponSwap(client, data);
			break;
			case 'swapAmmo':
				this.handleAmmoSwap(client, data);
			break;
			case 'spellUsed':
				this.handlePlayerUsedSpell(client, data);
			break;
		}
	}

	onDispose()
	{
		console.log('TestRoom disposed!');
	}

	broadcast(message: object, excludeClientID: any)
	{
		for (let i = 0; i < this.clients.length; ++i)
		{
			const client = this.clients[i];
			if (client.isLoaded && (!excludeClientID || client.sessionId != excludeClientID))
			{
				this.send(client, message);
			}
		}
	}

	load()
	{
		if (this.isLoaded) return;

		Loader.init();
		Loader.loadDB();
		Loader.loadResources();
		this.universalTileMap = Loader.loadMap();

		this.combatSystem = new CombatSystem(this.universalTileMap, '/res/scripts/');

		const creatureOnHPChangedHandler = new CreatureHPChangedCallback(this.onCreatureHPChanged.bind(this));
		this.combatSystem.addCreatureOnHPChangedHandler(creatureOnHPChangedHandler);
		const creatureOnMPChangedHandler = new CreatureMPChangedCallback(this.onCreatureMPChanged.bind(this));
		this.combatSystem.addCreatureOnMPChangedHandler(creatureOnMPChangedHandler);
		
		const creatureOnMissHandler = new CreatureMissCallback(this.onCreatureMissedHit.bind(this));
		this.combatSystem.addCreatureOnMissHandler(creatureOnMissHandler);
		const creatureOnFullDefHandler = new CreatureFullDefCallback(this.onCreatureGotFullDef.bind(this));
		this.combatSystem.addCreatureOnFullDefHandler(creatureOnFullDefHandler);
		const creatureOnCritReceivedHandler = new CreatureCritReceivedCallback(this.onCreatureCritReceived.bind(this));
		this.combatSystem.addCreatureOnCritReceivedHandler(creatureOnCritReceivedHandler);

		const creatureOnKilledHandler = new CreatureKilledCallback(this.onCreatureKilled.bind(this));
		this.combatSystem.addCreatureOnKilledHandler(creatureOnKilledHandler);

		const effectOnPlayRequestedHandler = new EffectPlayRequestedCallback(this.onEffectPlayRequested.bind(this));
		this.combatSystem.addEffectOnPlayRequestedHandler(effectOnPlayRequestedHandler);

		this.setState(new CombatSchema());
		this.setPatchRate(1000 / 60);
		this.setSimulationInterval(() =>
		{
			this.update(this.clock.deltaTime / 1000);
		});
		
		this.isLoaded = true;
	}

	handlePlayerAdd(client: Client, data: object)
	{
		const creatureID = client.sessionId;
		
		this.addCreature(creatureID, data.combatData);
		
		const floor = this.combatSystem.getCreatureFloor(creatureID);
		const pos = this.combatSystem.getCreaturePosition(creatureID);

		const creature = new CreatureSchema();
		creature.id = creatureID;
		creature.combatData = new CombatDataSchema(data.combatData);
		creature.position = new PositionSchema(pos.x, pos.y, floor);
		creature.lastValidPosition = new PositionSchema(pos.x, pos.y, floor);
		creature.movementDirection = new DirectionSchema(0, 0);
		creature.lookDirection = new DirectionSchema(0, -1);
		creature.selectedWeapon = new SelectedEquipmentSchema(true);
		creature.selectedAmmo = new SelectedEquipmentSchema(true);
		creature.HP = new ChangingAbilitySchema(this.combatSystem.getCreatureCurrentHP(creatureID), this.combatSystem.getCreatureTotalHP(creatureID));
		creature.MP = new ChangingAbilitySchema(this.combatSystem.getCreatureCurrentMP(creatureID), this.combatSystem.getCreatureTotalMP(creatureID));

		this.state.creatures[creatureID] = creature;

		client.isLoaded = true;
	}

	handlePosition(client: Client, data: object)
	{
		const creature = this.state.creatures[client.sessionId];
		
		let isRejected = false;

		if (TestRoom.POSITION_VALIDATION_ENABLED)
		{
			// we validate creature movement here by two conditions:
			// it can't be that creature instantly moved for distance more than one tile
			// and movement within defined validation period can't exceed its maximum allowed movement, considering its speed

			// first check
			const distance = new Vector2(data.position.x - creature.position.x, data.position.y - creature.position.y).length;
			if (distance >= FoFSprite.SIZE)
			{
				isRejected = true;
			}
			// second check
			else if (this.totalTime - creature.lastPositionValidationTime >= TestRoom.POSITION_VALIDATION_INTERVAL)
			{
				const dt = this.totalTime - creature.lastPositionValidationTime;
				const distance = new Vector2(data.position.x - creature.lastValidPosition.x, data.position.y - creature.lastValidPosition.y).length;
				const maxDistance = creature.combatData.abilities.moveSpeed * dt * TestRoom.POSITION_VALIDATION_ERROR_FACTOR;
				if (distance >= maxDistance)
				{
					isRejected = true;
				}
				creature.lastValidPosition.x = data.position.x;
				creature.lastValidPosition.y = data.position.y;
				creature.lastPositionValidationTime = this.totalTime;
			}
		}
		
		if (!isRejected)
		{
			isRejected = !this.combatSystem.setCreaturePosition(client.sessionId, new Vector2(data.position.x, data.position.y));
		}

		if (!isRejected)
		{
			creature.position.x = data.position.x;
			creature.position.y = data.position.y;
			const dir = data.direction;
			creature.movementDirection.x = dir.x;
			creature.movementDirection.y = dir.y;
			if (dir.x != 0 || dir.y != 0)
			{
				creature.lookDirection.x = dir.x;
				creature.lookDirection.y = dir.y;
			}
		}
		else
		{
			this.send(client, { 'message': 'positionRejected' });
		}
	}

	handleWeaponSwap(client: Client, data: object)
	{
		this.combatSystem.swapCreatureWeapon(client.sessionId);
		const creature = this.state.creatures[client.sessionId];
		creature.selectedWeapon.isPrimary = this.combatSystem.hasCreaturePrimaryWeaponSelected(client.sessionId);
	}

	handleAmmoSwap(client: Client, data: object)
	{
		this.combatSystem.swapCreatureAmmo(client.sessionId);
		const creature = this.state.creatures[client.sessionId];
		creature.selectedAmmo.isPrimary = this.combatSystem.hasCreaturePrimaryAmmoSelected(client.sessionId);
	}

	handlePlayerUsedSpell(client: Client, data: object)
	{
		this.combatSystem.setCreatureUsedSpell(client.sessionId, data.spellID, new Vector2(data.position.x, data.position.y));

		const broadcastMessage = {
			'message': 'spellUsed',
			'creatureID': client.sessionId,
			'spellID': data.spellID,
			'position': { 'x': data.position.x, 'y': data.position.y }
		};
		this.broadcast(broadcastMessage, client.sessionId);
	}

	addCreature(creatureID: string, combatData: object)
	{
		combatData = this.makeCreatureCombatDataFromPlainObject(combatData);
		this.combatSystem.addCreature(creatureID, combatData);
		this.combatSystem.setCreatureFloor(creatureID, UniversalTileMap.GROUND_FLOOR);

		// for testing currently spawning creatures on some convenient coordinates in the middle of the map
		// here we search for free tile in the row of possible positions
		let tileX = 21, tileY = 32;
		let tile = null;
		do
		{
			tile = this.universalTileMap.getTile(++tileX, tileY, UniversalTileMap.GROUND_FLOOR);
		}
		while (tile.isBlocking);
		
		this.combatSystem.setCreaturePosition(creatureID, this.combatSystem.makeCreaturePositionForTileCoords(tileX, tileY));
	}

	onCreatureHPChanged(creatureID: string, currentHP: number, totalHP: number, changeType: number)
	{
		const creature = this.state.creatures[creatureID];
		if (!creature) return;
		if (creature.HP.current == currentHP && creature.HP.total == totalHP) return;

		creature.HP.current = currentHP;
		creature.HP.total = totalHP;
		creature.HP.changeType = changeType;
	}

	onCreatureMPChanged(creatureID: string, currentMP: number, totalMP: number, changeType: number)
	{
		const creature = this.state.creatures[creatureID];
		if (!creature) return;
		if (creature.MP.current == currentMP && creature.MP.total == totalMP) return;

		creature.MP.current = currentMP;
		creature.MP.total = totalMP;
		creature.MP.changeType = changeType;
	}

	onCreatureMissedHit(creatureID: string)
	{
		const message = { 'message': 'miss', 'creatureID': creatureID };
		this.broadcast(message);
	}

	onCreatureGotFullDef(creatureID: string)
	{
		const message = { 'message': 'fullDef', 'creatureID': creatureID };
		this.broadcast(message);
	}

	onCreatureCritReceived(creatureID: string, damage: number)
	{
		const message = { 'message': 'crit', 'creatureID': creatureID, 'damage': damage };
		this.broadcast(message);
	}

	onCreatureKilled(killerCreatureID: string, killedCreatureID: string)
	{
		const message = { 'message': 'creatureKilled', 'killerCreatureID': killerCreatureID, 'killedCreatureID': killedCreatureID };
		this.broadcast(message);
		delete this.state.creatures[killedCreatureID];
	}

	onEffectPlayRequested(effectID: string, effectObjectID: number, position: Vector2, floor: number, direction: Vector2)
	{
		const message = {
			'message': 'effectRequested',
			'effectID': effectID,
			'effectObjectID': effectObjectID,
			'position': { 'x': position.x, 'y': position.y, 'z': floor },
			'direction': { 'x': direction.x, 'y': direction.y }
		};
		this.broadcast(message);
	}

	makeCreatureCombatDataFromPlainObject(data: object)
	{
		const combatData = new CreatureCombatData();
	
		combatData.creatureObjectID = data.creatureObjectID;
		combatData.exp = data.exp;
		combatData.level = data.level;
		
		const abilities = new CombatAbilities();
		for (let i in data.abilities)
		{
			const a = data.abilities[i];
			abilities[i] = a;
		}
		combatData.abilities = abilities;
		
		const equipment = new CombatEquipment();
		for (let i in data.equipment)
		{
			const e = data.equipment[i];
			equipment[i] = e;
		}
		combatData.equipment = equipment;

		const spells = new VectorCombatSpell();
		for (let i = 0; i < data.spells.length; ++i)
		{
			const s = data.spells[i];
			const cs = new CombatSpell();
			cs.id = s.id;
			cs.level = s.level;
			spells.push_back(cs);
		}
		combatData.spells = spells;

		const talents = new VectorCombatTalent();
		for (let i = 0; i < data.talents.length; ++i)
		{
			const t = data.talents[i];
			const ct = new CombatTalent();
			ct.id = t.id;
			ct.level = t.level;
			talents.push_back(ct);
		}
		combatData.talents = talents;

		return combatData;
	}

	update(dt: number)
	{
		this.totalTime += dt;
		this.combatSystem.update(dt);
	}
}
