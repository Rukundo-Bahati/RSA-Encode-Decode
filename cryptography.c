
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt();
void decryption();
void toEncrypt();
int decrypt();


//Variable Initialization
    char str[100]; // Store input message (encryption or decryption)

int p, q; // The primes
int e, d; // Public and Private key
int a; // Phi n
int n; // Product of primes

int i,k,m;

int encryption; 

// GCD function
int gcd(int number1, int number2)  {
 
 if(number2 == 0) {
    return number1;
 }

 return gcd(number2,number1%number2);
}

//Check if Prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // If there is a factor, the number is not prime
        }
    }

    return true; // If no factors found, the number is prime
}

//CREATING THE KEYS
void encrypt() {
    printf("Enter message to Encrypt:");
    fgets(str, sizeof(str), stdin);
    printf("\nChoose two prime numbers Less than 12: ");
    scanf("%d%d",&p,&q);

    if (!isPrime(p) || !isPrime(q)) {
        printf("The numbers are not prime\n");
        exit(1);
    }

    // value of n
    n=p*q;

    // value of a
    a=(p-1) * (q-1);

    // value of e
    int found = 0;

    // finding co-prime number less than a
    for(i=2; i<a; i++){
        if(gcd(a,i)==1 && gcd(n,i)==1){
            e=i;
            found = 1;
            break;
        }
    }   

    if(!found) {
        printf("Couldn't Find a suitable value of 'e'.  Choose other Primes\n");
    }
    else{
        printf("Public key (e,n): (%d, %d)\n",e,n);

        for(k=0; k<a; k++){
            if((k*e)%a==1){
                d=k;
            }
        }
        printf("Private key (d,n): (%d, %d)\n\n",d,n);
        toEncrypt();
    }
}

// ENCRYPTION
void toEncrypt(){

    int encryptedMessage[100] = {0};  // Assuming a maximum message length of 100

    int encryptedIndex = 0; //Track current position in array

    for (m = 0; str[m] != '\0'; m++) {
        int characterNumber = toupper(str[m]) - 'A'; // character number
        printf("%c : %d\n", str[m] ,characterNumber);
        long encryption = (int)(fmod(pow(characterNumber, e), n)); // encryption
        printf("Encrypted character %c: %d\n\n", str[m], encryption);
        encryptedMessage[encryptedIndex++] = (int)encryption;  // Store encrypted value in the array
    }

    printf("Encrypted Message is: ");
    for(i=0; i<encryptedIndex; i++){
        printf("%d,",encryptedMessage[i]);
    }   

}

// DECRYPTION
int decrypt(int d,int n){

    int numbers[10];
    int i;
	long decryption;
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '\0'";
    int count;
    
    if(!count){
        printf("Too long");
        exit(1);
    }
    else {
    	     
    printf("\nHow many input numbers make up your encrypted message?\n");
    scanf("%d",&count);

	}
    
    printf("\nEnter the encryption numbers(in Series): \n");
 
    for(i=0;i<count; i++){
        scanf("%d",&numbers[i]);	
    }

    printf("Decrypted Message is:\n");
    
    for(i=0;i<count;i++){
        decryption = (int)(fmod(pow(numbers[i],d),n));	
        printf("%c ",letters[decryption]);
    }
    printf("\n");
    return 0;
}

// main function
int main() {
    int start;

    printf("Press 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &start);
    getchar();  // Consume the newline character

    if (start == 1) {
        encrypt();
    } else if (start == 2) {
        int code1, code2;
        printf("Enter the private key: \n");
        scanf("%d%d", &code1, &code2);
        getchar();  // Consume the newline character
        decrypt(code1, code2);
    } else {
        printf("Invalid number");
    }


    return 0;
}