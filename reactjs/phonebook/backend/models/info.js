const mongoose = require('mongoose');
const uri = process.env.MONGODB_URI;

console.log('Connecting to', uri);

// Connect to database
mongoose
  .connect(uri, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    useFindAndModify: true,
    useCreateIndex: true,
  })
  .then(() => console.log('Success to connect to database'))
  .catch((err) => console.log('Failed to connect to database', err.message));

// Create Schema
const infoSchema = new mongoose.Schema({
  name: {
    type: String,
    required: [true, 'Name is required'],
  },
  phone: {
    type: String,
    required: [true, 'Phone number is required'],
    validate: {
      validator: (str) => {
        return /([0-9]{3})-([0-9]{3})-([0-9]{4})$/.test(str);
      },
      message: (prop) => `${prop.value} is not in valid format: xxx-xxx-xxxx!`,
    },
  },
});

infoSchema.set('toJSON', {
  transform: (document, returnedObject) => {
    returnedObject.id = returnedObject._id.toString();
    delete returnedObject._id;
    delete returnedObject.__v;
  },
});

module.exports = mongoose.model('Info', infoSchema);
