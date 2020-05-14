// Import modules
const router = require("express").Router();
const addUser = require("../models/user");
const bcrypt = require("bcrypt");

const salt = bcrypt.genSalt();

// Routers
router.get("/", (req, res) => {
  res.render("register.ejs");
});

// Submit user registered information
router.post("/", async (req, res) => {
  try {
    const hashPassword = await bcrypt.hash(req.body.password, salt);
    addUser.save({
      username: req.body.username,
      email: req.body.email,
      password: hashPassword,
    });
    res.send("Register Succeed");
  } catch {
    res.send("Register Failed");
  }
});

// Export
module.exports = router;
