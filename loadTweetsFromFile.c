#include "headerA3.h"

void loadTweetsFromFile(tweet ** tweetList) {
    FILE *inputFile = NULL;
    char *fileName = malloc(sizeof(char) * 100);
    tweet *newTweet = malloc(sizeof(tweet));
    int i;
    
    printf("Enter a filename to load from: ");
    scanf("%s",  fileName);
    fileName = realloc(fileName, strlen(fileName) + 1);
    inputFile = fopen(fileName, "r");

    if (inputFile == NULL) {
        printf("Loading failed, file not found.\n");
        exit(-1);
    }

    while(!feof(inputFile)) {
        if(fscanf(inputFile, "%d", &newTweet -> id) < 1) {
            printf("Tweets imported!\n");
            return;
        }
        i = 1;
        fgetc(inputFile);
        newTweet -> user[0] = fgetc(inputFile);
        
        while(newTweet -> user[i - 1] != ',') {
            newTweet -> user[i] = fgetc(inputFile);
            i++;
        }
        newTweet -> user[i - 1] = '\0';

        fgets(newTweet -> text, 141, inputFile);
        i = strlen(newTweet -> text);
        while (newTweet -> text[i - 1] == ',' || isspace(newTweet -> text[i - 1])) {
            i--;
        }

        newTweet -> text[i] = '\0'; 
        newTweet -> next = NULL;
        addNodeToList (tweetList, newTweet);
        newTweet -> id = 0;
        strcpy(newTweet -> user, "");
        strcpy(newTweet -> text, "");
    }

    printf("Tweets imported!\n");
}