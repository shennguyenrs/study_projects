import express from 'express';
import cors from 'cors';
import mongoose from 'mongoose';
import dotenv from 'dotenv';

const app: express.Application = express();

// Environment variables
dotenv.config();
const MONGO_URI = process.env.MONGO_URI;

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

// Interface
interface Car {
  brand: string;
  model: string;
  color: string;
  year: number;
}

// Database schema
const carSchema = new mongoose.Schema<Car>({
  brand: { type: String, required: true },
  model: { type: String, required: true },
  color: { type: String, required: true },
  year: { type: Number, required: true },
});

// Database model
const cardb = mongoose.model('cardb', carSchema);

// CRUD Functions
// Get
app.get(
  '/cars',
  (
    _req: express.Request,
    res: express.Response,
    next: express.NextFunction
  ) => {
    cardb
      .find({})
      .then((result: string) => {
        res.status(200).json(result);
      })
      .catch((err: Error) => {
        res.status(500);
        next(err);
      });
  }
);

app.get(
  '/cars/:id',
  (req: express.Request, res: express.Response, next: express.NextFunction) => {
    cardb
      .find(req.body)
      .then((result: string) => {
        res.status(200).json(result);
      })
      .catch((err: Error) => {
        res.status(500);
        next(err);
      });
  }
);

// Post
app.post(
  '/cars',
  (req: express.Request, res: express.Response, next: express.NextFunction) => {
    const newCar = req.body;
    const postCar = new cardb(newCar);

    postCar
      .save()
      .then(() => res.status(201).send('Post new car successfully'))
      .catch((err: Error) => {
        res.status(500);
        next(err);
      });
  }
);

// Update
app.put(
  '/cars/:id',
  (req: express.Request, res: express.Response, next: express.NextFunction) => {
    const filterId = req.params.id;
    const updateInfo = req.body;

    cardb
      .findOneAndUpdate({ _id: filterId }, updateInfo, { new: true })
      .then((result: string) => {
        res.status(200).json(result);
      })
      .catch((err: Error) => {
        res.status(500);
        next(err);
      });
  }
);

// Delete
app.delete(
  '/cars',
  (req: express.Request, res: express.Response, next: express.NextFunction) => {
    const requestDelete = req.body;
    const message =
      'Delete car with ' + JSON.stringify(requestDelete) + ' successfully';

    cardb
      .deleteOne(requestDelete)
      .then(() => res.status(200).send(message))
      .catch((err: Error) => {
        res.status(500);
        next(err);
      });
  }
);

export default app;
