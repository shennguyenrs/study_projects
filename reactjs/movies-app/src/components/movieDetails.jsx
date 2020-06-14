import React from "react";

const movieDetails = ({ match }) => {
  return (
    <>
      <h1>Movie ID is {match.params.id}</h1>
      <button className="btn btn-primary btn-sm" type="submit">
        Save
      </button>
    </>
  );
};

export default movieDetails;
