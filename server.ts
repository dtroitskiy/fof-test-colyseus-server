// core
import http from 'http';
import express from 'express';
import cors from 'cors';
// colyseus
import { Server } from 'colyseus';
import { monitor } from '@colyseus/monitor';
import { TestRoom } from './rooms/test';
// web
import favicon from 'serve-favicon'
import { Index } from './web/handlers/index';
// API
import { ping } from './api/ping';

const port = Number(process.env.PORT || 8000);
const app = express();

app.use(cors());
app.use(express.json());
app.use('/static', express.static('./web/static'));
app.use(favicon('./web/static/favicon.ico'));
app.set('views', './web/views');
app.set('view engine', 'pug');

const server = http.createServer(app);
const gameServer = new Server({
  server,
  express: app
});

gameServer.define('test', TestRoom);

app.use('/colyseus', monitor(gameServer));

// some web interface
const index = new Index();
app.get('/', index.get.bind(index));

// and some API
app.get('/api/ping', ping);

gameServer.listen(port);
console.log(`Listening on ws://localhost:${port}`);
