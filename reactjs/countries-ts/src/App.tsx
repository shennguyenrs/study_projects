import React, { useState, useEffect } from 'react';
import axios from 'axios';
import './App.css';

// Components
import CountryInfo from './components/CountryInfo';
import CountriesList from './components/CountriesList';
import CityWeather from './components/CityWeather';

// Interface
import { CountryInterface } from './common/interface';

const App: React.FC = () => {
  // States
  const [data, setData] = useState<CountryInterface[]>([]);
  const [input, setInput] = useState('');
  const [found, setFound] = useState<CountryInterface[]>([]);
  const [index, setIndex] = useState(0);
  const [showCountry, setShowCountry] = useState(false);

  // Use Effect
  useEffect(() => {
    axios
      .get(process.env.REACT_APP_API_COUNTRIES as string)
      .then(({ data }) => {
        setData(
          data.map((item: CountryInterface) => {
            return {
              name: item.name,
              capital: item.capital,
              population: item.population,
              area: item.area,
              languages: item.languages,
              flag: item.flag,
            };
          })
        );
      });
  }, []);

  // Handle Events
  const handleInputChange = (e: React.ChangeEvent<HTMLInputElement>): void => {
    const keyword = e.target.value;
    setInput(keyword);

    // Reset show country and index
    if (showCountry) {
      setIndex(0);
      setShowCountry(false);
    }

    // Make data list to match the keyword
    const filterCountries = [...data].filter(
      (country) =>
        country.name.slice(0, keyword.length).toLowerCase() ===
        keyword.toLowerCase()
    );

    // When delete everything on the search bar
    if (keyword === '') {
      setFound([]);
    } else {
      setFound(filterCountries);
    }
  };

  const handleCountryClick = (index: number) => {
    setIndex(index);
    setShowCountry(true);
  };

  const handleSearch = () => {
    if (found.length !== 1 && !showCountry) {
      return (
        <>
          {found.slice(0, 5).map((country, id) => (
            <CountriesList
              key={id}
              id={id}
              name={country.name}
              onClick={() => handleCountryClick(id)}
            />
          ))}
        </>
      );
    } else {
      return (
        <>
          <CountryInfo
            name={found[index].name}
            capital={found[index].capital}
            population={found[index].population}
            area={found[index].area}
            languages={found[index].languages}
            flag={found[index].flag}
          />
          <CityWeather cityName={found[index].capital} />
        </>
      );
    }
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
      {handleSearch()}
    </div>
  );
};

export default App;
