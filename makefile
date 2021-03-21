a3: mainA3.c createTweet.c displayTweets.c searchTweetsByKeyword.c countStopWords.c deleteTweet.c saveTweetsToFile.c helper.c loadTweetsFromFile.c
	gcc -Wall -std=c99 mainA3.c createTweet.c displayTweets.c searchTweetsByKeyword.c countStopWords.c deleteTweet.c saveTweetsToFile.c helper.c loadTweetsFromFile.c
clean:
	rm a3
