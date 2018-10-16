#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "helpers.h"
#include "mod.c"

int main(int argc, char *argv[1])
{
    //check that we have two command-line arguments
    if (argc == 3)
    {
        //check that input is strictly alphabetical
        for (int i = 0, t = strlen(argv[1]); i < t; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("ERROR! Key must be a string");
                return 1;
            }
        }

        if (strcmp(argv[2], "encrypt") == 0)
        {
            char *cipherText;
            cipherText = encrypt_vigenere(argv[1]);
            printf("ciphertext: %s\n", cipherText);
            free(cipherText);
        }

        if(strcmp(argv[2], "decrypt") == 0)
        {
            char *plainText;
            plainText = decrypt_vigenere(argv[1]);
            printf("plaintext: %s\n", plainText);
            free(plainText);
        }

        return 0;
    }
    else
    {
        printf("ERROR! Usage ./vigenere [key] [encrypt/decrypt]");
        return 1;
    }

}

char *encrypt_vigenere(char *key)
{
    // variables needed to keep track of index in key
    int keyLength = strlen(key);
    int plainPosition = 0;

    //prompt user for text
    char plain[MAX_SIZE];
    printf("plaintext: ");
    fgets(plain, MAX_SIZE, stdin);

    // initialize variables
    int plainLength = strlen(plain);
    char *cipher;
    cipher = malloc(sizeof(char) * (plainLength+1));
    int shift = 0;

    //code to cipher the plaintext
    for (int i = 0; i < plainLength; i++)
    {
        //checks if character is alphabetical
        if (isalpha(plain[i]))
        {
            int keyPosition = plainPosition % keyLength;

            //checks the case of the key and determines the shift
            if (isupper(key[keyPosition]))
            {
                shift = key[keyPosition] - 'A';
            }
            else if (islower(key[keyPosition]))
            {
                shift = key[keyPosition] - 'a';
            }

            //ciphers uppercase letters
            if (isupper(plain[i]))
            {
                cipher[i] = mod((plain[i] - 'A' + shift), ALPHABET_SIZE) + 'A';
            }
            //ciphers lowercase letters
            else if (islower(plain[i]))
            {
                cipher[i] = mod((plain[i] - 'a' + shift), ALPHABET_SIZE) + 'a';
            }

            plainPosition++;
        }
        else
        {
            cipher[i] = plain[i];
        }

    }
    cipher[plainLength] = '\0';
    return cipher;
}

char *decrypt_vigenere(char *key)
{
    // variables needed to keep track of index in key
    int keyLength = strlen(key);
    int cipherPosition = 0;

    //prompt user for text
    char cipher[MAX_SIZE];
    printf("ciphertext: ");
    fgets(cipher, MAX_SIZE, stdin);

    // initialize variables
    int cipherLength = strlen(cipher);
    char *plain;
    plain = malloc(sizeof(char) * (cipherLength+1));
    int shift = 0;

    // decrypt the ciphertext
    for (int i = 0; i < cipherLength; i++)
    {
        //checks if character is alphabetical
        if (isalpha(cipher[i]))
        {
            int keyPosition = cipherPosition % keyLength;

            //checks the case of the key and determines the shift
            if (isupper(key[keyPosition]))
            {
                shift = key[keyPosition] - 'A';
            }
            else if (islower(key[keyPosition]))
            {
                shift = key[keyPosition] - 'a';
            }

            //decrypt uppercase letters
            if (isupper(cipher[i]))
            {
                plain[i] = mod((cipher[i] - 'A' - shift), ALPHABET_SIZE) + 'A';
            }
            //decrypt lowercase letters
            else if (islower(cipher[i]))
            {
                plain[i] = mod((cipher[i] - 'a' - shift), ALPHABET_SIZE) + 'a';
            }

            cipherPosition++;
        }
        else
        {
            plain[i] = cipher[i];
        }

    }
    plain[cipherLength] = '\0';
    return plain;
}