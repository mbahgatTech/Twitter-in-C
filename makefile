CFLAGS = -Wall -std=c99
FILES = mainA3.c createTweet.c displayTweets.c searchTweetsByKeyword.c countStopWords.c deleteTweet.c saveTweetsToFile.c helper.c loadTweetsFromFile.c addNodeToList.c

twitter: $(FILES)
	gcc $(CFLAGS) $(FILES) -o twitter
clean:
	rm twitter
