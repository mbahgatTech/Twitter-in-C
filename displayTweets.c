#include "headerA3.h"

void displayTweets(tweet * tweetList) {
    tweet *tempNode = tweetList;
    while (tempNode != NULL) {
        printf("%d: Created by %s: %s\n", tempNode -> id, tempNode -> user, tempNode -> text);
        tempNode = tempNode -> next;
    }
}