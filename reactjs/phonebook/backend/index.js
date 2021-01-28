const express = require('express');
const morgan = require('morgan');
const cors = require('cors');
const app = express();
const PORT = process.env.PORT || 3001;

morgan.token('content', (req, res) => {
  return JSON.stringify(req.body);
});

// Middleware
app.use(express.json());
app.use(
  morgan(
    ':method :url :status :res[content-length] - :response-time ms :content'
  )
);
app.use(cors());
app.use(express.static('build'));

// Import json file
let { persons } = require('./db.json');

// Home
app.get('/', (req, res) => {
  res.send('<h1>Welcome to phonebook app</h1>');
});

// View info of json file
app.get('/api/info', (req, res) => {
  const count = Object.keys(persons).length;
  const timeStamp = new Date(Date.now());

  res.send(
    `<h3>Phonebook has info of ${count} people</h3><h3>${timeStamp}</h3>`
  );
});

// View the whole json file
app.get('/api/persons', (req, res) => {
  res.json(persons);
});

// Add new person
app.post('/api/persons', (req, res) => {
  const person = req.body;
  const maxId =
    Object.keys(persons).length > 0 ? Math.max(...persons.map((p) => p.id)) : 0;

  // Check missing name or number
  if (!person.name || !person.phone) {
    return res.status(400).json({
      error: 'Name or Phone missing.',
    });
  }

  // Check duplicate name
  const duplicateName = persons.find((p) => p.name === person.name);

  if (duplicateName) {
    return res.status(400).json({
      error: 'Duplicate name. Name must be unique.',
    });
  }

  person.id = maxId + 1;

  // Join new person to json file
  persons = persons.concat(person);

  res.json(person);
});

// View info by using id
app.get('/api/persons/:id', (req, res) => {
  const id = Number(req.params.id);
  const person = persons.find((person) => person.id === id);

  if (person) {
    res.json(person);
  } else {
    res.status(404).end();
  }
});

// Delete info by using id
app.delete('/api/persons/:id', (req, res) => {
  const id = Number(req.params.id);
  persons = persons.filter((person) => person.id !== id);

  res.status(204).end();
});

// Logging
app.listen(PORT, () => {
  console.log(`Server is listening on ${PORT}`);
});
