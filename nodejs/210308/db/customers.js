const db = require('./dbconfig');

// Get all customers
const getAllCustomer = (_req, res) => {
  db.query('select * from customers', (err, result) => {
    if (err) {
      console.error(err);
    } else {
      res.json(result.rows);
    }
  });
};

// Get customers by id
const getCustomerById = (req, res) => {
  const query = {
    text: 'select * from customers where id = $1',
    values: [req.params.id],
  };

  db.query(query, (err, result) => {
    if (err) {
      console.error(err);
    } else {
      if (result.rows.length > 0) {
        res.json(result.rows);
      } else {
        res.status(404).end();
      }
    }
  });
};

// Add new customer
const addCustomer = (req, res) => {
  const newCustomer = req.body;
  const query = {
    text:
      'insert into customers (id, firstname, lastname, email, phone) values ($1, $2, $3, $4, $5)',
    values: [
      newCustomer.id,
      newCustomer.firstname,
      newCustomer.lastname,
      newCustomer.email,
      newCustomer.phone,
    ],
  };

  db.query(query, (err) => {
    if (err) {
      console.error(err);
    } else {
      res.json(newCustomer);
    }
  });
};

// Delete customer
const deleteCustomer = (req, res) => {
  const query = {
    text: 'delete from customers where id = $1',
    values: [req.params.id],
  };

  db.query(query, (err) => {
    if (err) {
      console.error(err);
    } else {
      res.status(204).end();
    }
  });
};

// Update customer information
const updateCustomer = (req, res) => {
  const updatedCustomer = req.body;
  const query = {
    text:
      'update customers set firstname=$1, lastname=$2, email=$3, phone=$4 where id = $5',
    values: [
      updatedCustomer.firstname,
      updatedCustomer.lastname,
      updatedCustomer.email,
      updatedCustomer.phone,
      req.params.id,
    ],
  };

  db.query(query, (err) => {
    if (err) {
      console.error(err);
    } else {
      res.json(updatedCustomer);
    }
  });
};

module.exports = {
  getAllCustomer: getAllCustomer,
  getCustomerById: getCustomerById,
  addCustomer: addCustomer,
  deleteCustomer: deleteCustomer,
  updateCustomer: updateCustomer,
};
