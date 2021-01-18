import React, { Component } from "react";
import PropTypes from "prop-types";

export default class counter extends Component {
  render() {
    const {
      onReset,
      counters,
      onDelete,
      onIncrement,
      onDecrement,
    } = this.props;
    return (
      <div className="row">
        <div className="col-3">
          <span style={{ fontSize: 20 }} className={this.badgeClasses()}>
            {this.formatCount()}
          </span>
        </div>
        <div className="col-1">
          <button
            onClick={() => onIncrement(counters)}
            className="btn btn-dark btn-sm mt-2"
          >
            <i className="fas fa-plus fa-sm"></i>
          </button>
        </div>
        <div className="col-1">
          <button
            onClick={() => onDecrement(counters)}
            className={this.minusClass()}
            disabled={counters.value === 0 ? "disabled" : ""}
          >
            <i className="fas fa-minus fa-sm"></i>
          </button>
        </div>
        <div className="col-1">
          <button
            onClick={() => onDelete(counters.id)}
            className="btn btn-danger btn-sm mt-2"
          >
            <i className="fas fa-trash fa-sm"></i>
          </button>
        </div>
      </div>
    );
  }

  formatCount() {
    let { value } = this.props.counters;
    return value === 0 ? "Zero" : value;
  }

  badgeClasses() {
    let classes = "badge m-2 badge-";
    classes += this.props.counters.value === 0 ? "warning" : "primary";
    return classes;
  }

  minusClass() {
    let classes = "btn btn-sm mt-2 btn-";
    classes += this.props.counters.value === 0 ? "secondary" : "dark";
    return classes;
  }
}

counter.propTypes = {
  onReset: PropTypes.func,
  counters: PropTypes.func,
  onDelete: PropTypes.func,
  onIncrement: PropTypes.func,
  onDecrement: PropTypes.func,
};
