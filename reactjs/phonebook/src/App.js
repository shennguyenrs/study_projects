import React, { useState } from 'react';
import './App.css';

const App = () => {
  const [info, setInfo] = useState([
    { id: 1, name: 'test1', phone: '090-9403-3920' },
  ]);

  const [counter, setCounter] = useState(1);

  const [input, setInput] = useState({
    name: '',
    phone: '',
  });

  const handleInputChange = (e) => {
    setInput({ ...input, [e.target.name]: e.target.value });
  };

  const handleSubmit = (e) => {
    e.preventDefault();

    const newCounter = counter + 1;
    setCounter(newCounter);

    setInfo((prevInfo) => [...prevInfo, { newCounter, ...input }]);
  };

  return (
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
  );
};

export default App;
