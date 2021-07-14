import express from "express";
import cors from "cors";
import dotenv from "dotenv";
import { Pool } from "pg";

// Environment variables config
dotenv.config();

const USER = process.env.DBUSER;
const HOST = process.env.HOST;
const SQL_PORT = Number(process.env.SQL_PORT);
const DATABASE = process.env.DATABASE;
const PASSWD = process.env.PASSWD;

const app: express.Application = express();

// Middleware
app.use(cors());
app.use(express.json());

// Database connection
const db = new Pool({
  user: USER,
  host: HOST,
  port: SQL_PORT,
  database: DATABASE,
  password: PASSWD,
});

// CRUD functions
// Get all customers
app.get(
  "/api/customers",
  (
    _req: express.Request,
    res: express.Response,
    next: express.NextFunction
  ) => {
    const query = "select * from customers";

    db.query(query, (err, result) => {
      if (err) next(err);
      else {
        if (result.rows.length > 0) res.status(200).json(result.rows);
        else res.status(404).end();
      }
    });
  }
);

// Get customer by id
app.get(
  "/api/customers/:id",
  (req: express.Request, res: express.Response, next: express.NextFunction) => {
    const id = req.params.id;
    const query = {
      text: "select * from customers where id = $1",
      values: [id],
    };

    db.query(query, (err, result) => {
      if (err) next(err);
      else {
        if (result.rows.length > 0) res.status(200).json(result.rows);
        else res.status(404).end();
      }
    });
  }
);

// Post new customer
app.post(
  "/api/customers/",
  (req: express.Request, res: express.Response, next: express.NextFunction) => {
    const data = req.body;
    const query = {
      text: "insert into customers (id, firstname, lastname, email, phone) values ($1, $2, $3, $4, $5)",
      values: [data.id, data.firstname, data.lastname, data.email, data.phone],
    };

    db.query(query, (err, result) => {
      if (err) next(err);
      else res.status(200).json(result.rows);
    });
  }
);

// Delete a customer by id
app.delete(
  "/api/customers/:id",
  (req: express.Request, res: express.Response, next: express.NextFunction) => {
    const id = req.params.id;
    const query = {
      text: "delete from customers where id = $1",
      values: [id],
    };

    db.query(query, (err) => {
      if (err) next(err);
      else res.status(204).end();
    });
  }
);

// Update information on customer by id
app.put(
  "/api/customers/:id",
  (req: express.Request, res: express.Response, next: express.NextFunction) => {
    const id = req.params.id;
    const data = req.body;
    const query = {
      text: "update customers set firstname=$1, lastname=$2, email=$3, phone=$4 where id=$5",
      values: [data.firstname, data.lastname, data.email, data.phone, id],
    };

    db.query(query, (err, result) => {
      if (err) next(err);
      else res.json(result);
    });
  }
);

export default app;
