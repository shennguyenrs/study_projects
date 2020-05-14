// Import Modules
const mongoose = require("mongoose");

// Create database
const UserSchema = mongoose.Schema({
  date: Date.now,
  username: {
    type: String,
    require: true,
  },
  email: {
    type: String,
    require: true,
  },
  password: {
    type: String,
    require: true,
  },
});

// Export
module.exports = mongoose.model("User", UserSchema);
