import React from "react";
import Like from "./common/like";
import TableHeader from "./common/tableHeader";

const moviesTable = (props) => {
  let { itemsCount, movies, onLiked, onDelete} = props;
  return (
    <>
      <p className="text-center">
        Showing {itemsCount} movies in the database.
      </p>
      <table className="table container">
        <thead>
          <TableHeader />
        </thead>
        <tbody>
          {movies.map((movie) => (
            <tr key={movie._id}>
              <td className="align-middle">{movie.title}</td>
              <td className="align-middle">{movie.genre.name}</td>
              <td className="align-middle">{movie.numberInStock}</td>
              <td className="align-middle">{movie.dailyRentalRate}</td>
              <td className="align-middle">
                <Like liked={movie.liked} onClick={() => onLiked(movie)} />
              </td>
              <td>
                <button
                  type="submit"
                  className="btn btn-danger"
                  onClick={() => onDelete(movie)}
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
};

export default moviesTable;
