import React from "react";
import { NavLink } from "react-router-dom";

const navBar = () => {
  return (
    <nav className="navbar navbar-light bg-light">
      <NavLink to="/" className="navbar-brand">
        Movies-App
      </NavLink>
      <div className="d-flex">
        <div className="nav-item p-2">
          <NavLink to="/movies">Movies</NavLink>
        </div>
        <div className="nav-item p-2">
          <NavLink to="/customers">Customers</NavLink>
        </div>
        <div className="nav-item p-2">
          <NavLink to="/rentals">Rentals</NavLink>
        </div>
        <div className="nav-item p-2">
          <NavLink to="/login">Login</NavLink>
        </div>
      </div>
    </nav>
  );
};

export default navBar;
