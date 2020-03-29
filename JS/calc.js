/* This is first program: calculator;
Prints out result based on given operator and inputs*/

const readline = require('readline-sync');

function printWelcomeMessage () {
console.log('Welcome to the calculator!');
console.log('==========================')
}

function getStringInput(prompt) {
    console.log(prompt);
    return readline.prompt();
}

function getNumberInput(prompt) {
    let numberValue;
    do {
        numberValue = +getStringInput(prompt);
    } while (isNaN(numberValue));
    return numberValue;
}

function getNumberArray(operator) {
    const iterations = getNumberInput(`How many numbers do you want to ${operator}?`);
    let numbers = new Array(iterations);
    for (let x = 0; x < iterations; x++) {
        numbers[x] = getNumberInput(`Please enter number ${x + 1}:`);
    }
    return numbers;
}

function getOperator() {
    return getStringInput('Please enter the operator:');
}

function calculateAnswer(operator, numbers) {
    let answer = numbers[0];
    for (let x = 1; x < numbers.length; x++) {
        if(operator === '+') {
            answer += numbers[x];
        } else if(operator === '-') {
            answer -= numbers[x];
        } else if(operator === '*') {
            answer *= numbers[x];
        } else if(operator === '/') {
            answer /= numbers[x];
        } 
    } return answer;
}

printWelcomeMessage();
const operator = getOperator();
const numbers = getNumberArray(operator);
const answer = calculateAnswer(operator, numbers);
console.log(`\nThe answer is ${answer}`);
