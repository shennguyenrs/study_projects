const express = require('express');
const app = express();
const port = process.env.PORT;

const bodyParser = require('body-parser');
app.use(bodyParser.json());

let customers = [
  {id: '1588323375416', firstName: 'John', lastName: 'Johnson', email: 'john@johnson.com', phone: '8233243'},
  {id: '1588323375417', firstName: 'Mary', lastName: 'Smith', email: 'mary@smith.com', phone: '6654113'},
  {id: '1588323375418', firstName: 'Peter', lastName: 'North', email: 'peter@north.com', phone: '901176'},
]

app.get("/api/customers", (req, res) => {
    res.json(customers);
})

app.get("/api/customers/:id", (req, res) => {
    const id = req.params.id;
    customer = customers.filter(cus => cus.id === id);
    res.json(customer);
})

app.post("/api/customers", (req, res) => {
    const newCus = {'id': Date.now(), ...req.body};
    customers = [...customers, newCus];
    res.json(newCus);
})

app.delete("/api/customers/:id", (req, res) => {
    const id = req.params.id;
    customers = customers.filter(cus => cus.id !== id);
    res.status(204).end()
})

app.put("/api/customers/:id", (req, res) => { 
  const id = req.params.id;
  const updatedCus = {'id': id, ...req.body};
  const index = customers.findIndex(cus => cus.id === id);
  customers.splice(index, 1, updatedCus); 
  res.json(updatedCus);
})

app.listen(port, () => {
    console.log("App is listening on port "+port);
})