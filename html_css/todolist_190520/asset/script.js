window.onload = () => {
  // Press Enter to add the item
  let enterkey = this.document.getElementById("inputItem");
  enterkey.addEventListener("keydown", (e) => {
    if (e.code === "Enter") {
      e.preventDefault();
      this.document.getElementById("button").click();
    }
  });

  let list = document.querySelector("ul");
  list.addEventListener("click", (e) => {
    let targetItem = e.target;

    // Checked and unchecked items by click
    if (targetItem.tagName === "SPAN") {
      targetItem.classList.toggle("done-task");
    }

    // Edit Item
    if (targetItem.className === "fas fa-pen") {
      editItem();
    }

    // Remove Item
    if (targetItem.className === "fas fa-minus-circle") {
      let line = targetItem.parentNode;
      let thisLi = line.parentNode;
      thisLi.removeChild(line);
    }
  });
};

// Add Items function
function addItem() {
  let item = document.getElementById("inputItem");
  let span = document.createElement("span");
  let edit = document.createElement("i");
  let remove = document.createElement("i");
  let node = document.createElement("li");

  edit.className = "fas fa-pen";
  remove.className = "fas fa-minus-circle";

  // Alert if the input task is empty
  if (item === null) {
    document.getElementById("message").innerHTML =
      "The task name is empty! Please enter again!";
  }

  span.innerHTML = item.value;

  node.appendChild(span);
  node.appendChild(edit);
  node.appendChild(remove);

  document.getElementById("list").appendChild(node);

  // Clear input form after submit
  item.value = "";
}
