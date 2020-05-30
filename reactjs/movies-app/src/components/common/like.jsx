import React from "react";

const like = (props) => {
  let classes = "fa-heart fas";
  if (!props.liked) classes = classes.replace("fas", "far");
  return (
    <i
      className={classes}
      style={{ cursor: "pointer" }}
      onClick={props.onClick}
    ></i>
  );
};

export default like;
