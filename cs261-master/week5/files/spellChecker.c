#include "hashMap.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char *nextWord(FILE *file) {
  int maxLength = 16;
  int length = 0;
  char *word = malloc(sizeof(char) * maxLength);
  while (1) {
    char c = fgetc(file);
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') || c == '\'') {
      if (length + 1 >= maxLength) {
        maxLength *= 2;
        word = realloc(word, maxLength);
      }
      word[length] = c;
      length++;
    } else if (length > 0 || c == EOF) {
      break;
    }
  }
  if (length == 0) {
    free(word);
    return NULL;
  }
  word[length] = '\0';
  return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE *file, HashMap *map) {
  // FIXME: implement
  char *word = nextWord(file);
  while (word != 0) {
    hashMapPut(map, word, 1);
    free(word);
    word = nextWord(file);
  }
}

int levenshtein(char *s, char *t) {
  int i, j, n, m;
  n = strlen(s);
  m = strlen(t);
  int matrix[m + 1][n + 1];
  matrix[0][0] = 0;
  for (i = 1; i <= m; i++)
    matrix[i][0] = matrix[i - 1][0] + 1;
  for (j = 1; j <= n; j++)
    matrix[0][j] = matrix[0][j - 1] + 1;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      int a = matrix[i - 1][j] + 1;
      int b = matrix[i][j - 1] + 1;
      int c = matrix[i - 1][j - 1] + (s[j - 1] == t[i - 1] ? 0 : 1);
      if (a < b && a < c)
        matrix[i][j] = a;
      else if (b < a && b < c)
        matrix[i][j] = b;
      else
        matrix[i][j] = c;
    }

  return (matrix[m][n]);
}

/**
 * Prints the concordance of the given file and performance information.
 * Uses the file input1.txt by default or a file name specified as a command
 * line argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char **argv) {
  // FIXME: implement
  HashMap *map = hashMapNew(1000);

  FILE *file = fopen("dictionary.txt", "r");
  clock_t timer = clock();
  loadDictionary(file, map);
  timer = clock() - timer;
  printf("Dictionary loaded in %f seconds\n",
         (float)timer / (float)CLOCKS_PER_SEC);
  fclose(file);

  char inputBuffer[256];
  int quit = 0;

  do {
    printf("Enter a word or \"quit\" to quit: ");
    scanf("%s", inputBuffer);

    // Implement the spell checker code here..

    // copy word to display later
    char original[strlen(inputBuffer)];
    strcpy(original, inputBuffer);

    // convert to all lowercase
    for (int i = 0; inputBuffer[i]; i++) {
      inputBuffer[i] = tolower(inputBuffer[i]);
    }
    if (strcmp(inputBuffer, "quit") == 0) {
      quit = 1;
      break;
    }
    int found = 0;
    int distances[5] = {0};
    char *words[5];
    for (int i = 0; i < 5; i++) {
      words[i] = malloc(sizeof(char) * 256);
      assert(words[i] != 0);
    }
    // loop through hashmap buckets
    for (int i = 0; i < hashMapCapacity(map); i++) {
      // loop through links in each bucket
      HashLink *temp = map->table[i];
      if (temp != 0) {
        while (temp != 0) {
          if (strcmp(temp->key, inputBuffer) == 0) {
            printf("The inputted word \"%s\" is spelled correctly\n", original);
            found = 1;
          }

          else {
            int lev = levenshtein(temp->key, inputBuffer);
            // fill array first
            if (!distances[4])
              for (int i = 0; i < 5; i++) {
                if (distances[i] == 0) {
                  distances[i] = lev;
                  strcpy(words[i], temp->key);
                }
              }
            // find the max of array and replace the word if its distance is
            // greater than the lev we calculated
            int max = distances[0];
            int maxIdx = 0;
            for (int i = 0; i < 5; i++) {
              if (distances[i] > max) {
                max = distances[i];
                maxIdx = i;
              }
            }
            if (max > lev) {
              distances[maxIdx] = lev;
              strcpy(words[maxIdx], temp->key);
            }
          }
          temp = temp->next;
        }

      } else if (found)
        break;
    }

    if (!found) {
      // no matches, print out close words
      printf("The inputted word \"%s\" is spelled incorrectly.\n", original);
      printf("Did you mean...?\n");
      for (int i = 0; i < 5; i++) {
        printf("%s\n", words[i]);
      }
    }

    for (int i = 0; i < 5; i++) {
      free(words[i]);
    }

  } while (!quit);

  hashMapDelete(map);
  return 0;
}