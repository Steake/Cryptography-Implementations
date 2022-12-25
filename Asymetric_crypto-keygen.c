#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>


// Generate a random number in the range [min, max] 
    time_t t;
int random_number(int min, int max) {


        srand((unsigned) time(&t)); 



    return min + rand() % ((max + 1) - min); //returns random number between min and max both inclusive!  
}

// Returns true if num is prime else false    
int isPrime(int num) {


    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    
    for (int i = 5; i * i <= num; i = i++) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    
    return 1;
} //Generates a prime number of specified length in bits 
int generatePrime(int bitlength) {

    printf("[Subroutine:generatePrime(int bitlength:%d)]\nGenerating Prime...\n", bitlength);


    int primeCandidate = 0;
    int _primeCandidate;
    int flag = 0;
    while (!flag) {
        if (primeCandidate == _primeCandidate) break;
        _primeCandidate = primeCandidate;
        primeCandidate = random_number(2 ^ bitlength, 2 ^ bitlength + 1);
        printf("isPrime? %d\n", flag);
        if (flag) printf("Prime Candidate: %d\n", primeCandidate);
        flag = isPrime(primeCandidate);
    }
    printf("prime generated:%d\n", primeCandidate);
    return primeCandidate;
}
//Generates public and private key pair   
void generateKeys() {
    int randomSeed=1;
    int _randomSeed=1;
    do {
             randomSeed = randomSeed + rand() % 128;
            printf ("Using Random Seed: %d\n", randomSeed);
    } while(randomSeed==_randomSeed);

    int p1 = generatePrime(randomSeed);
    printf ("P1: %d\n", p1);
    int p2 = generatePrime(randomSeed);
    printf ("P2: %d\n", p2);
    int p1Timesp2 = (p1 * p2);
    // Phi is = p1 -1 * p2 -1 
    int phi = (p1 - 1) * (p2 - 1);
    printf ("Phi: %d\n", phi);
    int e =1;
    int d;
    int _e = 0;
    printf("%d\n",e);
    do {
        if (e == _e || e != 1) break;
        // Generate epsilon, a random number between half of phi and phi -1  
        e = random_number ((phi / 2) + 1, phi - 1);
        printf("%d\n",e);
    } while (!isPrime((e)));
        // Generate delta, two times phi, plus one divided by epsilon 
    d = (2 * phi + 1) / e;
    printf("Public key:(%d ,%d) \nPrivate key:(%d ,%d)\n", e, p1Timesp2, d, p1Timesp2);
}
//Driver code to test above functions 
int main() {
    generateKeys();
    return 0;
}