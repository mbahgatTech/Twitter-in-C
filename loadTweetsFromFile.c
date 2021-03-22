#include "headerA3.h"
#include "helperA3.h"

void loadTweetsFromFile(tweet ** tweetList) {
    FILE *inputFile = NULL; 
    char *fileName = malloc(sizeof(char) * 100); // initial memory allocated for the file name
    tweet *newTweet = malloc(sizeof(tweet)); // allocating enough memory for a new node
    int i;
    
    // prompt user for name of file
    printf("Enter a filename to load from: ");
    scanf("%s",  fileName);
    fileName = realloc(fileName, strlen(fileName) + 1); // reallocate memory enough for the string and NULL character
    inputFile = fopen(fileName, "r"); // attempts to open file

    // error message and return to main function if opening file failed
    if (inputFile == NULL) {
        printf("Loading failed, file not found.\n");
        return;
    }

    // loop iterates till end of file is reached
    while(!feof(inputFile)) {
        // attempts to scan an integer from the file, if failed it exits loop
        if(fscanf(inputFile, "%d", &newTweet -> id) < 1) {
            break;
        }

        i = 1;
        fgetc(inputFile); // gets rid of the comma
        newTweet -> user[0] = fgetc(inputFile);  
        
        // loop scans characters into user element of node until a comma is found
        while(newTweet -> user[i - 1] != ',') {
            newTweet -> user[i] = fgetc(inputFile);
            i++;
        }
        newTweet -> user[i - 1] = '\0'; // replaces comma with NULL

        fgets(newTweet -> text, MAX_TEXT, inputFile); // rest of the line is the tweet's text element
        // loop iterates till a non space/non comma character is found
        i = strlen(newTweet -> text); // starts from the end of string
        while (newTweet -> text[i - 1] == ',' || isspace(newTweet -> text[i - 1])) {
            i--;
        }

        newTweet -> text[i] = '\0'; // replaces space/comma after the tweet with NULL 
        newTweet -> next = NULL; // next pointer is NULL because node is to be added at the end of the list
        addNodeToList (tweetList, newTweet); 
        //reset new tweet elements 
        newTweet -> id = 0;
        strcpy(newTweet -> user, "");
        strcpy(newTweet -> text, "");
    }

    printf("Tweets imported!\n");
    fclose(inputFile);
    free(newTweet);
    free(fileName);
}