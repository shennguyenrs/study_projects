import React from "react";
import Joi from "@hapi/joi";
import Form from "./form";

export default class login extends Form {
  state = { account: { email: "", password: "" }, errors: {} };

  schema = {
    email: Joi.string()
      .email()
      .min(3)
      .max(30)
      .required()
      .label("Email Address"),
    password: Joi.string().min(8).max(16).required().label("Password"),
  };

  doSubmit = () => {
    this.handleSubmit();
    // Call Backend
    console.log("Submitted");
  };

  render() {
    return (
      <div className="container p-4">
        <form onSubmit={this.handleSubmit}>
          {this.renderInput("email", "Email Address", "email")}
          {this.renderInput("password", "Password", "password")}
          {this.renderButton("Login")}
        </form>
      </div>
    );
  }
}
