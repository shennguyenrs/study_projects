import axios from 'axios';
import { toast } from 'react-toastify';
import logger from './loggerServices';

axios.interceptors.response.use(null, (error) => {
  const expectedErrors =
    error.response &&
    error.response.status >= 400 &&
    error.response.status < 500;

  if (!expectedErrors) {
    logger.log(error);
    toast.error('An unexpected error occurs');
  }

  return Promise.reject(error);
});

export default {
  put: axios.put,
  get: axios.get,
  delete: axios.delete,
  post: axios.post,
};
