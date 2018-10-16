// define maximum size of plaintext/ciphertext
#define MAX_SIZE 255
#define ALPHABET_SIZE 26

// prototypes for caesar
char *encrypt_caesar(int key);
char *decrypt_caesar(int key);

// prototypes for vigenere
char *encrypt_vigenere(char *key);
char *decrypt_vigenere(char *key);