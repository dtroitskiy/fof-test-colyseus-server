import { Schema, type } from "@colyseus/schema";
import { Loader } from '../loader';
import { CombatSystem } from '../FoFcombat/FoFcombat';
import * as FoFcombat from '../FoFcombat/FoFcombat';

export class CombatState extends Schema
{
	combatSystem: CombatSystem;
	
	@type("number")
	test: number;

	constructor()
	{
		super();
	
		Loader.init();
		Loader.loadDB();
		Loader.loadResources();
	}
	
	/*createPlayer(id : string)
	{
		const cs = this.combatSystem;
		
		const player = new CombatPlayer();
		player.id = id;
	
		// randomly choosing player starting position on the map
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
	}*/
	
	update(delta : number)
	{
		// this.combatSystem.tick(delta);
	}
}
