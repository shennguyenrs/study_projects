import React, { Component } from "react";
import { getMovies } from "../services/fakeMovieService";
import { getGenres } from "../services/fakeGenreService";
import Pagination from "./common/pagination";
import ListGenres from "./common/listGenres";
import MoviesTable from "./moviesTable";
import { paginate } from "../utils/paginate";
import { sorted } from "../utils/sorted";

export default class Movies extends Component {
  state = {
    movies: [],
    genres: [],
    pageSize: 4,
    currentPage: 1,
    sortedColumn: { col: "title", order: "asc" },
    selectedGenre: { _id: "", name: "All Movies" },
  };

  componentDidMount() {
    const genres = [{ _id: "", name: "All Movies" }, ...getGenres()];
    this.setState({ movies: getMovies(), genres });
  }

  genresSelect = (genre) => {
    this.setState({ selectedGenre: genre, currentPage: 1 });
  };

  changePage = (page) => {
    this.setState({ currentPage: page });
  };

  deleteItem = (movie) => {
    let movies = this.state.movies.filter((m) => m._id !== movie._id);
    this.setState({ movies });
  };

  likedItem = (movie) => {
    let movies = [...this.state.movies];
    let index = movies.indexOf(movie);
    movies[index] = { ...movies[index] };
    movies[index].liked = !movies[index].liked;
    this.setState({ movies });
  };

  render() {
    const { length: count } = this.state.movies;
    const {
      pageSize,
      currentPage,
      movies: allMovies,
      genres,
      selectedGenre,
      sortedColumn,
    } = this.state;
    const filtered =
      selectedGenre && selectedGenre._id
        ? allMovies.filter((m) => m.genre._id === selectedGenre._id)
        : allMovies;

    if (count === 0) return <p>There are no movies in the database.</p>;
    const sortedMovies = sorted(filtered, sortedColumn.col, sortedColumn.order);
    const movies = paginate(sortedMovies, currentPage, pageSize);
    return (
      <>
        <div className="row m-4">
          <div className="col-3">
            <ListGenres
              items={genres}
              selectedItem={this.state.selectedGenre}
              onItemSelect={this.genresSelect}
            />
          </div>
          <div className="col">
            <MoviesTable
              itemsCount={filtered.length}
              movies={movies}
              onLiked={this.likedItem}
              onDelete={this.deleteItem}
            />
            <Pagination
              itemsCount={filtered.length}
              currentPage={currentPage}
              pageSize={pageSize}
              onChangePage={this.changePage}
            />
          </div>
        </div>
      </>
    );
  }
}
