#include "headerA3.h"
#include "helperA3.h"

int main() {
    int userChoice;
    tweet *tweetList = NULL; // initialize tweet pointer to NULL (this pointer will point to the linked list of tweets)
    
    // loop iterates until user enters choice 8 (8 results in exiting loop)
    while (userChoice != 8) {
        // menu
        printf("1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are \"stop words\"\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file\n");
        printf("7. Load tweets from a file\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &userChoice); //choice input
        getchar(); // gets rid of '\n'
        
        // based on the userChoice input switch function calls the appropriate function 
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
            case 8:
                break;
            default: // if userChoice isn't between 1 and 8, an error is printed and loop iterates again
                printf("Please enter a valid choice between 1 and 8\n");
                userChoice = 0; // valid value for while loop iteration
        }   
    }
    return 0; //end of program
}