import React from 'react';
import Joi from '@hapi/joi';

// Import Data
import { getGenres } from '../../services/fakeGenreService';
import { getMovie, saveMovie } from '../../services/fakeMovieService';

// Import Components
import Form from './form';

export default class formMovie extends Form {
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
    _id: Joi.string(),
    title: Joi.string().required().label('Title'),
    numberInStock: Joi.number().max(100).required().label('Number in Stock'),
    dailyRentalRate: Joi.number().max(5).required().label('Daily Rental Rate'),
  };

  doSubmit = () => {
    this.handleSubmit();
    saveMovie(this.state.data);
    this.props.history.push('/movies');
    // Call Backend
    console.log('Submitted');
  };

  mapToMovie = (movie) => {
    return {
      _id: movie._id,
      title: movie.title,
      genreId: movie.genre._id,
      numberInStock: movie.numberInStock,
      dailyRentalRate: movie.dailyRentalRate,
    };
  };

  componentDidMount() {
    let genres = getGenres();
    this.setState({ genres });

    let movieId = this.props.match.params.id;
    if (movieId === 'new') return;

    let movie = getMovie(movieId);
    if (!movie) return this.props.history.replace('/not-found');

    this.setState({ data: this.mapToMovie(movie) });
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
          {this.renderButton('Save movie')}
        </form>
      </div>
    );
  }
}
