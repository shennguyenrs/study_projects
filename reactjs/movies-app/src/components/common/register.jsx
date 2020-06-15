import React from "react";
import Joi from "@hapi/joi";
import Form from "./form";

export default class register extends Form {
  state = { account: { email: "", username: "", password: "" }, errors: {} };

  schema = {
    email: Joi.string()
      .email()
      .min(3)
      .max(30)
      .required()
      .label("Email Address"),
    username: Joi.string().min(3).max(30).label("Username"),
    password: Joi.string().min(8).max(16).label("Password"),
  };

  doSubmit = () => {
    this.handleSubmit();
    // Cal Backend
    console.log("Submitted");
  };

  render() {
    return (
      <div className="container p-4">
        <form onSubmit={this.handleSubmit}>
          {this.renderInput("email", "Email Address", "email")}
          {this.renderInput("username", "Username")}
          {this.renderInput("password", "Password", "password")}
          {this.renderButton("Register")}
        </form>
      </div>
    );
  }
}
