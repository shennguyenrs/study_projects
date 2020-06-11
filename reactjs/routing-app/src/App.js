import React from "react";
import "./App.css";
import { Route, Switch } from "react-router-dom";
import NavBar from "./components/navbar";
import Home from "./components/home";
import Products from "./components/products";
//import NotFound from "./components/notFound";
import Posts from "./components/posts";
//import ProductDetails from "./components/productDetails";
import DashBoard from "./components/admin/dashboard";

function App() {
  return (
    <>
      <NavBar />
      <div className="content">
        <Switch>
          <Route path="/products" component={Products} />
          <Route path="/posts" component={Posts} />
          <Route path="/admin" component={DashBoard} />
          <Route path="/" component={Home} />
        </Switch>
      </div>
    </>
  );
}

export default App;
