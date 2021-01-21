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
