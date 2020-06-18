import React from 'react';
import Joi from '@hapi/joi';

// Import Data
import { getGenres } from '../../services/fakeGenreService';
import { getMovie } from '../../services/fakeMovieService';

// Import Components
import Form from './form';

export default class movieDetails extends Form {
  state = {
    data: {
      title: '',
      genre: '',
      numberInStock: '',
      dailyRentalRate: '',
      publishDate: '',
    },
    genres: getGenres(),
    errors: {},
  };

  schema = {
    title: Joi.string().required().label('Title'),
    numberInStock: Joi.number().max(10).required().label('Stock'),
    dailyRentalRate: Joi.number().max(5).required().label('Rate'),
    publishDate: Joi.date().required().label('Date'),
  };

  doSubmit = () => {
    this.handleSubmit();
    // Call Backend
    console.log('Submitted');
  };

  render() {
    const { genres } = this.state;
    const { match } = this.props;
    console.log(match.params.id);

    return (
      <div className="container mt-4">
        <form onSubmit={this.doSubmit}>
          {this.renderInput('title', 'Title')}
          {this.renderOptions('genre', 'Genre', genres)}
          {this.renderInput('numberInStock', 'Stock', 'number')}
          {this.renderInput('dailyRentalRate', 'Rate', 'number')}
          {this.renderInput('publishDate', 'Publish Date', 'date')}
          {this.renderButton('Save movie')}
        </form>
      </div>
    );
  }
}
