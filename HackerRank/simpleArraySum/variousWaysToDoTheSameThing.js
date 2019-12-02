function sumWithForIn(arr) {
  let total = 0;
  for (var index in arr) {
    total += arr[index];
  }
  return total;
}

function sumWithForEach(arr) {
  let total = 0;
  arr.forEach( (val) => total += val);
  return total;
}

function sumWithStandardForLoop(arr)  {
  let total = 0;
  for (var index = 0; index<arr.length; index++){
    total += arr[index];
  }
  return total;
}

function sumWithWhileLoop(arr) {
  let total = 0;
  let index = 0;
  while (index<arr.length) {
    total += arr[index];  //  total = total + arr element @ index
    index ++;             //  increment the index by one
  }
  return total;
}

function main() {
  const a = [1, 2, 3, 4, 5];
  const b = [2, 4, 56, 90];
  console.log(`With for...in: ${sumWithForIn(a)}`);
  console.log(`With array.forEach(): ${sumWithForEach(a)}`);
  console.log(`With a standard for loop: ${sumWithStandardForLoop(a)}`);
  console.log(`With a while loop: ${sumWithWhileLoop(a)}`);
  console.log(`With while loop/2nd arr: ${sumWithWhileLoop(b)}`);
}

main();
