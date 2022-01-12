# Twitter in C
A command line based social media program written in C.
## Project Information
- Author: Mazen Bahgat
- Last Revision Date: March 21st 2021 
## Compile & Run Information
- Download the repository using the clone function on Gitub.
- Open a terminal window on your PC and change directory to the downloaded project using "cd <dir name>".
- Type "make" to compile the project.
- Run the program using "./twitter" command in your terminal.

## Components Information
The submission consists 13 files: 
- makefile: responsible for compiling the files into "twitter" program.
- helper.c: Consists of 3 functions
    - clearList -> It frees every node in a linked list
    - removeExtraInput -> It  gets rid of any extra input after a string until it reaches a new line character
    - lengthZeroError -> It gives an error if string is empty and reprompts the user for input
    - addNodeToList.c -> It consists of one function that adds a node to the end of a list (both are parameters)
    - mainA3.c -> It has the main function of the program. Displays the menu and gets user choice to call appropriate functions.

The rest are all files consisting of one function each, each file has the name of the function occupying it and each function resembles
one choice in the menu from the main function.
- createTweet.c   -> creates a new tweet from user input
- displayTweets.c   -> prints out all the tweets
- searchTweetsByKeyword.c  -> prints tweets that have a user specified keyword
- countStopWords.c  -> counts pre-specified stopwords
- deleteTweet.c  -> deletes a tweets of user's choice
- saveTweetsToFile.c  -> prints tweets to a file
- loadTweetsFromFile.c -> scans tweets from a file

## Limitations Information:
    In functions loadTweetsFromFile & saveTweetsToFile, the initial memory allocation for the file name string is enough 
    for 99 chars and a NULL character. 100 characters are more than enough for a file name but given the odd case of a 
    100 character name or more, fgets() will assign only the 99 possible characters to the string which will result in failure 
    to open the file and a return to the main function with an error message.


## Future Improvements Information:
    One improvement that can be done is dyncamically allocating each string in array of strings "stopWords" in "countStopWords" function, 
    currently memory is statically allocated to 5 bytes per string when there are some stop words that dont occupy all of the 5 bytes.
