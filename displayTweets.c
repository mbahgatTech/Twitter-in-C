#include "headerA3.h"
#include "helperA3.h"

void displayTweets(tweet * tweetList) {
    tweet *tempNode = tweetList;
    
    // branch checks for empty list
    if (tweetList == NULL) {
        printf("Tweet list is empty. Append tweets using option 1 or 7 and try again.\n"); // error message of empty list
    }

    // loop prints all contents of each node
    while (tempNode != NULL) {
        printf("%d: Created by %s: %s\n", tempNode -> id, tempNode -> user, tempNode -> text);
        tempNode = tempNode -> next; // tempNode is updated and loop condition is re checked
    }
}