// Import modules
const router = require("express").Router();
const bcrypt = require("bcrypt");
const userDb = require("../models/user");

// Routes
router.get("/", (req, res) => {
  res.render("login.ejs");
});

router.post("/", async (req, res) => {
  await userDb.findOne({ email: req.body.email }, (err, user) => {
    if (err) {
      throw err;
    }
    bcrypt.compare(req.body.password, user.password, (err, result) => {
      if (err) {
        throw err;
      }
      res.redirect("/index");
    });
  });
});

// Export
module.exports = router;
