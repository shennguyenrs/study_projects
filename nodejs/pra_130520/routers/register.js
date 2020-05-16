// Import modules
const router = require("express").Router();
const addUser = require("../models/user");
const bcrypt = require("bcrypt");
const { registerValidation } = require("../validations");

const salt = 10;

// Get
router.get("/", (req, res) => {
  res.render("register");
});

// Post
router.post("/", async (req, res) => {
  try {
    // Validate information before send information
    registerValidation(req.body);

    // Hash the login password
    const hashPassword = bcrypt.hash(req.body.password, salt);

    // Define user after validations
    const user = new addUser({
      username: req.body.username,
      email: req.body.email,
      password: hashPassword,
    });
    // Add user to database
    user.save();
    res.redirect("/index");
  } catch (err) {
    res.status(400).send();
    console.log(err);
  }
});

// Export
module.exports = router;
