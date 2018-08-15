#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  char src[255] = "hello";
  char dest[255] = "hegggllo";
  strcpy(dest, src);
  printf("%s", dest);
}