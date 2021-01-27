export interface Languages {
  iso639_1: string;
  iso639_2: string;
  name: string;
  nativeName: string;
}

export interface CountryInterface {
  name: string;
  capital: string;
  population: number;
  area: number;
  languages: Array<Languages>;
  flag: string;
}

export interface WeatherInterface {
  localTime: string;
  temperature: number;
  feelsLike: number;
  icon: string;
  description: string;
  windSpeed: number;
  windDir: string;
  humidity: number;
  uv: number;
}

export interface CityName {
  cityName: string;
}
