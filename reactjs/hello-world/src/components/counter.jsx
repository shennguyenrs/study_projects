import React, { Component } from "react";

export default class counter extends Component {
  state = {
    count: 0,
    tags: ["tag1", "tag2", "tag3"],
  };

  render() {
    return (
      <>
        <span style={{ fontSize: 20 }} className={this.badgeClasses()}>
          {this.formatCount()}
        </span>
        <button
          onClick={() => this.handleIncrement(product)}
          className="btn btn-secondary btn-sm"
        >
          Increments
        </button>
        <ul>{this.renderTags()}</ul>
      </>
    );
  }

  formatCount() {
    let { count } = this.state;
    return count === 0 ? "Zero" : count;
  }

  badgeClasses() {
    let classes = "badge m-2 badge-";
    classes += this.state.count === 0 ? "warning" : "primary";
    return classes;
  }

  renderTags() {
    if (this.state.tags.length === 0) return <p>There no tags!</p>;
    return this.state.tags.map((tag) => <li key={tag}>{tag}</li>);
  }

  handleIncrement = (product) => {
    this.setState({ count: this.state.count + 1 });
  };
}
