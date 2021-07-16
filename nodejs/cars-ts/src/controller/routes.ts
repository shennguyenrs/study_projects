import { NextFunction, Response, Request } from 'express';

import carModel from '../models/carModel';

// Get all cars
export function getAllCars(_req: Request, res: Response, next: NextFunction) {
  carModel
    .find({})
    .then((result: []) => {
      res.status(200).json(result);
    })
    .catch((err: Error) => {
      res.status(500);
      next(err);
    });
}

// Get cars by id
export function getCarById(req: Request, res: Response, next: NextFunction) {
  carModel
    .find({ _id: req.params.id })
    .then((result: []) => {
      res.status(200).json(result);
    })
    .catch((err: Error) => {
      res.status(500);
      next(err);
    });
}

// Add a new car
export function addNewCar(req: Request, res: Response, next: NextFunction) {
  const newCar = req.body;
  const postCar = new carModel(newCar);

  postCar
    .save()
    .then(() => res.status(201).send('Post new car successfully'))
    .catch((err: Error) => {
      res.status(500);
      next(err);
    });
}

// Update car information by id
export function updateCarById(req: Request, res: Response, next: NextFunction) {
  const filterId = req.params.id;
  const updateInfo = req.body;

  carModel
    .findOneAndUpdate({ _id: filterId }, updateInfo, { new: true })
    .then((result: []) => {
      res.status(200).json(result);
    })
    .catch((err: Error) => {
      res.status(500);
      next(err);
    });
}

// Delete car by id
export function deleteCarById(req: Request, res: Response, next: NextFunction) {
  carModel
    .deleteOne({ _id: req.params.id })
    .then(() => res.status(200).send('Deleta car successfully'))
    .catch((err: Error) => {
      res.status(500);
      next(err);
    });
}
