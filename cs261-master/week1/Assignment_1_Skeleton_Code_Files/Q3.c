/* CS261- Assignment 1 - Q.3*/
/* Name: Alex Cheng
 * Date: 7/11/2018
 * Solution description: This program converts strings into lower camel case by
 * first turning them into words separated by underscores then converting them
 * to camel case.
 */

#include <stdio.h>
#include <stdlib.h>

int MAX_CHAR = 100;
char toUpperCase(char ch) {
  /*Convert ch to upper case, assuming it is in lower case currently*/
  return ch - 32;
}

char toLowerCase(char ch) {
  /*Convert ch to lower case, assuming it is in upper case currently*/
  return ch + 32;
}

int stringLength(char s[]) { /*Return the length of the string*/
  int len = 0;
  while (s[len] != '\0') {
    len++;
  }
  return len;
}

int isalpha(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
    return 1;
  }
  return 0;
}

/* validStr:
 * A helper function that validates input strings. Returns 1 if valid.
 */
int validStr(char *word) {
  int isWord = 0;
  int i = 0;
  int wordCnt = 0;
  while (word[i] != '\0') {
    /* if we get an underscore or we're at the last char and we have a word then
     * increment word count */
    if ((word[i] == '_' || word[i + 1] == '\0') && isWord == 1) {
      wordCnt++;
      isWord = 0; // reset isWord
    } else {
      isWord = 1; // an alpha char marks the beginning of a word
    }
    i++;
  }
  /* must have two or more words to be valid */
  if (wordCnt >= 2)
    return 1;
  return 0;
}

/* cleanStr:
 * A helper function that modifies the input string. Strings will be in
 * underscore format. e.g. "random_word"
 */
void cleanStr(char *word) { /*convert to underscore words*/
  int haveWord = 0;
  int i = 0;    // count for original word
  int j = 0;    // count for new word
  int trim = 0; // number of chars to trim off the new word
  while (word[i] != '\0') {
    if (isalpha(word[i]) != 1) {
      // if we have a word and met a non-alpha character, insert an underscore
      if (haveWord == 1) {
        word[j] = '_';
        haveWord = 0; // reset haveWord
        j++;
      } else {
        trim++;
      }
    } else {
      if (word[i] >= 'A' && word[i] <= 'Z') {
        word[j] = toLowerCase(word[i]);
      } else {
        word[j] = word[i];
      }
      haveWord = 1;
      j++;
    }
    i++;
  }
  word[stringLength(word) - trim] = '\0';
}

/* camelCase:
 * This function will convert strings from underscore format to lower camelCase.
 * e.g. randomWord.
 */
void camelCase(char *word) { /*Convert to camelCase*/
  int i = 0;
  int j = 0;
  int trim = 0;
  while (word[i] != '\0') {
    /* if we get an underscore and we're not on the last character, capitalize
     * the letter. This is the start of a new word */
    if (word[i] == '_' && word[i + 1] != '\0') {
      word[j] = toUpperCase(word[i + 1]); // replace the underscore with the
                                          // next letter capitalized
      i += 2; // skip the next letter since we already used it
      trim++; // we need to trim off a char due to the underscore
    } else {
      /* if we have an alpha char, put the char in its respective place*/
      if (word[i] != '_') {
        word[j] = word[i];
        /* if we have an underscore that's also the last char, we have to trim
         * it off later */
      } else {
        trim++;
      }
      i++; // go to the next char to check
    }
    j++; // go to the next position to insert a char
  }
  /* trim off the excess chars due to underscores */
  word[stringLength(word) - trim] = '\0';
}

int main() {
  char word[MAX_CHAR];
  /*Read the string from the keyboard*/
  /* set delimiter of word to \n to accomodate spaces
        https://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character
  */
  scanf("%[^\n]s*c", word);
  /* Clean the string */
  cleanStr(word);

  /* Check if string is valid */
  if (validStr(word) != 1) {
    printf("invalid input string\n");
    return 0;
  }

  /*Call camelCase*/
  camelCase(word);

  /*Print the new string*/
  printf("%s\n", word);

  return 0;
}
