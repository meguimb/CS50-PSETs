#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <stdlib.h>

// char remove_spaces(char s);
char* concat(const char *s1, const char *s2);
bool isCharacterValid(char c);
char oneLetterPassword(char *hashedPassword, char salt[], char *all);
string fiveLetterPassword(char *hashedPassword, char salt[], char *all);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash");
        return 1;
    }
    char *hashedPassword = argv[1];
    
    //check if character is valid
    for (int i = 0; i < strlen(hashedPassword); i++)
    {
        char character = (char) hashedPassword[i];
        bool isValid = isCharacterValid(character);
        if(isValid==false)
        {
            printf("Usage: ./crack hash");
            return 1;
        }
    }
    
    //all characters passwords can have
    char *allCharacters = " qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0";
    char allCharactersArray[strlen(allCharacters) + 1];
    allCharactersArray[0] = '\0';
    
    for (int i = 0; i < strlen(allCharacters); i++)
    {
        allCharactersArray[i+1] = allCharacters[i];
    }
       
    string hashed = argv[1];
    //array of salt -> the first two numbers of hashed password
    char p0 = hashed[0];
    char p1 = hashed[1];
    char p[2];
    p[0] = p0;
    p[1] = p1;
    // create function for one letter password to 5 letter password
    string word = fiveLetterPassword(hashed, p, allCharacters);
    printf("%s\n", word);
    return 0;
}
//function that checks all passwords with 5 letters or less
//takes the hashed password, the salt and a list of all possible characters
//returns the password if found
string fiveLetterPassword(char *hashedPassword, char salt[], char *all)
{
    string password ="00000";
    //iterates through every possibility of letter (or space) for the 5 max-letters
    for(int i = 0; i < strlen(all); i++)
    {        
        for (int j = 0; j < strlen(all); j++)
        {
            for(int k = 0; k < strlen(all); k++)
            {
                for(int l = 0; l < strlen(all); l++)
                {
                    for(int m = 0; m < strlen(all); m++)
                    {
                        // creates an array of each char
                        char current[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
                        current[0]=(char)all[i];
                        current[1]=(char)all[j];
                        current[2]=(char)all[k];
                        current[3]=(char)all[l];
                        current[4]=(char)all[m];
                        current[5]='\0';
                        
                        string possibleWord = "";
                        //removes spaces from each array and creates a string
                        for(int a = 0; a < 5; a++)
                        {
                            char tempString[2];
                            tempString[0] = current[a];
                            tempString[1] = '\0';
                            if(strcmp(tempString, " ")!=0)
                            {
                                possibleWord = concat(possibleWord, tempString);
                            }
                        }   
                        // with created string, calc the possible hashed password
                        string crypted = crypt(possibleWord, salt);
                                            
                        // check if the possible hashed password is equal to the user's input
                        // if it is return the password                    
                        if (strcmp(crypted, hashedPassword)==0)
                        {
                            return possibleWord;
                        }
                    }
                }
            }
        }
    }
    return "0";
}

// checks if hashed password is valid
bool isCharacterValid(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    else if (c == '.' || c == '/')
    {
        return true;
    }
    else if(c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

// function that concatenates two strings --> will be very helpful
// don't quite understand the first line bc I haven't learned memory or anything related
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
