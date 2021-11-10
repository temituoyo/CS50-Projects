#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user to input their Credit card number
    long number = get_long("Number: ");

    //Checking if it is a valid credit card number

    int first;
    int total_first = 0;
    int second;
    int total_second = 0;
    long factor = 10;
    int checksum;
    long check = number;
    long checklength = number;
    int length = 0;

    //The length of the Credit card number
    do
    {

        length++;
        checklength /= 10;

    }
    while (checklength > 0);

    //Extracting digits of the credit card number to complete the Luhn Algorithm
    for (int i = 1; i < (length + 1); i++)
    {
        if (i % 2 == 1)
        {

            //Sum of the first digit from the back
            first = check % factor;
            total_first += first;

        }
        else if (i % 2 == 0)
        {

            //Sum of the second digit from the back multiplied by 2
            second = check % factor;
            if ((second * 2) >= 10)
            {

                total_second += ((second * 2) % 10);
                total_second += ((second * 2) / 10) % 10;


            }
            else
            {

                total_second += (second * 2);

            }

        }
        check /= factor;

    }

    //Check sum for algorithm to determine if it is valid or not
    checksum = total_first + total_second;

    if ((checksum % 10) == 0)
    {

        //Check for type of cards

        //Check for VISA
        if (length == 13 && first == 4)
        {

            printf("VISA\n");

        }
        else if (length == 16 && second == 4)
        {

            printf("VISA\n");

        }
        //Check for American Express card
        else if (length == 15 && first == 3)
        {

            if (second == 4 || second == 7)
            {

                printf("AMEX\n");

            }
            else
            {

                printf("INVALID\n");

            }

        }
        //Check for Mastercard
        else if (length == 16 && second == 5)
        {
            if (first >= 1)
            {

                if (first <= 5)
                {

                    printf("MASTERCARD\n");

                }
                else
                {

                    printf("INVALID\n");

                }

            }
            else
            {

                printf("INVALID\n");

            }

        }
        else
        {

            printf("INVALID\n");

        }

    }
    else
    {

        printf("INVALID\n");

    }

}
