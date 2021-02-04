const morgan = require('morgan');
const logger = require('./logger');

morgan.token('content', (req, res) => {
  return JSON.stringify(req.body);
});

const unknownEndpoint = (req, res) => {
  res.status(404).json({ error: 'Unknown Endpoint' });
};

const requestLogger = () => {
  morgan(
      ':method :url :status :res[content-length] - :response-time ms :content'
  );
};

const errorHandler = (err, req, res, next) => {
  logger.error(err.message);
  res.status(err.httpStatusCode || 400).json({ error: err.message });
  next(err);
};

module.exports = {
  unknownEndpoint,
  requestLogger,
  errorHandler,
};
