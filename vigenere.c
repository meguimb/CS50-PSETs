#include <cs50.h>
#include <stdio.h>
#include <string.h>

//prototypes
int shift(char c);
char shiftToKey(int startIndex, int key);
bool isLetter(char c);
string numbersArray = "0123456789";

int main(int argc, string argv[])
{
    //checks if has more than one arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    int keyCheck = atoi(argv[1]);
    // check if k is null or is a number 
    if (keyCheck!=0)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    // declaration of variables, creating an array of the keyword's ascii numbers
    string keyword = argv[1];
    int keywordLength = strlen(keyword);
    //check if keyword doesn't have a number
    for(int i = 0; i < keywordLength; i++)
    {
        for(int j = 0; j < strlen(numbersArray); j++)
        {
            if(keyword[i] == numbersArray[j])
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
    }
    int keyPlacesArray[keywordLength];
    for (int i = 0; i < keywordLength; i++)
    {
        keyPlacesArray[i] = (int)keyword[i];
    }
    
    //gets text to cipher
    string normalText = get_string("plaintext:  ");
    string cipherText = "";
    char cipherChar='0';
    
    //creates array for the ciphered text
    char cipheredArray[strlen(normalText)];
    int counter = 0;
    
    for(int i = 0; i < strlen(normalText); i++)
    {
        //check if plain text char is a letter
        if(isLetter(normalText[i]))
        {
            //checks if character out of bounds
            if (counter >= strlen(keyword))
            {
                counter = 0;
            }
            // counter is working
            //ciphers characters and adds to array
            //shift is working and shiftPlaces too
            //normalText is working too
            int shiftPlaces = shift((char)keyPlacesArray[counter]);
            cipherChar = shiftToKey((int)(normalText[i]), shiftPlaces);
            cipheredArray[i] = cipherChar;
            counter++;      
        }
        else{
            cipheredArray[i] = normalText[i];
        }
    }
    // prints ciphered text to the screen, one by one in array
    printf("ciphertext: ");
    for(int i = 0; i < strlen(normalText); i++)
    {
        printf("%c", cipheredArray[i]);
    }
    printf("\n");
}
//// takes a letter as an input and decides how many places to shift accordingly
int shift(char c)
{
    int index = (int) c;
    if (c >= 'A' && c <= 'Z')
    {
        index = index - (int) 'A';
    }
    else if (c >= 'a' && c <= 'z')
    {
        index = index - (int) 'a';
    }
    return index;
}

// function that shifts to key, output is chiphered char
char shiftToKey(int startIndex, int key)
{
    int finalIndex = 0;
    if(startIndex>='A' && startIndex <= 'Z')
    {
        if((startIndex + key > (int)'Z'))
        {
            printf("%c is now %c\n", startIndex, startIndex + key - 26);
            return startIndex + key - 26;
        }
        return startIndex + key;
    }
    else if(startIndex>='a' && startIndex <= 'z')
    {
        if((startIndex + key > (int)'z'))
        {
            return startIndex + key - 26;
        }
        return startIndex + key;
    }
    return startIndex;
}
// function that checks is character is letter and therefore shiftable
bool isLetter(char c)
{
    if ((c >= 'A' && c <= 'Z') || ((c >= 'a') && c <= 'z'))
    {
        return true;
    }
    return false;
}