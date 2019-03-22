import { Room } from 'colyseus';
import { CombatState } from '../states/combat';

export class TestRoom extends Room <CombatState>
{		
	onInit(options)
	{
		console.log('TestRoom created!');
		this.setState(new CombatState());
		this.setSimulationInterval(() =>
		{
			this.state.update(this.clock.deltaTime / 1000);
		});
	}

	onJoin(client)
	{
		console.log(`Client ${client.sessionId} joined TestRoom.`);
		
		const cs = this.state.combatSystem;
		this.send(client, {
			'message': 'initCombatSystem',
			'mapWidth': cs.mapWidth,
			'mapHeight': cs.mapHeight,
			'passMap': Array.from(cs.getPassMap())
		});
		this.state.createPlayer(client.sessionId);
	}

	onLeave(client)
	{
		console.log(`Client ${client.sessionId} left TestRoom.`);
		this.state.removePlayer(client.sessionId);
	}

	onMessage(client, data)
	{
		switch (data.message)
		{
			case 'movement':
				this.state.setPlayerMovement(client.sessionId, data.movementX, data.movementY);
			break;
		}
	}

	onDispose()
	{
		console.log('TestRoom disposed!');
	}
}

