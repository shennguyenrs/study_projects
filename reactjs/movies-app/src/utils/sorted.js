import _ from "lodash";
export function sorted(items, col, order) {
  return _(items).orderBy([col], [order]).value();
}
