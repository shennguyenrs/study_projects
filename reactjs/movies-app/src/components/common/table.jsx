import React from "react";
import TableHeader from "./tableHeader";
import TableBody from "./tableBody";

const table = ({ movies, headers, sortedColumn, onSort }) => {

  return (
    <table className="table container">
      <thead>
        <TableHeader
          headers={headers}
          sortedColumn={sortedColumn}
          onSort={onSort}
        />
      </thead>
      <tbody>
        <TableBody movies={movies} headers={headers} />
      </tbody>
    </table>
  );
};

export default table;
