#include "headerA3.h"
#include "helperA3.h"

int searchTweetsByKeyword(tweet * tweetList) {
    tweet *head = tweetList; // point head to the beginning of the list
    tweet *tempNode;
    int i,j;
    bool similarity = 0, matchFound = 0;
    char *keyWord = malloc(sizeof(char) * MAX_TEXT + 1); // max tweet size + 1 byte for new line

    // prompt user for keyword input
    printf("Enter a keyword to search: ");
    fgets(keyWord, MAX_TEXT + 1, stdin);
    
    if (keyWord[strlen(keyWord) - 1] == '\n') {
        keyWord[strlen(keyWord) - 1] = '\0'; // gets rid of newline character '\n'
    }
    keyWord = realloc(keyWord, strlen(keyWord) + 1); // enough space for the string including NULL
    
    tempNode = head;
    while (tempNode != NULL) { // loop iterates till tempNode reaches end of list
        for (i = 0; i < strlen(tempNode -> text); i++) { // iterates length of tweet text time
            // branch entered if one character in tweet text is equal to the first character in the keyword
            if (tolower(tempNode -> text[i]) == tolower(keyWord[0])) { 
                similarity = 1; // similarity set to TRUE
                for (j = 1; j < strlen(keyWord); j++) { // iterates length of keyword - 1 times
                    // branch checks if characters same length from the first character in keyword are not equal
                    if (tolower(tempNode -> text[i + j]) != tolower(keyWord[j])) { // tolower function for case-insensitivity
                        similarity = 0; // similarity set back to FALSE if entered                  
                    }
                }
            }
        }
        if (similarity == 1) {
            printf("Match found for '%s': %s wrote: \"%s\"\n", keyWord, tempNode -> user, tempNode -> text); // node print
            matchFound = 1;
            similarity = 0; // resets similarity for the next node
        }
        tempNode = tempNode -> next; // updates pointer to point to the next node
    }
    
    free(keyWord);
    if (matchFound == 1) { // branch indicates success of function finding a match 
        return 1;
    
    }
    return 0; // if match wasnt found 0 is returned
}