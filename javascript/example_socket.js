const express = require('express');
const app = express();
const port = 8080;

const server = require('http').createServer(app);
const io = require('socket.io')(server);

app.use(express.static(__dirname + '/nodes_modules'));
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/example_socket_index.html');
});

server.listen(port, () => {
  console.log('App is listening on port ' + port);
});

io.on('connection', client => {
  console.log('A client connected');

  client.on('diconnect', () => {
    console.log('A client diconnect');
  });
});
