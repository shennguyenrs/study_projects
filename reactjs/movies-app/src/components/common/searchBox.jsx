import React from 'react';
import PropTypes from 'prop-types';

const searchBox = ({ value, onChange }) => {
  return (
    <input
      className="form-control mb-4"
      type="text"
      name="query"
      placeholder="Search for ..."
      value={value}
      onChange={(e) => onChange(e.currentTarget.value)}
    />
  );
};

searchBox.propTypes = {
  value: PropTypes.string,
  onChange: PropTypes.func,
};

export default searchBox;
