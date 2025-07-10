#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long number2 = number;

    int sum = 0;
    int position = 0;

    while (number > 0)
    {
        int digit = number % 10;

        if (position % 2 == 1)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                // Add the digits of the product (e.g. 12 → 1 + 2 = 3)
                digit = (digit / 10) + (digit % 10);
            }
        }

        sum = sum + digit;
        number = number / 10;
        position++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }


    char number_str[20];
    sprintf(number_str, "%ld", number2);

    int first_two = (number_str[0] - '0') * 10 + (number_str[1] - '0');
    int first = number_str[0] - '0';


    if ((first_two == 34 || first_two == 37) && position == 15)
    {
        printf("AMEX\n");
    }

    else if (first_two >= 51 && first_two <= 55 && position == 16)
    {
        printf("MASTERCARD\n");
    }

    else if (first == 4 && (position == 13 || position == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
