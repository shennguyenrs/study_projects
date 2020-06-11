import React, { Component } from "react";

export default class tableHeader extends Component {
  raiseSort = (head) => {
    let sortedColumn = { ...this.props.sortedColumn };
    if (sortedColumn.col === head) {
      sortedColumn.order = sortedColumn.order === "asc" ? "desc" : "asc";
    } else {
      sortedColumn.col = head;
      sortedColumn.order = "asc";
    }
    this.props.onSort(sortedColumn);
  };

  renderSortIcon = (header) => {
    let { sortedColumn } = this.props;
    if (header.name !== sortedColumn.col) return null;
    if (sortedColumn.order === "asc") return <i className="fas fa-sort-up"></i>;
    return <i className="fas fa-sort-down"></i>;
  };

  render() {
    const { headers } = this.props;

    return (
      <tr>
        {headers.map((header) => (
          <th
            className="clickable"
            key={header.name || header.key}
            onClick={() => this.raiseSort(header.name)}
          >
            {header.label} {this.renderSortIcon(header)}
          </th>
        ))}
      </tr>
    );
  }
}
