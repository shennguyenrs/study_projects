import React, { Component } from "react";
import Joi from "@hapi/joi";

export default class newMovie extends Component {
  schema = {
    title: Joi.string().required().label("Title"),
    numberInStock: Joi.number().max(10).required().label("Stock"),
    dailyRentalRate: Joi.number().max(5).required().label("Rate"),
    publishDate: Joi.date().required().label("Date"),
  };

  render() {
    return (
      <div className="container m-4">
        <div className="form-group">
          <label htmlFor="title">Title</label>
          <input type="text" id="title" className="form-control" />
        </div>
        <div className="form-group">
          <label htmlFor="genre.name">Genre</label>
          <select name="genreOptions" id="genre.name">
            {genres.map((genre) => (
              <option key={genre.id}>{genre.name}</option>
            ))}
          </select>
        </div>
        <div className="form-group">
          <label htmlFor="numberInStock">Stock</label>
          <input type="number" id="numberInStock" className="form-control" />
        </div>
        <div className="form-group">
          <label htmlFor="dailyRentalRate">Rate</label>
          <input type="number" id="dailyRentalRate" className="form-control" />
        </div>
        <div className="form-group">
          <label htmlFor="publishDate">Publish Date</label>
          <input type="date" id="publishDate" className="form-control" />
        </div>
      </div>
    );
  }
}
