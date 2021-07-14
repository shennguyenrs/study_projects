import http from "http";
import app from "./app";
import dotenv from "dotenv";

dotenv.config();

const server = http.createServer(app);
const SERVER_PORT = process.env.SERVER_PORT;

server.listen(SERVER_PORT, () => {
  console.log("Server is listening on port ", SERVER_PORT);
});
