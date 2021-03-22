#include "headerA3.h"
#include "helperA3.h"

void deleteTweet(tweet ** tweetList) {
    tweet *head = *tweetList;
    tweet *tempNode, *temp2;
    int nodes = 0, i = 0;
    int userChoice;
    int deletedTweet;
    
    tempNode = head;
    while (tempNode != NULL) { // loop counts the amount nodes in the list
        nodes++;
        tempNode = tempNode -> next; 
    }
    // prompts user for node to be deleted
    printf("Currently there are %d tweets\n\n", nodes);
    printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", nodes);
    scanf("%d", &userChoice);
    
    if (userChoice == 1) { // first node branch
        tempNode = head;
        deletedTweet = tempNode -> id; // assigns deletedTweet to the id of the head node
        head = head -> next; // new head to the list is the second node
        free(tempNode); // old head free'd
        *tweetList = head; // original list updated to point to the new head
    }

    else if (userChoice == 2) { // second node branch
        tempNode = head -> next; // tempNode points to second node
        deletedTweet = tempNode -> id; // deletedTweet assigned the id of second node
        head -> next = tempNode -> next; // replaces pointer to second node to point to the third 
        free(tempNode); // old second node free'd
    }
    
    else {  // other nodes
        tempNode = head; 
        // loop iterates till tempNode points to tweet before chosen tweet. temp2 points to chosen tweet
        for (i = 1; i < userChoice - 1; i++) {
            tempNode = tempNode -> next; 
            temp2 = tempNode -> next;
        }

        deletedTweet = temp2 -> id; // assigns deletedTweet the id of temp2
        tempNode -> next = temp2 -> next; // updates next pointer of tempNode to next pointer of temp2
        free(temp2); // temp2 is free'd
    }
    printf("\nTweet %d deleted. There are now %d tweets left.\n\n", deletedTweet, nodes - 1); // prints the id of tweet deleted and updated node count
}