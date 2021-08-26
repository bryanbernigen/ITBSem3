function thumbsUp(x) {
  var x = document.getElementById("likeOrDislike");
  if (
    x.innerHTML ===
    "Please press Thumbs Up if you like or press Thumbs Down if you dislike"
  ) {
    x.innerHTML = "Thank you for your support!";
  } else if (x.innerHTML === "Sorry to let you down.") {
    x.innerHTML = "Thank you for your support!";
  }
}

function thumbsDown(x) {
  var x = document.getElementById("likeOrDislike");
  if (
    x.innerHTML ===
    "Please press Thumbs Up if you like or press Thumbs Down if you dislike"
  ) {
    x.innerHTML = "Sorry to let you down.";
  } else if (x.innerHTML === "Thank you for your support!") {
    x.innerHTML = "Sorry to let you down.";
  }
}
