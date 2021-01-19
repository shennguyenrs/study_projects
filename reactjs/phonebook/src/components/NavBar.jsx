import React from 'react'
import PropTypes from 'prop-types';

const NavBar = ({ onReset }) => {
  return (
    <nav className="navbar navbar-light bg-light">
      <button
        className="btn btn-warning"
        onClick={() => {
          onReset();
        }}
      >
        Reset
      </button>
    </nav>
  );
}

export default NavBar

NavBar.propTypes = {
  onReset: PropTypes.func,
};
