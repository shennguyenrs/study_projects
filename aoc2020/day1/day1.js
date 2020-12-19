const fs = require('fs');

// Find couple
function findCouple(data) {
  let begin = 0;
  let end = data.length - 1;

  while (begin < end) {
    const total = Number(data[begin]) + Number(data[end]);

    if (total === 2020) {
      console.log(`The first number is ${data[begin]}`);
      console.log(`The second number is ${data[end]}`);
      console.log(`Their multiply is ${data[begin] * data[end]}`);
      break;
    }

    end -= total > 2020 ? 1 : 0;
    begin += total < 2020 ? 1 : 0;
  }
}

// Find triplet
function findTriplet(data) {
  for (let i = 1; i < data.length; i += 1) {
    const begin = i;
    let mid = i + 1;
    let end = data.length - 1;

    while (mid < end) {
      const total = Number(data[begin]) + Number(data[mid]) + Number(data[end]);

      if (total === 2020) {
        console.log(`The first number is ${data[begin]}`);
        console.log(`The second number is ${data[mid]}`);
        console.log(`The third number is ${data[end]}`);
        console.log(`Their multiply is ${data[begin] * data[mid] * data[end]}`);
        break;
      }

      end -= total > 2020 ? 1 : 0;
      mid += total < 2020 ? 1 : 0;
    }
  }
}

// Read file to lines
const lines = fs.readFileSync('entries.txt', 'utf-8').split('\n');

// Sort lines
lines.sort();

// Find couple
findCouple(lines);

console.log();

// Find triplet
findTriplet(lines);
