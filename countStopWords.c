#include "headerA3.h"

void countStopWords(tweet * tweetList) {
    int stopCount = 0, tweetCount = 0;
    int i,j,k;
    bool similarity = 0;
    tweet *head = tweetList;
    tweet *tempNode;
    char stopWords[25][5] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its",
    "of","on","that","the","to","was","were","will","with"};
    
    tempNode = head;
    while (tempNode != NULL) {
        for (i = 0; i < 25; i++) {
            for (k = 0; k < strlen(tempNode -> text); k++) {
                if (tempNode -> text[k] == stopWords[i][0]) {
                    similarity = 1;
                    if (isspace(tempNode -> text[k - 1]) || k == 0) {
                        for (j = 1; j < strlen(stopWords[i]); j++) {
                            if (tempNode -> text[k + j] != stopWords[i][j]){
                                similarity = 0;
                            }                        
                        }
                        if (similarity == 1) {
                            if(isspace(tempNode -> text[j + k])) {
                                stopCount++;
                                similarity = 0;
                            }
                        
                        }    
                    } 
                } 
            }
        }

        tempNode = tempNode -> next;
        tweetCount++;
    }
    printf("Across %d tweets, %d stop words were found.\n", tweetCount, stopCount);
    
}
