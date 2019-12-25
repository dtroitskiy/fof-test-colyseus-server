import { Room, Client } from 'colyseus';
import { CombatData, Movement, Position, SelectedEquipment, ChangingAbility, Creature, CombatState } from '../states/combat';
import { Loader } from '../loader';
import { Vector2, CombatSystem, UniversalTileMap, CreatureCombatData, CombatAbilities, CombatEquipment, CombatSpell, VectorCombatSpell,
         CombatTalent, VectorCombatTalent, AbilityChangeSource, CreatureHPChangedCallback, CreatureMPChangedCallback,
         CreatureMissCallback, CreatureFullDefCallback, CreatureCritReceivedCallback, CreatureKilledCallback,
         EffectPlayRequestedCallback  } from '../FoFcombat/FoFcombat';

export class TestRoom extends Room
{
	static SYNC_INTERVAL: number = 1000;

	state: CombatState;

	isLoaded: boolean = false;

	universalTileMap: UniversalTileMap = null;
	combatSystem: CombatSystem = null;

	creatures: object = null;

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

	onMessage(client: Client, data: any)
	{
		switch (data.message)
		{
			case 'addPlayer':
				this.handlePlayerAdd(client, data);
			break;
			case 'movement':
				this.handleMovement(client, data);
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

		this.setState(new CombatState());
		// TODO: enable if precise positioning will be needed
		// this.setPatchRate(1000 / 60);
		this.setSimulationInterval(() =>
		{
			this.update(this.clock.deltaTime / 1000);
		});
		this.clock.setInterval(this.sync.bind(this), TestRoom.SYNC_INTERVAL);
		
		this.isLoaded = true;
	}

	handlePlayerAdd(client: Client, data: any)
	{
		const creatureID = client.sessionId;
		
		this.addCreature(creatureID, data.combatData);
		
		const floor = this.combatSystem.getCreatureFloor(creatureID);
		const pos = this.combatSystem.getCreaturePosition(creatureID);

		const creature = new Creature();
		creature.id = creatureID;
		creature.combatData = new CombatData(data.combatData);
		creature.movement = new Movement(0, 0);
		creature.position = new Position(pos.x, pos.y, floor);
		creature.selectedWeapon = new SelectedEquipment(true);
		creature.selectedAmmo = new SelectedEquipment(true);
		creature.HP = new ChangingAbility(this.combatSystem.getCreatureCurrentHP(creatureID), this.combatSystem.getCreatureTotalHP(creatureID));
		creature.MP = new ChangingAbility(this.combatSystem.getCreatureCurrentMP(creatureID), this.combatSystem.getCreatureTotalMP(creatureID));

		this.state.creatures[creatureID] = creature;

		client.isLoaded = true;
	}

	handleMovement(client: Client, data: any)
	{
		this.combatSystem.setCreatureMovement(client.sessionId, data.movementX, data.movementY);
		const creatureMovement = this.state.creatures[client.sessionId].movement;
		creatureMovement.x = data.movementX;
		creatureMovement.y = data.movementY;
	}

	handleWeaponSwap(client: Client, data: any)
	{
		this.combatSystem.swapCreatureWeapon(client.sessionId);
		const creature = this.state.creatures[client.sessionId];
		creature.selectedWeapon.isPrimary = this.combatSystem.hasCreaturePrimaryWeaponSelected(client.sessionId);
	}

	handleAmmoSwap(client: Client, data: any)
	{
		this.combatSystem.swapCreatureAmmo(client.sessionId);
		const creature = this.state.creatures[client.sessionId];
		creature.selectedAmmo.isPrimary = this.combatSystem.hasCreaturePrimaryAmmoSelected(client.sessionId);
	}

	handlePlayerUsedSpell(client: Client, data: any)
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
		if (!this.creatures) return;
		const creature = this.state.creatures[creatureID];
		if (!creature) return;
		if (creature.HP.current == currentHP && creature.HP.total == totalHP) return;

		creature.HP.current = currentHP;
		creature.HP.total = totalHP;
		creature.HP.changeType = changeType;
	}

	onCreatureMPChanged(creatureID: string, currentMP: number, totalMP: number, changeType: number)
	{
		if (!this.creatures) return;
		const creature = this.creatures[creatureID];
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
		delete this.creatures[killedCreatureID];
		const message = { 'message': 'creatureKilled', 'killerCreatureID': killerCreatureID, 'killedCreatureID': killedCreatureID };
		this.broadcast(message);
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

	sync()
	{
		const creatures = this.state.creatures;
		for (let id in creatures)
		{
			const creature = creatures[id];
			creature.position.z = this.combatSystem.getCreatureFloor(creature.id);
			const pos = this.combatSystem.getCreaturePosition(creature.id);
			creature.position.x = pos.x;
			creature.position.y = pos.y;
		}
	}

	update(dt: number)
	{
		this.combatSystem.update(dt);
	}
}
