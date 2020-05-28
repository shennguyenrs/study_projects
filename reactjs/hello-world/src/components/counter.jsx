import React, { Component } from "react";

export default class counter extends Component {
  state = {
    value: this.props.value,
  };

  render() {
    return (
      <div>
        <span style={{ fontSize: 20 }} className={this.badgeClasses()}>
          {this.formatCount()}
        </span>
        <button
          onClick={() => this.handleIncrement()}
          className="btn btn-secondary btn-sm"
        >
          Increments
        </button>
      </div>
    );
  }

  formatCount() {
    let { value } = this.state;
    return value === 0 ? "Zero" : value;
  }

  badgeClasses() {
    let classes = "badge m-2 badge-";
    classes += this.state.value === 0 ? "warning" : "primary";
    return classes;
  }

  handleIncrement = () => {
    this.setState({ value: this.state.value + 1 });
  };
}
