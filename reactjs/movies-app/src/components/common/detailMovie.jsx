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
    },
    genres: getGenres(),
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

  fetchData = () => {
    let data = {};
    let { match } = this.props;
    data = getMovie(match.params.id);
    this.setState({ data });
  };

  componentDidMount() {
    this.fetchData();
  }

  render() {
    const { data, genres } = this.state;

    return (
      <div className="container mt-4">
        <form onSubmit={this.doSubmit}>
          {this.renderInput('title', 'Title')}
          {this.renderOptions('genre', 'Genre', genres, data.genre.name)}
          {this.renderInput('numberInStock', 'Stock', 'number')}
          {this.renderInput('dailyRentalRate', 'Rate', 'number')}
          {this.renderButton('Save movie')}
        </form>
      </div>
    );
  }
}
