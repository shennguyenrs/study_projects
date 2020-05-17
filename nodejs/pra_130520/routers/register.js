// Import modules
const router = require("express").Router();
const userDB = require("../models/user");
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
    await registerValidation(req.body, (err, value) => {
      if (err) return console.log("Register validation error " + err);
      console.log(value);
    });

    // Check exist email
    await userDB.findOne({ email: req.body.email }, (err, result) => {
      if (err) return console.log("Check existence error" + err);
      console.log(result);
    });

    // Hash the login password
    const hashPassword = await bcrypt.hash(
      req.body.password,
      salt,
      (err, result) => {
        if (err) return console.log("Hashing error " + err);
        console.log(result);
      }
    );

    // Define user after validations
    const user = await new userDB({
      username: req.body.username,
      email: req.body.email,
      password: hashPassword,
    });

    // Add user to database
    await user.save((err, result) => {
      if (err) return console.log("Save inform error " + err);
      console.log(result);
      res.redirect("/index");
    });
  } catch (err) {
    res.status(400).send();
    console.log(err);
  }
});

// Export
module.exports = router;
