import React from "react";

let ListGenres = (props) => {
  let { genres } = props;
  let classes = "list-group-item list-group-item-action";
  return (
    <div className="list-group">
      {genres.map((genre) => {
        <a key={genre} href="/#" className={classes}></a>;
      })}
    </div>
  );
};

export default ListGenres;
