#include "headerA3.h"

void deleteTweet(tweet ** tweetList) {
    tweet *head = *tweetList;
    tweet *tempNode, *temp2;
    int nodes = 0, i = 0;
    int userChoice;
    
    tempNode = head;
    while (tempNode != NULL) {
        nodes++;
        tempNode = tempNode -> next;
    }
    printf("Currently there are %d tweets\n", nodes);
    printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", nodes);
    scanf("%d", &userChoice);

    tempNode = head;
    for (i = 0; i < userChoice - 2; i++) {
        tempNode = tempNode -> next;
        temp2 = tempNode -> next;
    }

    tempNode ->next = temp2 -> next;
    free(temp2);
}