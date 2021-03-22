#include "headerA3.h"
#include "helperA3.h"

// function copies contents of a node to the end of a list
void addNodeToList(tweet**tweetList, tweet * node) {
    tweet *tempNode = *tweetList; // this node is used to move till the end of a list and add a new node
    
    // branch checks if the list is empty
    if (*tweetList == NULL) { 
        *tweetList = malloc(sizeof(tweet)); // enough memory for a single node list
        //contents of node are copied to *tweetList
        (**tweetList).id = node -> id;
        strcpy((**tweetList).user, node -> user);
        strcpy((**tweetList).text, node -> text);
        (**tweetList).next = node -> next;
    }
    // else entered if list had existing node(s)
    else {
        // loop makes tempNode point to last element of the list
        while (tempNode -> next != NULL) {
            tempNode = tempNode -> next;
        }
    
        tempNode -> next = malloc(sizeof(tweet)); // allocates enough memory for a new node
        tempNode = tempNode -> next; 
        //contents of node are copied to the last node of the list (tempNode)
        tempNode -> id = node -> id;
        strcpy(tempNode -> user, node -> user);
        strcpy(tempNode -> text, node -> text);
        tempNode -> next = node -> next;
    }

}
