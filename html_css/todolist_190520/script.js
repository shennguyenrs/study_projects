// Press Enter to add the item
var input = document.getElementById("inputItem");
if (!!input) {
    input.addEventListener("keyup", e => {
        if (e.keyCode === 13) {
            e.preventDefault();
            document.getElementById("button").click();
    }});
}

// Add Items function
function addItem() {
    let item = document.getElementById("inputItem");
    let node = document.createElement("li");
    // Alert if the input task is empty
    if (item === null) {
        document.getElementById("message").innerHTML = "The task name is empty! Please enter again!";
    }

    let textnode = document.createTextNode(item.value);
    node.appendChild(textnode);
    document.getElementById("list").appendChild(node);
}

// Check and un-check items by clicking 
var list = document.querySelector("ul");
list.addEventListener("click", ev => {
    if (ev.target.tagName === "li") {
        ev.target.classList.toggle("done-task");
      }
    }, false);