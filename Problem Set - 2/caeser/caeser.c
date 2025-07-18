#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            char encrypted = ((c - 'A' + key) % 26) + 'A';
            printf("%c", encrypted);
        }
        else if (islower(c))
        {
            char encrypted = ((c - 'a' + key) % 26) + 'a';
            printf("%c", encrypted);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
