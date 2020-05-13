const express = require("express");
const app = express();
const bodyParser = require("body-parser");
const bcrypt = require("bcrypt");

const port = 3000;
const saltround = 10;

app.set("view engine", "ejs");
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.get("/login", (req, res) => {
  res.render("login.ejs");
});

app.post("/", (req, res) => {
  var email = req.body.email;
  var password = req.body.password;
  console.log("New login: " + email + " " + password);
  res.end("homepage.ejs");
});

app.get("/register", (req, res) => {
  res.render("register.ejs");
});

app.post("/register", (req, res) => {
  var username = req.body.username;
  var email = req.body.email;
  var password = req.body.password;
  console.log("New register: " + username + " " + email + " " + password);
  res.end("Success Register");
});

app.listen(port, () => {
  console.log("Server is listening on port " + port);
});
