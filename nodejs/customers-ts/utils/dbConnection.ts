import { Pool } from "pg";

import * as config from "./config";

// Database connection
const db = new Pool({
  user: config.USER,
  host: config.HOST,
  port: config.SQL_PORT,
  database: config.DATABASE,
  password: config.PASSWD,
});

export default db;
