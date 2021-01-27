import React, { useState, useEffect } from 'react';
import axios from 'axios';

// Interface
import { WeatherInterface, CityName } from '../common/interface';

type Props = CityName;

const CityWeather: React.FC<Props> = ({ cityName }: Props) => {
  // States
  const [weather, setWeather] = useState<WeatherInterface>();
  const [error, setError] = useState<boolean>(true);

  // Use Effect
  useEffect(() => {
    axios
      .get('http://api.weatherstack.com/current', {
        params: {
          access_key: process.env.REACT_APP_API_WEATHER,
          query: cityName,
        },
      })
      .then(({ data }) => {
        if (!data.error) {
          setError(false);
          setWeather({
            localTime: data.location.localtime,
            temperature: data.current.temperature,
            feelsLike: data.current.feelslike,
            icon: data.current.weather_icons[0],
            description: data.current.weather_descriptions[0],
            windSpeed: data.current.wind_speed,
            windDir: data.current.wind_dir,
            humidity: data.current.humidity,
            uv: data.current.uv_index,
          });
        } else {
          console.log('Get data from weather api happens error!');
          console.log(data.error.info);
        }
      });
  }, []);

  return (
    <>
      {!error ? (
        <div className="mt-3">
          <h3>Weather in {cityName}</h3>
          <p>
            <b>Local time: </b>
            {weather?.localTime}
          </p>
          <p>
            <b>Temperature: </b>
            {weather?.temperature} &#8451;
          </p>
          <p>
            <b>Feels like: </b>
            {weather?.feelsLike} &#8451;
          </p>
          <div className="mb-3">
            <img src={weather?.icon} alt="icon-weather" />
          </div>
          <p>
            <b>Description: </b>
            {weather?.description}
          </p>
          <p>
            <b>Wind Speed: </b>
            {weather?.windSpeed}
          </p>
          <p>
            <b>Wind Direction: </b>
            {weather?.windDir}
          </p>
          <p>
            <b>Humidity: </b>
            {weather?.humidity}
          </p>
          <p>
            <b>UV Index: </b>
            {weather?.uv}
          </p>
        </div>
      ) : (
        <h3> Can not get weather data of {cityName} </h3>
      )}
    </>
  );
};

export default CityWeather;
