#include "headerA3.h"

void saveTweetsToFile(tweet * tweetList) {
    FILE *outputFile = NULL;
    char *fileName = malloc(sizeof(char) * 100);
    tweet *tempNode = tweetList;
    
    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);
    fileName = realloc(fileName, strlen(fileName) + 1);
    outputFile = fopen(fileName, "w");
    
    while (tempNode != NULL) {
        fprintf(outputFile, "%d,%s,%s\n", tempNode -> id, tempNode -> user, tempNode -> text);
        tempNode = tempNode -> next;
    }
    printf("Output successful!\n");
}