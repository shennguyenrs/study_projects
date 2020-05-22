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
  // Double click to mask as done
  list.addEventListener("dblclick", (e) => {
    let targetItem = e.target;

    if (targetItem.tagName === "SPAN") {
      let parent = targetItem.parentNode;
      if (!parent.classList.contains("on-edit")) {
        targetItem.classList.toggle("done");
      }
    }
  });

  // Click to edit or remove item
  list.addEventListener("click", (e) => {
    let targetItem = e.target;

    // Edit Item
    if (targetItem.className === "fas fa-pen") {
      editItem(targetItem);
    }

    // Remove Item
    if (targetItem.className === "fas fa-minus-circle") {
      let line = targetItem.parentNode;
      let ul = line.parentNode;
      ul.removeChild(line);
    }
  });
};

// Add Items function
function addItem() {
  let item = document.getElementById("inputItem").value;
  let span = document.createElement("span");
  let inputform = document.createElement("input");
  let edit = document.createElement("i");
  let remove = document.createElement("i");
  let node = document.createElement("li");

  edit.className = "fas fa-pen";
  remove.className = "fas fa-minus-circle";

  // Alert if the input task is empty
  if (item.length === 0) {
    document.getElementById("message").innerHTML =
      "The task name is empty! Please enter again!";
  } else {
    span.innerText = item;
    inputform.type = "text";

    node.appendChild(span);
    node.appendChild(inputform);
    node.appendChild(edit);
    node.appendChild(remove);

    document.getElementById("list").appendChild(node);

    // Clear input form after submit
    item.value = "";
  }
}

// Edit Item function
function editItem(targetItem) {
  let line = targetItem.parentNode;
  let span = line.getElementsByTagName("SPAN");
  let inputform = line.getElementsByTagName("INPUT");

  inputform.value = span.innerText;
  console.log(span.innerHTML);

  // Change style of editing form
  line.classList.toggle("on-edit", true);
  inputform.focus();

  // Listen for Enter key to finish
  inputform.addEventListener("keydown", (e) => {
    if (e.key === "Enter") {
      e.preventDefault();
      span.innerText = inputform.value;
      line.classList.toggle("on-edit", false);
    }
  });
}
