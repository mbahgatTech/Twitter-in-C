Submission Information:
    Student Name: Mazen Bahgat
    Student username: mbahgat
    Student ID: 1157821
    Due Date: March 21st 2021
    Last Revision Date: March 21st 2021
    Course: CIS*2500

Compile & Run Information:
    A makefile is included in the submission. To compile the program, 
    you must have all the submitted files in your repository and 
    simply compile by typing "make" (without quotes) through 
    command-line  and it will create the target executable "a3".

    To run the program type "./a3" (without quotes) into 
    the command-line. No further command-line arguments are needed
    to run a3.

Completed Components Information:
The submission consists 13 files: 
    1) makefile: responsible for compiling the files into "a3" program.
    2) helper.c: Consists of 3 functions
        1. cleaList -> It frees every node in a linked list
        2. removeExtraInput -> It  gets rid of any extra input after a string until it reaches a new line character
        3. lengthZeroError -> It gives an error if string is empty and reprompts the user for input
    3) addNodeToList.c -> It consists of one function that adds a node to the end of a list (both are parameters)
    4) mainA3.c -> It has the main function of the program. Displays the menu and gets user choice to call appropriate functions.
    The rest are all files consisting of one function each, each file has the name of the function occupying it and each function resembles
    one choice in the menu from the main function.
        1. createTweet.c   -> creates a new tweet from user input
        2. displayTweets.c   -> prints out all the tweets
        3. searchTweetsByKeyword.c  -> prints tweets that have a user specified keyword
        4. countStopWords.c  -> counts pre-specified stopwords
        5. deleteTweet.c  -> deletes a tweets of user's choice
        6. saveTweetsToFile.c  -> prints tweets to a file
        7. loadTweetsFromFile.c -> scans tweets from a file

Limitations Information:
    In functions loadTweetsFromFile & saveTweetsToFile, the initial memory allocation for the file name string is enough 
    for 99 chars and a NULL character. 100 characters are more than enough for a file name but given the odd case of a 
    100 character name or more, fgets() will assign only the 99 possible characters to the string which will result in failure 
    to open the file and a return to the main function with an error message.


Future Improvements Information:
    One improvement that can be done is dyncamically allocating each string in array of strings "stopWords" in "countStopWords" function, 
    currently memory is statically allocated to 5 bytes per string when there are some stop words that dont occupy all of the 5 bytes.
