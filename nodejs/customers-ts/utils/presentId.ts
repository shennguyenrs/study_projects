import db from "./dbConnection";

const presentId = async (): Promise<number> => {
  const query = "select max(id) from customers";
  const result = await db.query(query);

  return result.rows[0].max;
};

export default presentId;
