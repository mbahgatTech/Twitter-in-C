CFLAGS = -Wall -std=c99
FILES = mainA3.c createTweet.c displayTweets.c searchTweetsByKeyword.c countStopWords.c deleteTweet.c saveTweetsToFile.c helper.c loadTweetsFromFile.c addNodeToList.c

a3: $(FILES)
	gcc $(CFLAGS) $(FILES) -o a3
clean:
	rm a3
