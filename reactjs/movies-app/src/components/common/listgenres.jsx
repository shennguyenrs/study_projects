import React from "react";

const ListGenres = (props) => {
  let { items } = props;
  console.log(items);
  return (
    <ul className="list-group">
      {items.map((item) => (
        <li key={item._id} className="list-group-item">
          {item.name}
        </li>
      ))}
    </ul>
  );
};

export default ListGenres;
