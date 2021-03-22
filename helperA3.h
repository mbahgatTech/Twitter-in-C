#include <stdbool.h>
#include <ctype.h>

#define MAX_USER 51 // for maximum characters in user string
#define MAX_TEXT 141 // for maximum characters in text string

void cleanList(tweet *tweetList);

void removeExtraInput(char *string, FILE *sourceFile);

void lengthZeroError (char *string, FILE *sourceFile, int maxInput);