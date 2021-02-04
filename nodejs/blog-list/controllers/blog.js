const appRouter = require('express').Router();
const Blog = require('../models/blog');

appRouter.get('/', (req, res, next) => {
  Blog.find({})
    .then((blogs) => {
      res.json(blogs);
    })
    .catch((err) => next(err));
});

appRouter.post('/', (req, res, next) => {
  const blog = new Blog(req.body);

  blog
    .save()
    .then((result) => {
      res.status(201).json(result);
    })
    .catch((err) => next(err));
});

module.exports = appRouter;
