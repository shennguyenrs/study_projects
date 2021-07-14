import dotenv from "dotenv";

dotenv.config();

export const USER = process.env.DBUSER;
export const HOST = process.env.HOST;
export const SQL_PORT = Number(process.env.SQL_PORT);
export const DATABASE = process.env.DATABASE;
export const PASSWD = process.env.PASSWD;
