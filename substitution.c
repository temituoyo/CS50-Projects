#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{

    //Checks how many command arguements were put in
    if (argc == 2)
    {

        //Checks if the Key is 26 characters long
        //Account for all letters of the alphabet
        if (strlen(argv[1]) == 26)
        {

            //Check for invalid characters and repeating characters
            int count = 0;
            int repeat = 0;
            for (int i = 0, n = strlen(argv[1]); i < n; i++)
            {

                for (int j = 0, m = tolower(argv[1][i]); j < n; j++)
                {

                    //Switch all characters to lower case to avoid
                    if (m == tolower(argv[1][j]))
                    {

                        repeat += 1;

                    }

                }

                //Check if characters are all aphabets
                if ((argv[1][i] > 64 && argv[1][i] < 91) || (argv[1][i] > 96 && argv[1][i] < 123))
                {

                    count += 1;

                }

            }

            if (repeat == 26 && count == 26)
            {

                //Encrypting the text
                int position;
                string plain = get_string("plaintext: ");

                for (int i = 0, n = strlen(plain); i < n; i++)
                {

                    if ((plain[i] > 64 && plain[i] < 91) || (plain[i] > 96 && plain[i] < 123))
                    {

                        //Maintain the characters case (upper or lower case)
                        if (isupper(plain[i]))
                        {

                            position = plain[i] - 65;
                            plain[i] = toupper(argv[1][position]);

                        }
                        else
                        {

                            position = plain[i] - 97;
                            plain[i] = tolower(argv[1][position]);

                        }

                    }

                }
                printf("ciphertext: %s\n", plain);
                return 0;

            }
            else
            {

                printf("Invalid Key!\n");
                return 1;

            }



        }
        else
        {

            printf("Key should be 26 characters long!\n");
            return 1;

        }

    }
    else
    {

        printf("Please enter key as a single word\n");
        return 1;

    }




}
