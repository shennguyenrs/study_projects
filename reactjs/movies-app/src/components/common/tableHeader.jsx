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

  render() {
    const { headers } = this.props;

    return (
      <tr>
        {headers.map((header) => (
          <th
            key={header.name || header.key}
            onClick={() => this.raiseSort(header.name)}
          >
            {header.label}
          </th>
        ))}
      </tr>
    );
  }
}
