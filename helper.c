#include "headerA3.h"

void addNodeToList(tweet**tweetList,tweet * node) {
    tweet *tempNode = *tweetList;
    
    if (*tweetList == NULL) {
        *tweetList = malloc(sizeof(tweet));
        (**tweetList).id = node -> id;
        strcpy((**tweetList).user, node -> user);
        strcpy((**tweetList).text, node -> text);
        (**tweetList).next = node -> next;
    }
    else {
        
        while (tempNode -> next != NULL) {
            tempNode = tempNode -> next;
        }
    
        tempNode -> next = malloc(sizeof(tweet));
        tempNode = tempNode -> next;
        tempNode -> id = node -> id;
        strcpy(tempNode -> user, node -> user);
        strcpy(tempNode -> text, node -> text);
        tempNode -> next = node -> next;
    }

}