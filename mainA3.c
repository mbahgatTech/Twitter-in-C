#include "headerA3.h"

int main() {
    int userChoice;
    tweet *tweetList = NULL;
    
    while (userChoice != 8) {
        printf("1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are \"stop words\"\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file\n");
        printf("7. Load tweets from a file\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        getchar();
        
        switch (userChoice) {
            case 1:
                tweetList = createTweet(tweetList); 
                break;
            case 2:
                displayTweets(tweetList);
                break;     
            case 3: 
                searchTweetsByKeyword(tweetList);
                break;
            case 4:
                countStopWords(tweetList);  
                break;
            case 5:
                deleteTweet(&tweetList);
                break;  
            case 6:
                saveTweetsToFile(tweetList);
                break;
            case 7:
                loadTweetsFromFile(&tweetList);
                break;
        }   
    }
    return 0;
}