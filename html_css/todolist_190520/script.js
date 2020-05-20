window.onload = () => {
  // Press Enter to add the item
  let enterkey = this.document.getElementById("inputItem");
  enterkey.addEventListener("keydown", (e) => {
    if (e.code === "Enter") {
      e.preventDefault();
      this.document.getElementById("button").click();
    }
  });

  // Checked and unchecked items by click
  let list = document.querySelector("ul");
  list.addEventListener("click", (e) => {
    let targetItem = e.target;
    if (targetItem.tagName === "LI") {
      targetItem.classList.toggle("done-task");
    }
  });
};

// Add Items function
function addItem() {
  let item = document.getElementById("inputItem");
  let node = document.createElement("li");

  // Alert if the input task is empty
  if (item === null) {
    document.getElementById("message").innerHTML =
      "The task name is empty! Please enter again!";
  }

  let textnode = document.createTextNode(item.value);
  node.appendChild(textnode);
  document.getElementById("list").appendChild(node);

  // Clear input form after submit
  item.value = "";
}
