#include "headerA3.h"

int searchTweetsByKeyword(tweet * tweetList) {
    tweet *head = tweetList;
    tweet *tempNode;
    int i,j;
    bool similarity = 0, matchFound = 0;
    char *keyWord = malloc(sizeof(char) * 141); // max tweet size

    printf("Enter a keyword to search: ");
    scanf("%s", keyWord);
    keyWord = realloc(keyWord, strlen(keyWord) + 1); // enough space for the string including NULL
    
    tempNode = head;
    while (tempNode != NULL) {
        for (i = 0; i < strlen(tempNode -> text); i++) {
            if (tolower(tempNode -> text[i]) == tolower(keyWord[0])) {
                similarity = 1;
                for (j = 1; j < strlen(keyWord); j++) {
                    if (tolower(tempNode -> text[i + j]) != tolower(keyWord[j])) {
                        similarity = 0;                       
                    }
                }
            }
        }
        if (similarity == 1) {
            printf("Match found for '%s': %s wrote: \"%s\"\n", keyWord, tempNode -> user, tempNode -> text);      
            matchFound = 1;
            similarity = 0;
        }
        tempNode = tempNode -> next;
    }
    if (matchFound == 1) { // branch indicates success of function finding a match 
        return 1;
    }
    return 0;
}
