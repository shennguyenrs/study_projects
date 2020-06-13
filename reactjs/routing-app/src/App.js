import React from "react";
import "./App.css";
import { Route, Switch, Redirect } from "react-router-dom";
import NavBar from "./components/navbar";
import Home from "./components/home";
import Products from "./components/products";
import NotFound from "./components/notFound";
import Posts from "./components/posts";
import ProductDetails from "./components/productDetails";
import DashBoard from "./components/admin/dashboard";

function App() {
  return (
    <>
      <NavBar />
      <div className="content">
        <Switch>
          <Route path="/products/:id" component={ProductDetails} />
          <Route
            path="/products"
            render={(props) => <Products sortBy="newest" {...props} />}
          />
          <Route path="/posts/:year?/:month?" component={Posts} />
          <Route path="/posts" component={Posts} />
          <Redirect from="/message" to="/posts" />
          <Route path="/admin" component={DashBoard} />
          <Route path="/not-found" component={NotFound} />
          <Route path="/" exact component={Home} />
          <Redirect to="/not-found" />
        </Switch>
      </div>
    </>
  );
}

export default App;
