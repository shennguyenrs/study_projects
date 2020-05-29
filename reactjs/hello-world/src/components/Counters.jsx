import React, { Component } from "react";
import Counter from "./counter";

export default class Counters extends Component {
  render() {
    const { onReset, counters, onDelete, onIncrement } = this.props;
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
          />
        ))}
      </>
    );
  }
}
