require('dotenv').config();
const express = require('express');
const morgan = require('morgan');
const cors = require('cors');
const app = express();
const PORT = process.env.PORT;
const Info = require('./models/info');

morgan.token('content', (req, res) => {
  return JSON.stringify(req.body);
});

const unknownEndPoint = (req, res) => {
  res.status(404).json({ error: 'Unknown Endpoint' });
};

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
//let { persons } = require('./db.json');

// Home
app.get('/', (req, res) => {
  res.status(200).send('<h1>Welcome to phonebook app backend</h1>');
});

// View info of json file
app.get('/api/info', async (req, res) => {
  const count = await Info.estimatedDocumentCount()
    .then((result) => result)
    .catch((err) => {
      res.status(400).json({
        error: err.message,
      });
    });

  const timeStamp = new Date(Date.now());

  res
    .status(200)
    .send(
      `<h3>Phonebook has info of ${count} people</h3><h3>${timeStamp}</h3>`
    );
});

// View the whole database
app.get('/api/persons', (req, res) => {
  Info.find({})
    .then((data) => res.status(200).json(data))
    .catch((err) => res.status(400).json({ error: err.message }));
});

// Add new person
app.post('/api/persons', async (req, res) => {
  const person = req.body;

  // Check missing name or number
  if (!person.name || !person.phone) {
    return res.status(400).json({
      error: 'Name or Phone missing.',
    });
  }

  // Check duplicate name
  const duplicateName = await Info.find({ name: person.name })
    .then((info) => (info.length === 0 ? false : true))
    .catch((err) => res.status(400).json({ error: err.message }));

  if (duplicateName) {
    return res.status(400).json({
      error: 'Duplicate name. Name must be unique.',
    });
  }

  const newInfo = new Info({
    name: person.name,
    phone: person.phone,
  });

  newInfo
    .save()
    .then((savedInfo) => {
      res.status(201).json(savedInfo);
    })
    .catch((err) => {
      res.status(400).json({ error: err.message });
    });
});

// View info by using id
app.get('/api/persons/:id', (req, res) => {
  Info.findById(req.params.id)
    .then((info) => res.status(200).json(info))
    .catch((err) => {
      res.status(404).json({ error: err.message });
    });
});

// Delete info by using id
app.delete('/api/persons/:id', (req, res) => {
  Info.deleteOne({ _id: req.params.id })
    .then(() => {
      res.status(204).end();
    })
    .catch((err) => res.status(400).json({ error: err.message }));
});

// Unknown endpoint
app.use(unknownEndPoint);

// Logging
app.listen(PORT, () => {
  console.log(`Server is listening on ${PORT}`);
});
