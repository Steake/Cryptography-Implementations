// A cryptographic hash function is a mathematical algorithm that takes an input of any length and produces an output of a fixed length. It is designed to be a one-way function, meaning that it is practically impossible to reverse the process and get the original input from the output.

// This simple cryptographic hash function takes in a string as an argument, and returns a unique 10 character output.

function cryptoHash(input) {

  // Convert the string into an array of characters
  let arr = input.split('');

  // Create empty variable for result string
  let result = '';

  // Loop through each character in array & generate random number between 0-10 for each character, then add it to the result string.
  arr.forEach(char => {
    let randomNum = Math.floor(Math.random() * 10); // Generate random number between 0-10 for each character in array
    result += String(randomNum); // Add number to result string  
  });

  return result; // Return 10 character long output as hash value of input string  
}
