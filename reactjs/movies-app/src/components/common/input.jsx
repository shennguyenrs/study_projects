import React from 'react';
import PropTypes from 'prop-types';

const input = ({ name, label, error, ...rest }) => {
  return (
    <div className="form-group">
      <label htmlFor={name}>{label}</label>
      <input
        {...rest}
        type={name}
        name={name}
        id={name}
        className="form-control"
      />
      {error && <div className="alert alert-danger">{error}</div>}
    </div>
  );
};

input.propTypes = {
  name: PropTypes.string,
  label: PropTypes.string,
  error: PropTypes.object,
};

export default input;
