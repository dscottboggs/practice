const readline = require('readline');
const DEBUG = true;
const debugmsg = (msg) => {if(DEBUG) {console.log(msg);}}

function buildStaircase(ofSize) {
  /* Return a string of 'ofSize' rows and columns.
   *
   *

   * Any logging from this function will appear BEFORE the staircase.
   *
   * If 'ofSize' is 4, the staircase should look like this:
   * ______
   * |   #|
   * |  ##|
   * | ###|
   * |####|
   * -----
   * (without the box arount it, that's just to show boundaries.)
   */
  let out = "";
  debugmsg(`Building staircase ${ofSize} rows high and columns wide.`)
  // code goes here
  // row# = ofSize; iterate through rows
  // row0 = ' ' * (ofSize - 1) + '#'
  // row1 = ' ' * (ofSize - 2) + ('#' * 2)
  // rowN = ' ' * (ofSize - N - 1) + ('#' * N)
  for (var row = 0; row < ofSize; row++) {
    for (var column = 0; column < ofSize; column++){
      // Condition deciding if ' ' or '#' should be added to out.
      out += column <= (ofSize - row - 2)? " ": "#";
      // if (column <= (ofSize - column - 1)) {
      //   out = out + " ";
      // } else {
      //   out = out + "#";
      // }
    }
    out = out + "\n";
  }

  return out;
}

function main() {
  const inputreader = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });
  inputreader.question(
    "Size of staircase: ",
    (sizeOf) => {
      console.log(buildStaircase(sizeOf));
      inputreader.close();
    }
  );
}

main();
