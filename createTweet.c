#include"headerA3.h"
#include "helperA3.h"

tweet * createTweet( tweet * tweetList) {
    tweet *newTweet = malloc(sizeof(tweet)); // allocating memory for one new node
    tweet *tempNode;
    int i = 0;

    // prompts user to enter user element for newTweet
    printf("Enter username: ");
    fgets(newTweet -> user, MAX_USER, stdin);
    lengthZeroError(newTweet -> user, stdin, MAX_USER); // call with MAX_USER for right print
    removeExtraInput(newTweet -> user, stdin); // removes extra input after max length
    if (newTweet -> user[strlen(newTweet -> user) -1] == '\n') { // branch gets rid of new line if it exists
        newTweet -> user[strlen(newTweet -> user) -1] = '\0';
    }
    
    // prompts user for to enter text element for the tweet
    printf("Enter tweet: ");
    fgets(newTweet -> text, MAX_TEXT, stdin);
    lengthZeroError(newTweet -> text, stdin, MAX_TEXT); // call with MAX_TEXT for right print
    removeExtraInput(newTweet -> text, stdin); // removes extra input after max length
    if (newTweet -> text[strlen(newTweet -> text) -1] == '\n') { // branch gets rid of new line if it exists
        newTweet -> text[strlen(newTweet -> text) -1] = '\0';
    }
    
    
    newTweet -> id = 0;
    for (i = 0; i < strlen(newTweet -> user); i++) { // iterates through each character in user string element in newTweet
        newTweet -> id += (int)(newTweet -> user[i]); // adds ASCII value to the id element
    }
    newTweet -> id += strlen(newTweet -> text); // adds length of tweet text to the id
    
    tempNode = tweetList; // point tempNode to head of list
    while (tempNode != NULL) { // iterates til tempNode reaches end of list
        if (tempNode -> id == newTweet -> id) { // branch checks if the newTweet id matches current node id
            newTweet -> id += (rand() % 999); // adds randoom number to the id
            tempNode = tweetList; // resets tempNode to the beginning of the list to recheck with the new id of newTweet
        }
        else { 
            tempNode = tempNode -> next; // updates tempNode to next node if 
        }
    }
    printf("Your computer generated userid is %d.\n", newTweet -> id); 

    newTweet -> next = NULL; // sets next pointer to NULL (end of list)
    addNodeToList(&tweetList, newTweet); // adds the node to end of list
    free(newTweet); 

    return tweetList;
}