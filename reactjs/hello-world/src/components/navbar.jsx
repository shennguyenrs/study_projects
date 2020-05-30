import React from "react";

const navbar = ({ info }) => {
  return (
    <>
      <nav className="navbar navbar-light bg-light">
        <div className="row">
          <div className="col-9">Navigation Bar</div>
          <div className="col-1">
            <span className="badge badge-info">{info}</span>
          </div>
        </div>
      </nav>
    </>
  );
};

export default navbar;
