import React from 'react';
import Joi from '@hapi/joi';

// Import Data
import { getGenres } from '../../services/fakeGenreService.js';

// Import Components
import Form from './form';

export default class newMovie extends Form {
  state = {
    data: {
      title: '',
      genreId: '',
      numberInStock: '',
      dailyRentalRate: '',
    },
    genres: [],
    errors: {},
  };

  schema = {
    title: Joi.string().required().label('Title'),
    numberInStock: Joi.number().max(10).required().label('Stock'),
    dailyRentalRate: Joi.number().max(5).required().label('Rate'),
  };

  doSubmit = () => {
    this.handleSubmit();
    // Call Backend
    console.log('Submitted');
  };

  componentDidMount(){
  }

  render() {
    const { genres } = this.state;

    return (
      <div className="container mt-4">
        <form onSubmit={this.handleSubmit}>
          {this.renderInput('title', 'Title')}
          {this.renderOptions('genre', 'Genre', genres)}
          {this.renderInput('numberInStock', 'Stock', 'number')}
          {this.renderInput('dailyRentalRate', 'Rate', 'number')}
          {this.renderButton('Add movie')}
        </form>
      </div>
    );
  }
}
