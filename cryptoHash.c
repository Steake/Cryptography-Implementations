#include <stdio.h>
#include <string.h>
#include <math.h> 
// Constants used in the hashing function 
const int p = 31;
 double m = 1000000007;

// Function to calculate hash value of a given string 
long long calculateHash(char *str) { 

    // Initialize result 
    long long hashValue = 0;  

    // Calculate length of string str  
    int len = strlen(str);  

    // Calculate the hash value of given string str[0..len-1]  
    for (int i=0; i<len; i++) {  

        // Add current character to the hash value and multiply by prime number p (31) 
        // Then mod with a large prime number (1000000007).
	//This is done to make sure that the final hash value is within the range of integer data type.
	//This helps in avoiding overflow errors while performing arithmetic operations on this result.      

        hashValue = (int)hashValue + (int)(str[i]-'a'+1)*pow(p,i) % (int)m;
} 

    return hashValue;
}
