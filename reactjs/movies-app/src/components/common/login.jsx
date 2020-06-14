import React, { Component } from "react";
import Joi from "joi";
import Input from "./input";

export default class login extends Component {
  state = { account: { email: "", password: "" }, errors: {} };

  schema = {
    username: Joi.require().label("Username"),
    password: Joi.require().label("Password"),
  };

  validateProperty = () => {};

  validate = () => {
    let errors = {};
    let { account } = this.state;

    if (account.email === "") errors.email = "Email is required";
    if (account.password === "") errors.password = "Password is required";
    return Object.keys(errors).length === 0 ? null : errors;
  };

  handleSubmit = (e) => {
    e.preventDefault();

    let errors = this.validate();
    this.setState({ errors: errors || {} });
    if (errors) return console.log(errors);
    return console.log("Submitted");
  };

  handleChange = ({ currentTarget: input }) => {
    let account = { ...this.state.account };
    account[input.name] = input.value;
    this.setState({ account });
  };

  render() {
    const { account, errors } = this.state;

    return (
      <div className="container p-4">
        <form onSubmit={this.handleSubmit}>
          <Input
            name="email"
            label="Email Address"
            value={account.email}
            error={errors.email}
            handleChange={this.handleChange}
          />
          <Input
            name="password"
            label="Password"
            value={account.password}
            error={errors.password}
            handleChange={this.handleChange}
          />
          <button className="btn btn-primary">Login</button>
        </form>
      </div>
    );
  }
}
