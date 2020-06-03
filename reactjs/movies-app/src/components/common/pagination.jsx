import React from "react";
import _ from "lodash";

const pagination = (props) => {
  let { itemsCount, pageSize, currentPage, onChangePage } = props;
  let pagesCount = Math.ceil(itemsCount / pageSize);

  if (pagesCount === 1) return null;
  let pages = _.range(1, pagesCount + 1);

  return (
    <nav>
      <ul className="pagination justify-content-center">
        {pages.map((page) => (
          <li
            key={page}
            className={page === currentPage ? "page-item active" : "page-item"}
          >
            <a className="page-link" onClick={() => onChangePage(page)}>
              {page}
            </a>
          </li>
        ))}
      </ul>
    </nav>
  );
};

export default pagination;
