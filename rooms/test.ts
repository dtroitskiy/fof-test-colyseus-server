import { Room, Client } from 'colyseus';
import { Loader } from '../loader';

export class TestRoom extends Room
{
	isLoaded:boolean = false;

	onCreate(options: any)
	{
		console.log('TestRoom created!');
		//this.setPatchRate(1000 / 60);
		this.setSimulationInterval(() =>
		{
			this.update(this.clock.deltaTime / 1000);
		});
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
		// this.state.removePlayer(client.sessionId);
	}

	onMessage(client: Client, data: any)
	{
		switch (data.message)
		{
			case 'ready':
				this.send(client, { 'message': 'init' });
			break;
			case 'movement':
				// this.state.setPlayerMovement(client.sessionId, data.movementX, data.movementY);
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
		Loader.loadMap();
		
		this.isLoaded = true;
	}

	update(dt: number)
	{

	}
}
