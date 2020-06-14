import React from "react";

const input = ({ name, handleChange, label, value, error }) => {
  return (
    <div className="form-group">
      <label htmlFor={name}>{label}</label>
      <input
        onChange={handleChange}
        name={name}
        value={value}
        type={name}
        className="form-control"
        id={name}
      />
      {error && <div className="alert alert-danger">{error}</div>}
    </div>
  );
};

export default input;
