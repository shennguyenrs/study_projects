import React from "react";

const navbar = ({ info }) => {
  return (
    <>
      <nav className="navbar navbar-light bg-light">
        Navigation Bar <span className="badge badge-info">{info}</span>
      </nav>
    </>
  );
};

export default navbar;
