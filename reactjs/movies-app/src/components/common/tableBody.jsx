import React, { Component } from "react";
import _ from "lodash";

export default class tableBody extends Component {
  renderCell = (movie, header) => {
    if (header.content) return header.content(movie);
    return _.get(movie, header.name);
  };

  render() {
    const { movies, headers } = this.props;
    return (
      <>
        {movies.map((movie) => (
          <tr key={movie._id}>
            {headers.map((header) => (
              <td
                key={movie._id + (header.name || header.key)}
                className="align-middle"
              >
                {this.renderCell(movie, header)}
              </td>
            ))}
          </tr>
        ))}
      </>
    );
  }
}
