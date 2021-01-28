import axios from 'axios';

// Base url
const baseUrl = '/api/persons';

// Get all data from api
const getAll = () => {
  const req = axios.get(baseUrl);
  return req.then((res) => res.data);
};

// Create new person
const create = (newObj) => {
  const req = axios.post(baseUrl, newObj);
  return req.then((res) => res.data);
};

export default { getAll, create };
