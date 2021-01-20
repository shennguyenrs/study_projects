import React, { useState } from 'react';
import { ToastContainer, toast } from 'react-toastify';
import './App.css';

// Components
import NavBar from './components/NavBar';

// Utils
import { validatePhone } from './utils';

const initialInput = {
  name: '',
  phone: '',
};

const initialInfo = [{ id: 0, name: 'test1', phone: '090-403-3920' }];

const App = () => {
  // States
  const [info, setInfo] = useState(initialInfo);
  const [id, setId] = useState(1);
  const [input, setInput] = useState(initialInput);

  // Notifications
  const notifyErr = (name) => {
    toast.error(`${name} is duplicated! Please try again with a new ones!`);
  };

  const notifyErrPhone = (number) => {
    toast.error(
      `${number} is wrong format! Please try again with xxx-xxx-xxxx!`
    );
  };

  const notifySuc = () => {
    toast.success('New record added successfully!');
  };

  // Handle Events
  const handleInputChange = (e) => {
    setInput({ ...input, [e.target.name]: e.target.value });
  };

  const handleSubmit = (e) => {
    e.preventDefault();

    // Validate phone number is correct format
    if (!validatePhone(input.phone)) {
      notifyErrPhone(input.phone);
      return;
    }

    // Validate name is duplicated
    for (let i = 0; i < info.length; i += 1) {
      if (input.name === info[i].name) {
        notifyErr(input.name);
        return;
      }
    }

    // Success adding new record
    setId(id + 1);
    setInfo((prevInfo) => [...prevInfo, { id, ...input }]);
    setInput(initialInput);
    notifySuc();
  };

  const handleReset = () => {
    setInfo(initialInfo);
    setInput(initialInput);
  };

  return (
    <>
      <ToastContainer
        position="top-right"
        autoClose={5000}
        hideProgressBar={false}
        closeOnClick
        newestOnTop={true}
        pauseOnHover
      />
      <NavBar onReset={handleReset} />
      <div className="w-25 m-5 d-flex flex-column justify-content-center text-center">
        <div>
          <h1>Phonebook</h1>
          <form onSubmit={handleSubmit}>
            <div className="form-group">
              <label>Name</label>
              <input
                className="form-control mb-3"
                type="text"
                name="name"
                value={input.name}
                onChange={handleInputChange}
              />
              <label>Phone number</label>
              <input
                className="form-control mb-3"
                type="text"
                name="phone"
                value={input.phone}
                onChange={handleInputChange}
              />
              <button className="btn btn-primary" type="submit">
                Save
              </button>
            </div>
          </form>
        </div>
        <div>
          <h1>Numbers</h1>
          <ul className="list-group">
            {info.map((person) => (
              <li key={person.id} className="list-group-item bg-light">
                {person.name} - {person.phone}
              </li>
            ))}
          </ul>
        </div>
      </div>
    </>
  );
};

export default App;
