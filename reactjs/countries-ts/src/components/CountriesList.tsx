import React from 'react';

type Props = {
  id: number;
  name: string;
  onClick: (id: number) => void;
};

const CountriesList: React.FC<Props> = ({ id, name, onClick }: Props) => {
  return (
    <div className="d-flex align-item-center mb-3">
      <p className="m-0 p-0 mr-3">{name}</p>
      <button
        className="d-inline btn btn-sm btn-info"
        onClick={() => onClick(id)}
      >
        Show
      </button>
    </div>
  );
};

export default CountriesList;
