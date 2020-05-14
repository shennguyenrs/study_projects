// Require modules
const express = require("express");
const app = express();
const bodyParser = require("body-parser");
//const bcrypt = require("bcrypt");
require("dotenv/config");
const mongoose = require("mongoose");

const port = 3000;
//const saltround = 10;

// Settings
app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Connect to Database
mongoose.connect(
  process.env.DB_CONNECTION,
  { useNewUrlParser: true, useUnifiedTopology: true },
  () => {
    console.log("Connected to Database");
  }
);

// Import Routes
const loginRoute = require("./routers/login");
const registerRoute = require("./routers/register");

// Middle Wares
app.use("/login", loginRoute);
app.use("/register", registerRoute);

// Application listen
app.listen(port, () => {
  console.log("Server is listening on port " + port);
});
