import * as fs from 'fs';
import { EntityMap, nosync } from 'colyseus';
import * as Config from '../config';
import { CombatConsts, CombatAbilities, CombatPlayer, CombatSystem } from '../FoFcombat';
import * as FoFcombat from '../FoFcombat';

export class CombatState
{
	@nosync
	combatSystem : CombatSystem;
	
	players : EntityMap = {};
	
	constructor()
	{
		this.combatSystem = new CombatSystem(Config.MAP_WIDTH, Config.MAP_HEIGHT);
		this.createMapObstacles();
	}
	
	createMapObstacles()
	{
		const cs = this.combatSystem;
		const contents = fs.readFileSync('map.json');
		const mapData = JSON.parse(contents);
		for (let i in mapData)
		{
			const tile = mapData[i];
			cs.setTileState(tile.x, tile.y, tile.z, tile.state);
		}
	}
	
	createPlayer(id : string)
	{
		const cs = this.combatSystem;
		
		const player = new CombatPlayer();
		player.id = id;
	
		// randomly choosing player starting position on the map
		let found = false;
		player.mapTileZ = CombatConsts.MAP_GROUND_FLOOR;
		
		player.mapTileX = Math.floor(Math.random() * cs.mapWidth);
		player.mapTileY = Math.floor(Math.random() * cs.mapHeight);
		do
		{
			player.mapTileX = Math.floor(Math.random() * cs.mapWidth);
			player.mapTileY = Math.floor(Math.random() * cs.mapHeight);
		}
		while (cs.getTileState(player.mapTileX, player.mapTileY, player.mapTileZ) != CombatConsts.MAP_TILE_FREE);
		
		player.abilities = new CombatAbilities();
		for (let i in Config.PLAYER_ABILITIES)
		{
			player.abilities[i] = Config.PLAYER_ABILITIES[i];
		}
		cs.addPlayer(player);
		
		this.players[id] = player;
		
		console.log(`Player ${player.id} spawned on (${player.mapTileX}, ${player.mapTileY})`);
	}
	
	removePlayer(id : string)
	{
		this.combatSystem.removePlayerByID(id);
		delete this.players[id];
	}
	
	setPlayerMovement(id : string, movementX : number, movementY : number)
	{
		const player = this.players[id];
		player.movementX = movementX;
		player.movementY = movementY;
	}
	
	update(delta : number)
	{
		this.combatSystem.tick(delta);
	}
}

