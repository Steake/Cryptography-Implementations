#include <stdio.h> 
#include <math.h> 
  
// Function to calculate (base^exponent)%modulus 
long long int modulo(long long int base, long long int exponent,  
                                              long long int modulus) 
{ 
    // Initialize result 
    long long int result = 1;  

    // Update result if exponent is greater than or equal to 1 
    while (exponent >= 1) {

        // If exponent is odd, multiply with base and update the exponent and result accordingly. 
        if (exponent % 2 == 1) {        // If exponent is odd then update the result with base^exponent % modulus value.    

            result = (result * base) % modulus;  

            --exponent;    // Reduce the value of exp by 1 as it's odd now.    

        } else {               // If exp is even then calculate base ^ (exp/2) and store in a temp variable t.    

            long long int t = modulo(base, exponent / 2, modulus);     

            // Calculate t^2 % modulus and store in result for further use.     

            result = (t * t) % modulus;      

            exponent /= 2;          // reduce the exp by half as it's even now     

        }   

    }       return result;      // return the final calculated value of Result.     */     
}     /* Driver program to test above function */
int main() {    
    printf("%lld",modulo(3, 3, 5));              
    return 0;       
}
      