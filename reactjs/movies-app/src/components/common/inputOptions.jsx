import React, { Component } from 'react';
import PropTypes from 'prop-types';

export default class inputOptions extends Component {
  state = { value: '' };

  handleChange = (e) => {
    this.setState({ value: e.target.value });
  };

  componentDidUpdate() {}

  render() {
    const { name, label, objects, textProperty, valueProperty } = this.props;
    const { value } = this.state;

    return (
      <div className="form-group">
        <label htmlFor={name}>{label}</label>
        <select
          value={value}
          id={name}
          className="form-control"
          onChange={this.handleChange}
        >
          {objects.map((object) => (
            <option key={object[valueProperty]}>{object[textProperty]}</option>
          ))}
        </select>
      </div>
    );
  }
}

inputOptions.propTypes = {
  name: PropTypes.string,
  label: PropTypes.string,
  objects: PropTypes.array,
  selected: PropTypes.string,
  textProperty: PropTypes.string,
  valueProperty: PropTypes.string,
};

inputOptions.defaultProps = {
  textProperty: 'name',
  valueProperty: '_id',
};
