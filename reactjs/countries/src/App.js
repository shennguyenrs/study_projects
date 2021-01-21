import React, { useState, useEffect } from 'react';
import axios from 'axios';
import './App.css';

const App = () => {
  const [data, setData] = useState([]);
  //const [input, setInput] = useState('');

  useEffect(() => {
    axios.get(process.env.REACT_APP_API_COUNTRIES).then((res) => {
      setData({ ...res.data[0] });
    });
  }, []);

  return (
    <>
      <form>
        <div className="form-group">
          <label className="m-2">Find Countries</label>
          <input type="text" />
        </div>
      </form>
      <div className="country">
        <div className="info">
          <h1>{data.name}</h1>
          <p>
            <b>Capital: </b> {data.capital}
          </p>
          <p>
            <b>Population: </b> {data.population}
          </p>
          <p>
            <b>Area: </b> {data.area}
          </p>
        </div>
        <div className="languages">
          <h3>Languages</h3>
          <ul>
            {data.languages.map((lang) => (
              <li key={lang.nativeName}>{lang.name}</li>
            ))}
          </ul>
        </div>
        <div className="flag">
          <img src={data.flag} />
        </div>
      </div>
    </>
  );
};

export default App;
