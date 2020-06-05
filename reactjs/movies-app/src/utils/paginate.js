import _ from "lodash";
export function paginate(items, pageNumber, pageSize) {
  let startIndex = (pageNumber - 1) * pageSize;
  return _(items).splice(startIndex).take(pageSize).value();
}
