#include "headerA3.h"
#include "helperA3.h"

// function frees a linked list
void cleanList(tweet *tweetList) {
    tweet *head = tweetList;
    tweet *tempNode = head;

    // loop frees the first node of the list and makes the two pointers point to the new "head" node
    while (head != NULL) { // it iterates that process till head is NULL (0 nodes/tweets remaining)
        head = head -> next;
        free(tempNode);
        tempNode = head;
    }
}

// function gets rid of any extra input after a string until it reaches a new line character
void removeExtraInput(char *string, FILE *sourceFile) {
    char inputEnd;
    
    // this branch checks if there is no '\n' new line character in the string
    if (!strchr(string, '\n')) { // strchr function source: stackoverflow: https://stackoverflow.com/questions/30388101/how-to-remove-extra-characters-input-from-fgets-in-c
        inputEnd = fgetc(sourceFile); 
        while (inputEnd != '\n') { // loop iterates till a new line character is scanned
            inputEnd = fgetc(sourceFile); 
        }
    }
    // if there was initially a '\n' in string, this function has no effect

}

// function gives an error of empty string and reprompts user for input
void lengthZeroError (char *string, FILE *sourceFile, int maxInput) {

    // branch checks for empty string or string of only a new line (effect of fgets)
    if ((strlen(string) == 1 && string[0] == '\n') || strlen(string) == 0) {
        // loop iterates till string is not empty or/and string has 1 character thats not a new line
        while((strlen(string) == 1 && string[0] == '\n') || strlen (string) == 0) {
            printf("\nInput must have at least one character.\n"); // error message
            if (maxInput == MAX_TEXT) { // branch enter prompt message depending on max length of string (user = 51, text = 141)
                printf("Enter tweet: ");
            }
            else if (maxInput == MAX_USER) {
                printf("Enter username: ");
            }
            fgets(string, maxInput, sourceFile); // new string value
        }
    }

}