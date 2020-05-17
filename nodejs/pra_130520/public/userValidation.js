function username() {
  let username = document.getElementById("username").value;
  let spacePattern = /\s/g;

  // Username validation
  // Must have at least 6 characters
  if (username.length <= 6) {
    document
      .getElementById("unMessage")
      .innerHTML("Username must have at least 6 non-space characters");
  } else {
    document.getElementById("unMessage").innerHTML = "";
  }
  if (username.matches(spacePattern)) {
    document
      .getElementById("unMessage")
      .innerHTML("Username must have no space");
  } else {
    document.getElementById("unMessage").innerHTML = "";
  }
}
