#include "headerA3.h"
#include "helperA3.h"

void countStopWords(tweet * tweetList) {
    int stopCount = 0, tweetCount = 0;
    int i,j,k;
    bool similarity = 0;
    tweet *head = tweetList;
    tweet *tempNode;
    char stopWords[25][5] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its",
    "of","on","that","the","to","was","were","will","with"}; // initializes all 25 stopWords to the array
    
    tempNode = head;
    while (tempNode != NULL) { // loop iterates till tempNode reaches end of list
        for (i = 0; i < 25; i++) { // loop iterates for each stopWord
            for (k = 0; k < strlen(tempNode -> text); k++) { // iterates for length tweet text times
                //branch enters if a character in text matches first character in stop word i
                if (tempNode -> text[k] == stopWords[i][0]) {
                    similarity = 1; // similarity updated to TRUE
                    if (isspace(tempNode -> text[k - 1]) || k == 0) { // branch checks if the character is a start of word or text
                        for (j = 1; j < strlen(stopWords[i]); j++) { // iterates length current stopWord - 1 times
                            if (tempNode -> text[k + j] != stopWords[i][j]) { // branch sets similarity to FALSE if and characters same length from initial char dont match 
                                similarity = 0;
                            }                        
                        }
                        
                        if (similarity == 1) { 
                            if(isspace(tempNode -> text[j + k])) { // branch increments stopCount when there is a space in the text after words are matched (same length check)
                                stopCount++;
                            }
                        }    
                    } 
                    similarity = 0; // resets to check next char in text
                } 
            }
        }

        tempNode = tempNode -> next; // updates pointer to next node
        tweetCount++; // increments tweet/node count
    }
    printf("Across %d tweets, %d stop words were found.\n", tweetCount, stopCount);
    
}
