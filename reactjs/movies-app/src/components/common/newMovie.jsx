import React from 'react';
import Joi from '@hapi/joi';

// Import Data
import { getGenres } from '../../services/fakeGenreService.js';

// Import Components
import Form from './form';

export default class newMovie extends Form {
  state = {
    movies: {
      title: '',
      genre: '',
      numberInStock: '',
      dailyRentalRate: '',
      publishDate: '',
    },
    genres: getGenres(),
  };

  schema = {
    title: Joi.string().required().label('Title'),
    numberInStock: Joi.number().max(10).required().label('Stock'),
    dailyRentalRate: Joi.number().max(5).required().label('Rate'),
    publishDate: Joi.date().required().label('Date'),
  };

  render() {
    const { genres } = this.state;

    return (
      <div className="container mt-4">
        {this.renderInput('title', 'Title')}
        {this.renderOptions('genre', 'Genre', { genres })}
        {this.renderInput('numberInStock', 'Stock', 'number')}
        {this.renderInput('dailyRentalRate', 'Rate', 'number')}
        {this.renderInput('publishDate', 'Publish Date', 'date')}
        {this.renderButton('Add movie')}
        {/*
         *<div className="form-group">
         *  <label htmlFor="title">Title</label>
         *  <input type="text" id="title" className="form-control" />
         *</div>
         *<div className="form-group">
         *  <label htmlFor="genre.name">Genre</label>
         *  <select className="form-control" name="genreOptions" id="genre.name">
         *    {this.state.genres.map((genre) => (
         *      <option key={genre._id}>{genre.name}</option>
         *    ))}
         *  </select>
         *</div>
         *<div className="form-group">
         *  <label htmlFor="numberInStock">Stock</label>
         *  <input type="number" id="numberInStock" className="form-control" />
         *</div>
         *<div className="form-group">
         *  <label htmlFor="dailyRentalRate">Rate</label>
         *  <input type="number" id="dailyRentalRate" className="form-control" />
         *</div>
         *<div className="form-group">
         *  <label htmlFor="publishDate">Publish Date</label>
         *  <input type="date" id="publishDate" className="form-control" />
         *</div>
         *<button className="btn btn-primary">Add</button>
         */}
      </div>
    );
  }
}
