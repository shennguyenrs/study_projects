import React, { Component } from "react";
import PropTypes from "prop-types";
import Counter from "./counter";

export default class Counters extends Component {
  render() {
    const {
      onReset,
      counters,
      onDelete,
      onIncrement,
      onDecrement,
    } = this.props;
    return (
      <>
        <button className="btn btn-primary m-2" onClick={() => onReset()}>
          Reset
        </button>
        {counters.map((counter) => (
          <Counter
            key={counter.id}
            counters={counter}
            onDelete={() => onDelete(counter.id)}
            onIncrement={() => onIncrement(counter)}
            onDecrement={() => onDecrement(counter)}
          />
        ))}
      </>
    );
  }
}

Counters.propTypes = {
  onReset: PropTypes.func,
  onDelete: PropTypes.func,
  onIncrement: PropTypes.func,
  onDecrement: PropTypes.func,
  counters: PropTypes.number,
};
