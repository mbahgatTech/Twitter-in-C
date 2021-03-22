#include "headerA3.h"
#include "helperA3.h"

void saveTweetsToFile(tweet * tweetList) {
    FILE *outputFile = NULL;
    char *fileName = malloc(sizeof(char) * 100); //initial memory allocated for the name of file
    tweet *tempNode = tweetList;
    
    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);
    fileName = realloc(fileName, strlen(fileName) + 1); // enough space for the string input and NULL '\0'
    outputFile = fopen(fileName, "w"); // opens a file with the name of 

    // branch gives an error message if opening the file failed
    if (outputFile == NULL) {
        printf("Output failed, file not found.\n");
        return;
    }
    
    // loop prints each node's contents into the outputFile
    while (tempNode != NULL) {
        fprintf(outputFile, "%d,%s,%s\n", tempNode -> id, tempNode -> user, tempNode -> text);
        tempNode = tempNode -> next; // update tempNode to point to the next node/tweet
    }
    printf("Output successful!\n");
    fclose(outputFile); 
    free(fileName);
}