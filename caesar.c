#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "helpers.h"
#include "mod.c"

int main(int argc, char *argv[])
{
    //check that we have two command-line arguments
    if (argc == 3)
    {
        if (strcmp(argv[2], "encrypt") == 0)
        {
            char *cipherText;
            cipherText = encrypt_caesar(atoi(argv[1]));
            printf("ciphertext: %s\n", cipherText);
            free(cipherText);
        }

        if(strcmp(argv[2], "decrypt") == 0)
        {
            char *plainText;
            plainText = decrypt_caesar(atoi(argv[1]));
            printf("plaintext: %s\n", plainText);
            free(plainText);
        }
        return 0;
    }
    else
    {
        printf("ERROR! Usage ./caesar [key] [encrypt/decrypt] \n");
        return 1;

    }

}

char *encrypt_caesar(int key)
{
    //prompt user for text
    char plain[MAX_SIZE];
    printf("plaintext: ");
    fgets(plain, MAX_SIZE, stdin);

    //initialize variables
    int plainLength = strlen(plain);
    char *cipher;
    cipher = malloc(sizeof(char) * (plainLength+1));

    //encrypt the plaintext
    for (int i = 0; i < plainLength; i++)
    {
        //checks if character is alphabetical
        if (isalpha(plain[i]))
        {
            //ciphers uppercase letters
            if (isupper(plain[i]))
            {
                cipher[i] = mod((plain[i] - 'A' + key), ALPHABET_SIZE) + 'A';
            }
            //ciphers lowercase letters
            else if (islower(plain[i]))
            {
                cipher[i] = mod((plain[i] - 'a' + key), ALPHABET_SIZE) + 'a';
            }
            }
            else
            {
                cipher[i] = plain[i];
        }
    }
    cipher[plainLength] = '\0';
    return cipher;
}

char *decrypt_caesar(int key)
{
    //prompt user for text
    char cipher[MAX_SIZE];
    printf("ciphertext: ");
    fgets(cipher, MAX_SIZE, stdin);

    //initialize variables
    int cipherLength = strlen(cipher);
    char *plain;
    plain = malloc(sizeof(char) * (cipherLength+1));

    //decrypt the ciphertext
    for (int i = 0; i < cipherLength; i++)
    {
        //checks if character is alphabetical
        if (isalpha(cipher[i]))
        {
            //ciphers uppercase letters
            if (isupper(cipher[i]))
            {
                plain[i] = mod((cipher[i] - 'A' - key), ALPHABET_SIZE) + 'A';
            }
            //ciphers lowercase letters
            else if (islower(cipher[i]))
            {
                plain[i] = mod((cipher[i] - 'a' - key), ALPHABET_SIZE) + 'a';
            }
        }
        else
        {
            plain[i] = cipher[i];
        }
    }
    plain[cipherLength] = '\0';
    return plain;
}