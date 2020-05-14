// Import modules
const express = require("express");
const router = express.Router();
const addUser = require("../models/user");
const bcrypt = require("bcrypt");

const saltround = 10;

// Routers
router.get("/", (req, res) => {
  res.render("register.ejs");
});

// Submit user registed information
router.post("/", async (req, res) => {
  bcrypt.hash(req.body.password, saltround, (err, hash) => {
    const user = new addUser({
      username: req.body.username,
      email: req.body.email,
      password: hash,
    });
      
    try {
        const userSaved = await user.save();
        res.redirect("../views/homepage.ejs");
    } catch(err) {
          res.send("Register is failed");
          console.log({message: err});
    }
})
});

// Export
module.exports = router;
