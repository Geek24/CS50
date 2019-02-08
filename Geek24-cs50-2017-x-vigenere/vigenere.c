#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Author: Chris Edwards, 2017
// Beverly, MA

int main (int argc, string argv[])
{
     string argument = argv[1];
     
    // Checks to make sure proper command line arguments exist
    if (argc == 1 || argv[1] == NULL)
    {
        printf("Error! Program must be used with command line argument.\n");
        return 1;
    }
    
    // checks to make sure the argument is alphabetical.
    for (int i = 0; i < strlen(argument); i++)
    {
        if (isalpha(argument[i]) == false)
            {
                printf("Error! Must be alphabetical.\n");
                return 1;
            }
    }
    {
     
        
    printf("plaintext:");

    string plaintext = get_string();

    printf("ciphertext:");
    
    
    // Loop as long as each iteration is < or = length of code to cipher.
    for (int i = 0, q = 0, k = strlen(plaintext); i < k; i++)
    {
        int length = strlen(argv[1]);
        char key = argv[1][(q) %length];
        char cipher = plaintext[i];
 
        if (islower(key))
        {
            key -= 97;
        }
        if (isupper(key))
        {
            key -= 65;
        }
        
       // Applies cipher properly to lowercase text
       if (islower(plaintext[i]))
       {
           
           printf("%c", ((cipher + key - 97) % 26 + 97 ));
           q++;
        
       }
       
       // Applies cipher properly to uppercase text
       else if (isupper(plaintext[i])) {
           
           printf("%c", ((cipher + key - 65) % 26 + 65) );
           q++;
          
       }
   
       else {
           printf("%c", plaintext[i]);
        
       }

       
       if (plaintext[i+1] == '\0')
        {
            printf("\n");
       }
       
    }
   
   
    }
    
}

