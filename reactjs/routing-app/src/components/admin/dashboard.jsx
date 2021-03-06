import React from "react";
import { Route } from "react-router-dom";
import SideBar from "./sideBar.jsx";
import Users from "./users";
import Posts from "./posts";

const Dashboard = () => {
  return (
    <div>
      <h1>Admin Dashboard</h1>
      <SideBar />
      <Route path="/admin/users" component={Users} />
      <Route path="/admin/posts" component={Posts} />
    </div>
  );
};

export default Dashboard;
