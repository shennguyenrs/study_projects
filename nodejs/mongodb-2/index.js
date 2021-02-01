require("dotenv").config();
const mongoose = require("mongoose");
const argvLength = process.argv.length;

// Exit when arguments are more than 5 or less than 3
if (argvLength !== 4 && argvLength !== 2) {
  console.log(
    "Please provide arguments as: nodejs index.js <password> <name> <phone>"
  );
  process.exit(1);
}

const uri = process.env.MONGODB_URI;

// Mongo DB connect
mongoose
  .connect(uri, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    useFindAndModify: true,
    useCreateIndex: true,
  })
  .then(() => console.log("Connected to database"))
  .catch((err) => {
    console.error("Error to connect Mongo Database -", err.message);
    process.exit(1);
  });

// Create Schema
const infoSchema = new mongoose.Schema({
  name: {
    type: String,
    required: [true, "Name is required"],
  },
  phone: {
    type: String,
    required: [true, "Phone number is required"],
    validate: {
      validator: (str) => {
        return /([0-9]{3})-([0-9]{3})-([0-9]{4})$/.test(str);
      },
      message: (prop) => `${prop.value} is not in valid format: xxx-xxx-xxxx!`,
    },
  },
});

// Create model
const Info = mongoose.model("Info", infoSchema);

// Save new if if user pass name and phone in arguments
if (argvLength === 4) {
  const newName = process.argv[3];
  const newPhone = process.argv[4];

  const info = new Info({
    name: newName,
    phone: newPhone,
  });

  info
    .save()
    .then(() => {
      console.log(`${newName} ${newPhone} is saved`);
      mongoose.connection.close();
      process.exit(0);
    })
    .catch((err) => {
      console.error("Error to save new info -", err.message);
      process.exit(1);
    });
}

// Find info if user do not pass name and phone in arguments
if (argvLength === 2) {
  const id = "6016ccd1c1df7c58a0c86922";
  Info.findById(id).then((info) => {
    console.log(info);
    mongoose.connection.close();
    process.exit(0);
  });
}
