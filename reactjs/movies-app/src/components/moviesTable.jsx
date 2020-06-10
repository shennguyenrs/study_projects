import React, { Component } from "react";
import TableHeader from "./common/tableHeader";
import TableBody from "./common/tableBody";
import Like from "./common/like";

export default class moviesTable extends Component {
  headers = [
    { name: "title", label: "Title" },
    { name: "genre.name", label: "Genre" },
    { name: "numberInStock", label: "Stock" },
    { name: "dailyRentalRate", label: "Rate" },
    {
      key: "like",
      content: (movie) => (
        <Like liked={movie.liked} onClick={() => this.props.onLiked(movie)} />
      ),
    },
    {
      key: "delete",
      content: (movie) => (
        <button
          type="submit"
          className="btn btn-danger"
          onClick={() => this.props.onDelete(movie)}
        >
          <i className="fas fa-trash pr-2"></i>
          Delete
        </button>
      ),
    },
  ];

  render() {
    const { itemsCount, movies, sortedColumn, onSort } = this.props;

    return (
      <>
        <p className="text-center">
          Showing {itemsCount} movies in the database.
        </p>
        <table className="table container">
          <thead>
            <TableHeader
              headers={this.headers}
              sortedColumn={sortedColumn}
              onSort={onSort}
            />
          </thead>
          <tbody>
            <TableBody movies={movies} headers={this.headers} />
          </tbody>
        </table>
      </>
    );
  }
}
