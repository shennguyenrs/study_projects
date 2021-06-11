let slideIndex = 1;

const plusImg = (n) => {
  showImgs((slideIndex += n));
};

const showImgs = (n) => {
  const x = document.getElementsByClassName("slider__img");

  if (n > x.length) {
    slideIndex = 1;
  }

  if (n < 1) {
    slideIndex = x.length;
  }

  for (let i = 0; i < x.length; i++) {
    x[i].style.display = "none";
  }

  x[slideIndex - 1].style.display = "block";
};

window.onload = () => {
  showImgs(slideIndex);
};
