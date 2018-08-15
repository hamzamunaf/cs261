/*
 * CS 261 Data Structures
 * Assignment 5
 * Name:
 * Date:
 */

#include "hashMap.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashFunction1(const char *key) {
  int r = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    r += key[i];
  }
  return r;
}

int hashFunction2(const char *key) {
  int r = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    r += (i + 1) * key[i];
  }
  return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink *hashLinkNew(const char *key, int value, HashLink *next) {
  HashLink *link = malloc(sizeof(HashLink));
  link->key = malloc(sizeof(char) * (strlen(key) + 1));
  strcpy(link->key, key);
  link->value = value;
  link->next = next;
  return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink *link) {
  free(link->key);
  free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap *map, int capacity) {
  map->capacity = capacity;
  map->size = 0;
  map->table = malloc(sizeof(HashLink *) * capacity);
  for (int i = 0; i < capacity; i++) {
    map->table[i] = NULL;
  }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap *map) {
  // FIXME: implement
  assert(map != 0);
  for (int i = 0; i < map->capacity; i++) {
    struct HashLink *temp = map->table[i];
    while (temp != 0) {
      struct HashLink *link = temp;
      temp = temp->next;
      hashLinkDelete(link);
    }
    free(temp);
  }
  free(map->table);
  map->size = 0;
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap *hashMapNew(int capacity) {
  HashMap *map = malloc(sizeof(HashMap));
  hashMapInit(map, capacity);
  return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap *map) {
  hashMapCleanUp(map);
  free(map);
}

/**
 * Returns a pointer to the value of the link with the given key  and skip
 * traversing as well. Returns NULL if no link with that key is in the table.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 *
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int *hashMapGet(HashMap *map, const char *key) {
  // FIXME: implement
  assert(map != 0);
  int index = HASH_FUNCTION(key) % map->capacity;
  if (index < 0)
    index += map->capacity;

  struct HashLink *temp = map->table[index];

  while (temp != 0) {
    if (strcmp(temp->key, key) == 0)
      return &temp->value;
    temp = temp->next;
  }
  return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given
 * capacity (double of the old capacity). After allocating the new table,
 * all of the links need to rehashed into it because the capacity has changed.
 *
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 *
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap *map, int capacity) {
  // FIXME: implement
  assert(map != 0);
  int oldCap = map->capacity;
  struct HashLink **oldTable = map->table;
  hashMapInit(map, 2 * oldCap);
  for (int i = 0; i < oldCap; i++) {
    struct HashLink *temp = oldTable[i];
    while (temp != 0) {
      struct HashLink *rmLnk = temp;
      hashMapPut(map, temp->key, temp->value);
      temp = temp->next;
      hashLinkDelete(rmLnk);
    }
  }
  free(oldTable);
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value and skip traversing.
 * Otherwise, it will create a new link with the given key and value and add it
 * to the table bucket's linked list. You can use hashLinkNew to create the
 * link.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket.
 *
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap *map, const char *key, int value) {
  // FIXME: implement
  assert(map != 0);
  if (hashMapTableLoad(map) >= MAX_TABLE_LOAD)
    resizeTable(map, 2 * map->capacity);
  int index = HASH_FUNCTION(key) % map->capacity;
  if (index < 0)
    index += map->capacity;
  struct HashLink *temp = map->table[index];

  // check if key is already in map
  while (temp != 0) {
    if (strcmp(temp->key, key) == 0) {
      // key is already in map, update value
      temp->value = value;
      return;
    }
    temp = temp->next;
  }

  // place new link at the front of the table[index]
  struct HashLink *newLnk = hashLinkNew(key, value, map->table[index]);
  map->table[index] = newLnk;
  map->size++;
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap *map, const char *key) {
  // FIXME: implement
  assert(map != 0);
  if (!hashMapContainsKey(map, key))
    return;
  int index = HASH_FUNCTION(key) % map->capacity;
  if (index < 0)
    index += map->capacity;
  struct HashLink *temp = map->table[index];
  struct HashLink *prev = 0;

  if (temp == 0)
    return;
  while (temp != 0) {
    if (strcmp(temp->key, key) == 0) {
      if (prev == 0) {
        map->table[index] = temp->next;
      } else {
        prev->next = temp->next;
      }
      hashLinkDelete(temp);
      temp = 0;
      map->size--;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 *
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 *
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap *map, const char *key) {
  // FIXME: implement
  assert(map != 0);
  int index = HASH_FUNCTION(key) % map->capacity;
  if (index < 0)
    index += map->capacity;
  struct HashLink *temp = map->table[index];
  while (temp != 0) {
    if (strcmp(temp->key, key) == 0) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap *map) {
  // FIXME: implement
  assert(map != 0);
  return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap *map) {
  // FIXME: implement
  assert(map != 0);
  return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap *map) {
  // FIXME: implement
  int num = map->capacity;
  for (int i = 0; i < map->capacity; i++) {
    if (map->table[i] != 0) {
      num--;
    }
  }
  return num;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap *map) {
  // FIXME: implement
  float links = (float)map->size;
  float buckets = (float)map->capacity;
  return links / buckets;
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap *map) {
  // FIXME: implement
  for (int i = 0; i < map->capacity; i++) {
    struct HashLink *link = map->table[i];
    printf("Bucket %d -> ", i);
    while (link != 0) {
      printf("(%s, %d) -> ", link->key, link->value);
      link = link->next;
    }
    printf("\n");
  }
}

// int main() {
//   struct HashMap *map = hashMapNew(10);
//   HashLink links[] = {{.key = "a", .value = 0, .next = NULL},
//                       {.key = "c", .value = 1, .next = NULL},
//                       {.key = "d", .value = 2, .next = NULL},
//                       {.key = "f", .value = 3, .next = NULL},
//                       {.key = "g", .value = 4, .next = NULL}};
//   hashMapPut(map, links[0].key, links[0].value);
//   hashMapPut(map, links[1].key, links[1].value);
//   hashMapPut(map, links[2].key, links[2].value);
//   hashMapPut(map, links[3].key, links[3].value);
//   hashMapPut(map, links[4].key, links[4].value);
//   hashMapPrint(map);
//   printf("newline\n");
//   hashMapRemove(map, links[0].key);
//   hashMapRemove(map, links[1].key);
//   //   hashMapRemove(map, links[2].key);
//   //   hashMapRemove(map, links[3].key);
//   hashMapPrint(map);
// }
