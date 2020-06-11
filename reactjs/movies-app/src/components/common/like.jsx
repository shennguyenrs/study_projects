import React from "react";

const Like = ({ liked, onClick }) => {
  let classes = "fa-heart fas";
  if (!liked) classes = classes.replace("fas", "far");

  return (
    <i className={classes} style={{ cursor: "pointer" }} onClick={onClick}></i>
  );
};

export default Like;
