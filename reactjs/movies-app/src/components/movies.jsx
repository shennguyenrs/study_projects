import React, { Component } from "react";
import { getMovies } from "../services/fakeMovieService";
import { getGenres } from "../services/fakeGenreService";
import Like from "./common/like";
import Pagination from "./common/pagination";
import ListGenres from "./common/listgenres";
import { paginate } from "../utils/paginate";

export default class Movies extends Component {
  state = {
    movies: getMovies(),
    genres: getGenres(),
    pageSize: 4,
    currentPage: 1,
  };

  render() {
    let { length: count } = this.state.movies;
    let { pageSize, currentPage, movies: allMovies, genres } = this.state;
    console.log(allMovies);

    if (count === 0) return <p>There are no movies in the database.</p>;
    let movies = paginate(allMovies, currentPage, pageSize);
    console.log(movies);
    return (
      <>
        <div className="row">
          <div className="col-2">
            <ListGenres genres={genres} />
          </div>
          <div className="col">
            <p className="text-center m-4">
              Showing {count} movies in the database.
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
                {movies.map((movie) => (
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
            <Pagination
              itemsCount={count}
              currentPage={currentPage}
              pageSize={pageSize}
              onChangePage={this.changePage}
            />
          </div>
        </div>
      </>
    );
  }

  changePage = (page) => {
    this.setState({ currentPage: page });
  };

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
