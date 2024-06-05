<h1>RSA Encoding and Decoding in C</h1>
This project implements RSA encryption and decryption algorithms in C.
It demonstrates how to generate RSA keys, encrypt messages, and decrypt messages using the RSA algorithm.

Features
Generate RSA public and private keys
Encrypt messages using the public key
Decrypt messages using the private key
Simple command-line interface
Prerequisites
A C compiler (e.g., GCC)
Basic understanding of RSA algorithm and C programming
Getting Started
Clone the Repository
sh
Copy code
git clone https://github.com/Rukundo-Bahati/Cryptography.git
cd rsa-encoding-decoding
Compile the Program
sh
Copy code
gcc rsa.c -o rsa -lm
Run the Program
sh
Copy code
./rsa
Usage
Upon running the program, you will be prompted to choose between generating keys, encrypting a message, or decrypting a message.

Generate Keys
The program will generate a pair of RSA keys and display them.

Encrypt a Message
You will be prompted to enter a message. The program will then encrypt the message using the public key and display the encrypted message.

Decrypt a Message
You will be prompted to enter the encrypted message. The program will then decrypt the message using the private key and display the original message.

Example
mathematica
Copy code
RSA Encryption and Decryption
1. Generate RSA Keys
2. Encrypt Message
3. Decrypt Message
4. Exit
Enter your choice: 1

Generated RSA keys:
Public Key: (e, n)
Private Key: (d, n)

RSA Encryption and Decryption
1. Generate RSA Keys
2. Encrypt Message
3. Decrypt Message
4. Exit
Enter your choice: 2

Enter the message to encrypt: Hello, RSA!
Encrypted message: <encrypted_message>

RSA Encryption and Decryption
1. Generate RSA Keys
2. Encrypt Message
3. Decrypt Message
4. Exit
Enter your choice: 3

Enter the message to decrypt: <encrypted_message>
Decrypted message: Hello, RSA!
File Structure
rsa.c: The main C source file containing the implementation of RSA encryption and decryption.
README.md: This README file.
Contributing
Feel free to fork this repository, make changes, and submit pull requests. Any contributions, such as optimizations, bug fixes, or additional features, are welcome.

License
This project is licensed under the MIT License. See the LICENSE file for more details.

Contact
For any questions or feedback, please contact rukundorca@gmail.com.
