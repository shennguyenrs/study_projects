require("dotenv").config();
const express = require("express");
const app = express();
const PORT = process.env.PORT || 3001;

app.use("/", (_req, res) => {
  res.send("<h1>Hello World</h1>");
});

app.listen(PORT, () => {
  console.log("App listening on port " + PORT);
});
