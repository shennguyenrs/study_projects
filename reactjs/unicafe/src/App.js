import React, { Component, useState } from 'react';
import logo from './logo.svg';
import './App.css';

import NavBar from './components/navbar.jsx';

const App = () => {
  const [good, setGood] = useState(0);
  const [neutral, setNeutral] = useState(0);
  const [bad, setBad] = useState(0);

  const increaseGood = (newValue) => {
    setGood(newValue);
  };

  const increaseNeutral = (newValue) => {
    setNeutral(newValue);
  };

  const increaseBad = (newValue) => {
    setBad(newValue);
  };

  const handleReset = () => {
    setGood(0);
    setNeutral(0);
    setBad(0);
  };

  const showFeedback = (total) => {
    if (total > 0) {
      return (
        <>
          <h4>Good: {good}</h4>
          <h4>Neutral: {neutral}</h4>
          <h4>Bad: {bad}</h4>
        </>
      );
    } else {
      return (
        <>
          <h4>There is no feedback yet!</h4>
        </>
      );
    }
  };

  return (
    <>
      <NavBar
        onReset={() => {
          handleReset();
        }}
      />
      <div className="w-100 mt-2 d-block text-center">
        <div>
          <h1>Give Feedback</h1>
          <div className="btn-group">
            <div className="m-2">
              <button
                onClick={() => increaseGood(good + 1)}
                className="btn btn-success"
              >
                Good
              </button>
            </div>
            <div className="m-2">
              <button
                onClick={() => increaseNeutral(neutral + 1)}
                className="btn btn-primary"
              >
                Neutral
              </button>
            </div>
            <div className="m-2">
              <button
                onClick={() => increaseBad(bad + 1)}
                className="btn btn-danger"
              >
                Bad
              </button>
            </div>
          </div>
        </div>
        <div>
          <h1>Statistic</h1>
          {showFeedback(good + neutral + bad)}
        </div>
      </div>
    </>
  );
};

export default App;
