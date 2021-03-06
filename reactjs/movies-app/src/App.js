import React from 'react';
import { Route, Switch, Redirect } from 'react-router-dom';
import './App.css';

// Import Components
import Movies from './components/movies';
import NavBar from './components/navBar';
import Customers from './components/customers';
import Rentals from './components/rentals';
import NotFound from './components/notfound';
import Login from './components/common/login';
import Register from './components/common/register';
import FormMovie from './components/common/formMovie';

function App() {
  return (
    <>
      <NavBar />

      <Switch>
        <Route path="/login" component={Login} />
        <Route path="/register" component={Register} />
        <Route path="/movies/:id" component={FormMovie} />
        <Route path="/movies" component={Movies} />
        <Route path="/customers" component={Customers} />
        <Route path="/rentals" component={Rentals} />
        <Route path="/not-found" component={NotFound} />
        <Redirect exact from="/" to="/movies" />
        <Redirect to="/not-found" />
      </Switch>
    </>
  );
}
export default App;
