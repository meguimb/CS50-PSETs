#include <cs50.h>
#include <stdio.h>
#include <string.h>

char shiftToKey(int startIndex, int key);

int main(int argc, string argv[])
{
    // check if number of args are correct
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    else
    {
        int k = atoi(argv[1]);
        // check if k is null or not int
        if ((k == 0) || (k == '\0'))
        {
            printf("Usage: ./caesar key\n");
            return 0;
        }
        else{
            // get normal text from user
            string normalText = get_string("plaintext: ");
            printf("ciphertext: ");
            // print ciphered text
            for (int i = 0; i < strlen(normalText); i++)
            {
                int startIndex = (int) normalText[i];
                printf("%c", shiftToKey(startIndex, k));
            }
            printf("\n");
        }
    }
}
char shiftToKey(int startIndex, int key)
{
    int finalIndex = 0;
    // check some stuff
    bool upperCaseCheck = ((startIndex + key) > 'Z' && startIndex < 'a');
    bool lowerCaseCheck = ((startIndex + key) > 'z');
    if (startIndex < (int)'A' || startIndex > 'z' || (startIndex < 'a' && startIndex > 'Z'))
    {
        return startIndex;
    }
    else if (upperCaseCheck || lowerCaseCheck)
    {
        int tempIndex = startIndex + key;
        while (!((tempIndex >= 'A' && tempIndex <= 'Z') || (tempIndex >= 'a' && tempIndex <= 'z')))
        {
            tempIndex -= 26;
        }
        //finalIndex = startIndex + key - (int)('z' - 'a' +1);
        finalIndex = (tempIndex);
        return (char) finalIndex;
    }
    return (char)(startIndex + key);
}