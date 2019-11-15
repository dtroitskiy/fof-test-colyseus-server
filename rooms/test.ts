import { Room, Client } from 'colyseus';
import { Loader } from '../loader';
import { CombatSystem, UniversalTileMap, CreatureCombatData, CombatAbilities, CombatEquipment,
         CombatSpell, VectorCombatSpell, CombatTalent, VectorCombatTalent } from '../FoFcombat/FoFcombat';

export class TestRoom extends Room
{
	isLoaded:boolean = false;

	universalTileMap: UniversalTileMap = null;
	combatSystem:CombatSystem = null;

	clientIDs: string[] = [];

	onCreate(options: any)
	{
		console.log('TestRoom created!');
	}

	onJoin(client: Client, options: any)
	{
		console.log(`Client ${client.sessionId} joined TestRoom.`);

		this.clientIDs.push(client.sessionId);

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

		const otherClientsMessage = { 'message': 'removeCreature', 'creatureID': client.sessionId };
		for (let i in this.clients)
		{
			const otherClient = this.clients[i];
			if (client.sessionId == otherClient.sessionId) continue;
			this.send(otherClient, otherClientsMessage);
		}
	}

	onMessage(client: Client, data: any)
	{
		switch (data.message)
		{
			case 'addMe':
			{
				this.addCreature(client.sessionId, data.combatData);
				
				const floor = this.combatSystem.getCreatureFloor(client.sessionId);
				const pos = this.combatSystem.getCreaturePosition(client.sessionId);
				
				this.send(client, { 'message': 'addSelf', 'position': { 'x': pos.x, 'y': pos.y, 'z': floor } });

				const otherClientsMessage = {
					'message': 'addCreature',
					'creatureID': client.sessionId,
					'combatData': data.combatData,
					'position': { 'x': pos.x, 'y': pos.y, 'z': floor }
				};
				for (let i in this.clients)
				{
					const otherClient = this.clients[i];
					if (client.sessionId == otherClient.sessionId) continue;
					this.send(otherClient, otherClientsMessage);
				}
			}
			break;
			case 'movement':
			{
				this.combatSystem.setCreatureMovement(client.sessionId, data.movementX, data.movementY);

				const otherClientsMessage = {
					'message': 'movement',
					'creatureID': client.sessionId,
					'movementX': data.movementX,
					'movementY': data.movementY
				};
				for (let i in this.clients)
				{
					const otherClient = this.clients[i];
					if (client.sessionId == otherClient.sessionId) continue;
					this.send(otherClient, otherClientsMessage);
				}
			}
			break;
		}
	}

	onDispose()
	{
		console.log('TestRoom disposed!');
	}

	load()
	{
		if (this.isLoaded) return;

		Loader.init();
		Loader.loadDB();
		Loader.loadResources();
		this.universalTileMap = Loader.loadMap();

		this.combatSystem = new CombatSystem(this.universalTileMap, '/res/scripts/');

		this.setSimulationInterval(() =>
		{
			this.update(this.clock.deltaTime / 1000);
		});
		
		this.isLoaded = true;
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
		for (let i in data.spells)
		{
			const s = data.spells[i];
			const cs = new CombatSpell();
			cs.id = s.id;
			cs.level = s.level;
			spells.push_back(cs);
		}
		combatData.spells = spells;

		const talents = new VectorCombatTalent();
		for (let i in data.talents)
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
		this.combatSystem.update(dt);

		// FIXME: testing
		/*for (let i in this.clientIDs)
		{
			const creatureID = this.clientIDs[i];
			const pos = this.combatSystem.getCreaturePosition(creatureID);
		}*/
	}
}
