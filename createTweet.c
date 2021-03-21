#include"headerA3.h"

tweet * createTweet( tweet * tweetList) {
    tweet *newTweet = malloc(sizeof(tweet));
    tweet *tempNode;
    int i = 0;

    printf("Enter username: ");
    fgets(newTweet -> user, 51, stdin);
    newTweet -> user[strlen(newTweet -> user) -1] = '\0';
    
    printf("Enter tweet: ");
    fgets(newTweet -> text, 141, stdin);
    newTweet -> text[strlen(newTweet -> text) - 1] = '\0';
    
    newTweet -> id = 0;
    for (i = 0; i < strlen(newTweet -> user); i++) {
        newTweet -> id += (int)(newTweet -> user[i]);
    }
    newTweet -> id += strlen(newTweet -> text);
    
    tempNode = tweetList;
    while (tempNode != NULL) {
        if (tempNode -> id == newTweet -> id) {
            newTweet -> id += (rand() % 999);
            tempNode = tweetList;
        }
        tempNode = tempNode -> next;
    }
    printf("Your computer generated userid is %d.\n", newTweet -> id);
    
    addNodeToList(&tweetList, newTweet);
    free(newTweet);
    return tweetList;
}