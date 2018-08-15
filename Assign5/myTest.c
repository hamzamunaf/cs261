#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>

int main() {
   struct HashMap *map = hashMapNew(10);
   HashLink links[] = {{.key = "a", .value = 0, .next = NULL},
                       {.key = "c", .value = 1, .next = NULL},
                       {.key = "d", .value = 2, .next = NULL},
                       {.key = "f", .value = 3, .next = NULL},
                       {.key = "g", .value = 4, .next = NULL}};
   hashMapPut(map, links[0].key, links[0].value);
   hashMapPut(map, links[1].key, links[1].value);
   hashMapPut(map, links[2].key, links[2].value);
   hashMapPut(map, links[3].key, links[3].value);
   hashMapPut(map, links[4].key, links[4].value);
   hashMapPrint(map);
   printf("newline\n");
   hashMapRemove(map, links[0].key);
   hashMapRemove(map, links[1].key);
      hashMapRemove(map, links[2].key);
      hashMapRemove(map, links[3].key);
   hashMapPrint(map);
 }
