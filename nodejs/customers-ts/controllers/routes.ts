import { Request, Response, NextFunction } from "express";

import db from "../utils/dbConnection";

// Get all customers
export const getAllCustomers = (
  _req: Request,
  res: Response,
  next: NextFunction
): void => {
  const query = "select * from customers";

  db.query(query, (err, result) => {
    if (err) next(err);
    else {
      if (result.rows.length > 0) res.status(200).json(result.rows);
      else res.status(404).end();
    }
  });
};

// Get customer by id
export const getCustomerById = (
  req: Request,
  res: Response,
  next: NextFunction
): void => {
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
};

// Post new customer
export const addCustomer = (
  req: Request,
  res: Response,
  next: NextFunction
): void => {
  const data = req.body;
  const query = {
    text: "insert into customers (id, firstname, lastname, email, phone) values ($1, $2, $3, $4, $5)",
    values: [data.id, data.firstname, data.lastname, data.email, data.phone],
  };

  db.query(query, (err) => {
    if (err) next(err);
    else res.status(200).json(data);
  });
};

// Delete a customer by id
export const deleteCustomerById = (
  req: Request,
  res: Response,
  next: NextFunction
): void => {
  const id = req.params.id;
  const query = {
    text: "delete from customers where id = $1",
    values: [id],
  };

  db.query(query, (err) => {
    if (err) next(err);
    else res.status(204).end();
  });
};

export const deleteAllCustomers = (
  _req: Request,
  res: Response,
  next: NextFunction
): void => {
  const query = {
    text: "delete from customers",
  };

  db.query(query, (err) => {
    if (err) next(err);
    else res.status(204).end();
  });
};

// Update information on customer by id
export const updateCustomerById = (
  req: Request,
  res: Response,
  next: NextFunction
): void => {
  const id = req.params.id;
  const data = req.body;
  const query = {
    text: "update customers set firstname=$1, lastname=$2, email=$3, phone=$4 where id=$5",
    values: [data.firstname, data.lastname, data.email, data.phone, id],
  };

  db.query(query, (err) => {
    if (err) next(err);
    else res.json(data);
  });
};
