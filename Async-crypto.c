#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

// Structure to store public and private keys 
struct Keypair {
    int n; // modulus for both keys 
    int e; // public key 
    int d; // private key 
};


// Generates prime numbers using Sieve of Eratosthenes method and stores them in an array of size n
// b/w 2 to n-1 where n is the number given by user.  

void generatePrime(int prime[], int n) {

    int isPrime[n + 1];

    memset(isPrime, 1, sizeof(isPrime));

    for (int p = 2; p * p <= n; p++) {

        if (isPrime[p] == 1) {

            for (int i = p * 2; i <= n; i += p)

                isPrime[i] = 0;

        }

    }

    int j = 0; // Stores the generated prime numbers in an array     

    for (int p = 2; p <= n; p++) {

        if (isPrime[p]) prime[j++] = p;
    }

} // Generates public and private keys using Euclid's Algorithm
void generatePublicPrivateKey(struct Keypair * keypair, int prime1, int prime2) {
    keypair -> n = prime1 * prime2;
    keypair -> e = 2;
    while (keypair -> e < keypair -> n) {
        if ((prime1 - 1) * (prime2 - 1) % keypair -> e != 0) {
            break;
        } else {
            ++keypair -> e;
        }
    }
    keypair -> d = ((prime1 - 1) * (prime2 - 1)) / keypair -> e;
} 

// Calculate message signature using modulo exponentiation
void calculateSignature(char message[], struct Keypair * keyPair, long long signatureArray[]) {
    long long base = 0;
    long long exponent = keyPair -> d;
    long long modulus = keyPair -> n;
    long long signatureValue = 0;
    long long i;
    long long j = strlen(message);

    for (i = 0; i < j; ++i) {
        base = (base * 256) + message[i];
        signatureValue = (base ^ exponent) % modulus;;
        signatureArray[i] = signatureValue;
    }
    printf("\nThe Signature Value of the Message : ");
    for (i = 0; i < j - 1; ++i) {
        printf("%lld", signatureArray[i]);
    }
    printf("%lld\n", signatureArray[j - 1]);
} 

char base46_map[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                     'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};


char* base64_encode(char* plain) {

    char counts = 0;
    char buffer[3];
    char* cipher = malloc(strlen(plain) * 4 / 3 + 4);
    int i = 0, c = 0;

    for(i = 0; plain[i] != '\0'; i++) {
        buffer[counts++] = plain[i];
        if(counts == 3) {
            cipher[c++] = base46_map[buffer[0] >> 2];
            cipher[c++] = base46_map[((buffer[0] & 0x03) << 4) + (buffer[1] >> 4)];
            cipher[c++] = base46_map[((buffer[1] & 0x0f) << 2) + (buffer[2] >> 6)];
            cipher[c++] = base46_map[buffer[2] & 0x3f];
            counts = 0;
        }
    }

    if(counts > 0) {
        cipher[c++] = base46_map[buffer[0] >> 2];
        if(counts == 1) {
            cipher[c++] = base46_map[(buffer[0] & 0x03) << 4];
            cipher[c++] = '=';
        } else {                      // if counts == 2
            cipher[c++] = base46_map[((buffer[0] & 0x03) << 4) + (buffer[1] >> 4)];
            cipher[c++] = base46_map[(buffer[1] & 0x0f) << 2];
        }
        cipher[c++] = '=';
    }

    cipher[c] = '\0';   /* string padding character */
    return cipher;
}


char* base64_decode(char* cipher) {

    char counts = 0;
    char buffer[4];
    char* plain = malloc(strlen(cipher) * 3 / 4);
    int i = 0, p = 0;

    for(i = 0; cipher[i] != '\0'; i++) {
        char k;
        for(k = 0 ; k < 64 && base46_map[k] != cipher[i]; k++);
        buffer[counts++] = k;
        if(counts == 4) {
            plain[p++] = (buffer[0] << 2) + (buffer[1] >> 4);
            if(buffer[2] != 64)
                plain[p++] = (buffer[1] << 4) + (buffer[2] >> 2);
            if(buffer[3] != 64)
                plain[p++] = (buffer[2] << 6) + buffer[3];
            counts = 0;
        }
    }

    plain[p] = '\0';    /* string padding character */
    return plain;
}

// Driver Program to test above functions
int main() {
    char message[] = "TestTest";
    long long signatureArray[20];
    struct Keypair kp;
    printf("---------------------------\n");
    printf("Enter two different Prime Numbers: \n");
    int a, b;
    scanf("%d %d", & a, & b);
    generatePublicPrivateKey( &kp, a, b);
    printf("---------------------------\n");
    printf("Enter message to sign: \n");
    scanf("%s", & message);
    calculateSignature(message, &kp, signatureArray);
    printf("Message Signature Base64: 0x");
    printf("%s\n",base64_encode(message));

    return 0;
}