const mongoose = require("mongoose");

if (process.argv.length < 3) {
  console.log(
    "Please provide the password as an argument: nodejs index.js <password>"
  );
  process.exit(1);
}

const password = process.argv[2];
const uri = `mongodb+srv://dbadmin:${password}@fullstack.s3bwy.mongodb.net/test?retryWrites=true&w=majority`;

mongoose.connect(uri, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
  useFindAndModify: false,
  useCreateIndex: true,
});

const noteSchema = new mongoose.Schema({
  content: String,
  date: Date,
  important: Boolean,
});

const Note = mongoose.model("Note", noteSchema);
const note = new Note({
  content: "HTML is easy",
  date: new Date(),
  important: true,
});

note.save().then((result) => {
  console.log("Note saved");
  console.log(result);
  mongoose.connection.close();
});
