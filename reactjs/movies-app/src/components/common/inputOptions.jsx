import React from 'react';
import PropTypes from 'prop-types';

const inputOptions = ({
  name,
  label,
  objects,
  textProperty,
  valueProperty,
}) => {
  return (
    <div className="form-group">
      <label htmlFor={name}>{label}</label>
      <select name={name} id={name} className="form-control">
        {objects.map((object) => (
          <option key={object[valueProperty]}>{object[textProperty]}</option>
        ))}
      </select>
    </div>
  );
};

inputOptions.propTypes = {
  name: PropTypes.string,
  label: PropTypes.string,
  objects: PropTypes.object,
  textProperty: PropTypes.string,
  valueProperty: PropTypes.string
};

inputOptions.defaultProp = {
  textProperty: 'name',
  valueProperty: '_id',
};

export default inputOptions;
