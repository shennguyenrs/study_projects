// Import modules
const router = require("express").Router();

// Routes
router.get("/", (req, res) => {
  res.render("login.ejs");
});

router.post("/", (req, res) => {
  var email = req.body.email;
  var password = req.body.password;
  console.log("New login: " + email + " " + password);
  res.end("homepage.ejs");
});

// Export
module.exports = router;
