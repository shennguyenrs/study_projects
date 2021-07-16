import express from 'express';
import cors from 'cors';
import mongoose from 'mongoose';

import { MONGO_URI } from './utils/config';
import * as route from './controller/routes';

const app: express.Application = express();

// Middleware
app.use(cors());
app.use(express.json());

// Database connections
mongoose
  .connect(MONGO_URI as string, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    useFindAndModify: true,
    useCreateIndex: true,
  })
  .then(() => {
    console.log('MongoDB connects successfully');
  })
  .catch((err: Error) => {
    console.error('MongoDB fails to connect: ', err.message);
    process.exit(1);
  });

// CRUD Functions
app.get('/api/cars', route.getAllCars);
app.get('/api/cars/:id', route.getCarById);
app.post('/api/cars', route.addNewCar);
app.delete('/api/cars/:id', route.deleteCarById);
app.put('/api/cars/:id', route.updateCarById);

export default app;
