#include <stdio.h> 
#include <string.h> 
  
// A simple hash function used to 
// map a given key to its index 
// in hash table 
void main () {

hashFunction("T");
char helloworld = 'Hello World';
hashFunction(helloworld);
}

int hashFunction(char *str) 
{ 
    int hashIndex = 0; 

    // Iterate through each character of the string and add the ASCII value of each character to the index
           // multiplied by a prime number (37 in this case)
            // This ensures that the result is unique for different strings.
        int i;

    for (i = 0; i < strlen(str); i++) { 

        hashIndex += (int)str[i] * 37; 

    }

    return hashIndex % 10; // Return the index between 0 and 9 inclusive.   
}
