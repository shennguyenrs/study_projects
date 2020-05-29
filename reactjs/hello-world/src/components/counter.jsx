import React, { Component } from "react";

export default class counter extends Component {
  render() {
    const { onReset, counters, onDelete, onIncrement } = this.props;
    return (
      <div className="d-flex align-items-center">
        <span style={{ fontSize: 20 }} className={this.badgeClasses()}>
          {this.formatCount()}
        </span>
        <button
          onClick={() => onIncrement(counters)}
          className="btn btn-secondary btn-sm m-2"
        >
          Increments
        </button>
        <button
          onClick={() => onDelete(counters.id)}
          className="btn btn-danger btn-sm m-2"
        >
          Delete
        </button>
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
}
