// Import modules
const router = require("express").Router();

// Routes
router.get("/", (req, res) => {
  res.render("../views/index.ejs");
});

// Export
module.exports = router;
