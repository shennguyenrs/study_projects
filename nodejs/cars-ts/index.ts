import http from 'http';
import dotenv from 'dotenv';

import app from './src/app';

// Config environment variables
dotenv.config();
const PORT = process.env.PORT;

const server = http.createServer(app);

server.listen(PORT, () => {
  console.log('Server is listening on port', PORT);
});
