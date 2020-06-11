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

  sortedItems = (sortedColumn) => {
    this.setState({ sortedColumn });
  };

  getPagedData = () => {
    let {
      pageSize,
      currentPage,
      movies: allMovies,
      selectedGenre,
      sortedColumn,
    } = this.state;

    let filtered =
      selectedGenre && selectedGenre._id
        ? allMovies.filter((m) => m.genre._id === selectedGenre._id)
        : allMovies;

    let sortedMovies = sorted(filtered, sortedColumn.col, sortedColumn.order);
    let movies = paginate(sortedMovies, currentPage, pageSize);

    return { totalCount: filtered.length, movies };
  };

  render() {
    const { length: count } = this.state.movies;
    const {
      pageSize,
      currentPage,
      genres,
      sortedColumn,
    } = this.state;

    if (count === 0) return <p>There are no movies in the database.</p>;
    const { totalCount, movies } = this.getPagedData();

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
              itemsCount={totalCount}
              movies={movies}
              sortedColumn={sortedColumn}
              onLiked={this.likedItem}
              onDelete={this.deleteItem}
              onSort={this.sortedItems}
            />
            <Pagination
              itemsCount={totalCount}
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
