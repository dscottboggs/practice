'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function rightDiagonal(arrays) {
    let sum = 0;
    for (var index in arrays) {
        sum += arrays[index][index];
    }
    return sum;
}

function leftDiagonal(arrays){
    let sum    = 0;
    let row    = 0;
    let column = arrays.length - 1;
    while (row < arrays.length) {
        sum += arrays[row][column];
        row++;
        column--;
    }
    return sum;
}

// Complete the diagonalDifference function below.
function diagonalDifference(arrays) {
    let diff = (rightDiagonal(arrays) - leftDiagonal(arrays));
    return Math.abs(diff);
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    console.log("How many numbers wide/tall is the grid?");
    const n = parseInt(readLine(), 10);

    let a = Array(n);

    for (let i = 0; i < n; i++) {
        console.log(`Input Line #${i}.`);
        a[i] = readLine().split(' ').map(aTemp => parseInt(aTemp, 10));
    }

    let result = diagonalDifference(a);

    ws.write(result + "\n");

    ws.end();
}
