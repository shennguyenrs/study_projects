// Import modules
const router = require("express").Router();

// Routes
router.get("/", (req, res) => {
  res.render("../views/index.ejs", { username: "Shen" });
});

// Export
module.exports = router;
