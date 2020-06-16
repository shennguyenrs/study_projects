import React, { Component } from 'react';
import Joi from '@hapi/joi';

// Import Components
import Input from './input';
import InputOptions from './inputOptions';

export default class form extends Component {
  state = { account: {}, errors: {} };

  validateProperty = ({ name, value }) => {
    let object = { [name]: value };
    let schema = { [name]: this.schema[name] };
    let { error } = Joi.validate(object, schema);
    return error ? error.details[0].message : null;
  };

  validate = () => {
    let { account } = this.state;
    let { error } = Joi.validate(account, this.schema, { abortEarly: false });

    if (!error) return null;
    let errors = {};
    for (let item of error.details) errors[item.path[0]] = item.message;
    return errors;
  };

  handleSubmit = (e) => {
    e.preventDefault();

    let errors = this.validate();
    this.setState({ errors: errors || {} });
    if (errors) return console.log(errors);
  };

  handleChange = ({ currentTarget: input }) => {
    let errors = { ...this.state.errors };
    let errorMessages = this.validateProperty(input);
    if (errorMessages) errors[input.name] = errorMessages;
    else delete errors[input.name];

    let account = { ...this.state.account };
    account[input.name] = input.value;
    this.setState({ account, errors });
  };

  renderButton(label) {
    return (
      <button disabled={this.validate()} className="btn btn-primary">
        {label}
      </button>
    );
  }

  renderInput(name, label, type) {
    let { account, errors } = this.state;
    return (
      <Input
        name={name}
        type={'text' || type}
        label={label}
        value={account[name]}
        error={errors[name]}
        onChange={this.handleChange}
      />
    );
  }

  renderOptions(name, label, objects) {
    return <InputOptions name={name} label={label} objects={objects} />;
  }
}
