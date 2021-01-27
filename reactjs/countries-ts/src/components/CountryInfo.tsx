import React from 'react';

// Interface
import { CountryInterface } from '../common/interface';

// Styles
import { Img } from '../common/styles';

type Props = CountryInterface;

const CountryInfo: React.FC<Props> = ({
  name,
  capital,
  population,
  area,
  languages,
  flag,
}: Props) => {
  return (
    <>
      <div className="info">
        <h1>{name}</h1>
        <p>
          <b>Capital: </b> {capital}
        </p>
        <p>
          <b>Population: </b> {population}
        </p>
        <p>
          <b>Area: </b> {area}
        </p>
      </div>
      <div className="languages">
        <h3>Languages</h3>
        <ul>
          {languages.map((lang) => (
            <li key={lang.nativeName}>{lang.name}</li>
          ))}
        </ul>
      </div>
      <div className="flag">
        <Img src={flag} alt="country-flag" />
      </div>
    </>
  );
};

export default CountryInfo;
