import React, { Component } from "react";

export default class tableHeader extends Component {
  render() {
    let headers = ["Title", "Genre", "Stock", "Rate"];

    raiseSort = (head) => {
      let sortedColumn = { ...this.props.sortedColumn };
      if (sortedColumn.col === head) {
        sortedColumn.order = sortedColumn.order === "asc" ? "desc" : "asc";
      } else {
        sortedColumn.col = head;
        sortedColumn.order = "asc";
      }
      this.props.setState({ sortedColumn });
    };

    return (
      <tr>
        {headers.map((header) => (
          <th key={header} onClick={() => raiseSort(header)}>
            {header}
          </th>
        ))}
      </tr>
    );
  }
}
