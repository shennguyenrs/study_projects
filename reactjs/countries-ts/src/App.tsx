import React, { useState, useEffect } from 'react';
import axios from 'axios';
import './App.css';

// Components
import CountryInfo from './components/CountryInfo';

// Interface
import { CountryInterface } from './common/interface';

const initialFound = {
  name: '',
  capital: '',
  population: 0,
  area: 0,
  languages: [],
  flag: '',
};

const App: React.FC = () => {
  // States
  const [data, setData] = useState([]);
  const [input, setInput] = useState('');
  const [found, setFound] = useState<CountryInterface>(initialFound);

  const isFound = false;

  // Use Effect
  useEffect(() => {
    axios.get(process.env.REACT_APP_API_COUNTRIES as string).then((res) => {
      setData({ ...res.data });
    });

    setFound({
      name: data[0].name,
      capital: data[0].capital,
      population: data[0].population,
      area: data[0].area,
      languages: data[0].languages,
      flag: data[0].flag,
    });
  }, []);

  // Handle Events
  const handleInputChange = (e: React.ChangeEvent<HTMLInputElement>): void => {
    setInput(e.target.value);
  };

  return (
    <div className="m-2 d-inline-block">
      <form>
        <div className="form-group">
          <label className="mr-2">
            <b>Find</b>
          </label>
          <input
            type="text"
            name="name"
            value={input}
            onChange={handleInputChange}
          />
        </div>
      </form>
      {isFound && (
        <CountryInfo
          name={found.name}
          capital={found.capital}
          population={found.population}
          area={found.area}
          languages={found.languages}
          flag={found.flag}
        />
      )}
    </div>
  );
};

export default App;
