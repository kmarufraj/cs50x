#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for positive integer
    int n;
    do
    {
        n = get_int("Height: ");
    }

    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            printf(" ");
        }

        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }

        printf(" ");

        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }

        printf("\n");
    }
}
