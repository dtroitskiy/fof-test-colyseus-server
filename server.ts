import { Server } from 'colyseus';
import { createServer } from 'http';
import { TestRoom } from './rooms/test';

const port = process.env.PORT || 8080;
const gameServer = new Server({ server: createServer() });
gameServer.register('test', TestRoom);
gameServer.listen(port);
console.log(`Listening on http://localhost:${port}`);

