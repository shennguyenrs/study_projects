import React, { Component } from "react";
import { getMovies } from "../services/fakeMovieService";
import Like from "./common/like";

export default class Movies extends Component {
  state = {
    movies: getMovies(),
  };

  render() {
    if (this.state.movies.length === 0)
      return <p>There are no movies in the database.</p>;
    return (
      <>
        <p className="text-center m-4">
          Showing {this.state.movies.length} movies in the database.
        </p>
        <table className="table container">
          <thead>
            <tr>
              <th>Title</th>
              <th>Genre</th>
              <th>Stock</th>
              <th>Rate</th>
            </tr>
          </thead>
          <tbody>
            {this.state.movies.map((movie) => (
              <tr key={movie._id}>
                <td className="align-middle">{movie.title}</td>
                <td className="align-middle">{movie.genre.name}</td>
                <td className="align-middle">{movie.numberInStock}</td>
                <td className="align-middle">{movie.dailyRentalRate}</td>
                <td className="align-middle">
                  <Like
                    liked={movie.liked}
                    onClick={() => this.handleLiked(movie)}
                  />
                </td>
                <td>
                  <button
                    type="submit"
                    className="btn btn-danger"
                    onClick={() => this.deleteItem(movie)}
                  >
                    <i className="fas fa-trash pr-2"></i>
                    Delete
                  </button>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </>
    );
  }

  deleteItem = (movie) => {
    let movies = this.state.movies.filter((m) => m._id !== movie._id);
    this.setState({ movies });
  };

  handleLiked = (movie) => {
    let movies = [...this.state.movies];
    let index = movies.indexOf(movie);
    movies[index] = { ...movies[index] };
    movies[index].liked = !movies[index].liked;
    this.setState({ movies });
  };
}
