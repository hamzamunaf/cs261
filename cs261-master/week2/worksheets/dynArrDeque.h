#ifndef TYPE
#define TYPE int
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct deque {
  TYPE *data;
  int size;
  int cap;
  int beg;
};

void initArrDeque(struct deque *d, int cap) {
  d->data = (TYPE *)malloc(cap * sizeof(TYPE));
  assert(d->data != 0);
  d->size = d->beg = 0;
  d->cap = cap;
}

void _dequeSetCapacity(struct deque *d, int newCap) {
  /* Create a new underlying array*/
  TYPE *newData = (TYPE *)malloc(sizeof(TYPE) * newCap);
  assert(newData != 0);
  /* copy elements to it */
  int j = d->beg;
  for (int i = 0; i < d->size; i++) {
    newData[i] = d->data[j];
    j = j + 1;
    if (j >= d->cap)
      j = 0;
  }
  /* Delete the oldunderlying array*/
  free(d->data);
  /* update capacity and size and data*/
  d->data = newData;
  d->cap = newCap;
  d->beg = 0;
}

void dequeFree(struct deque *d) {
  free(d->data);
  d->size = d->cap = 0;
}

int dequeSize(struct deque *d) { return d->size; }

void _dequeDoubleCapacity(struct deque *d) { _dequeSetCapacity(d, 2 * d->cap); }

void dequeAddFront(struct deque *d, TYPE newValue) {
  /* check if we need to increase capacity */
  if (d->size >= d->cap)
    _dequeSetCapacity(d, 2 * d->cap);
  /* if beg is 0, move beg to end of memory */
  if (d->beg - 1 < 0)
    d->beg = d->cap - 1;
  else
    d->beg--;
  d->data[d->beg] = newValue;
  d->size++;
}

void dequeAddBack(struct deque *d, TYPE newValue) {
  /* check if we need to increase capacity */
  if (d->size >= d->cap)
    _dequeSetCapacity(d, 2 * d->cap);
  /* compute absolute index */
  int absIdx = (d->beg + d->size) % d->cap;
  d->data[absIdx] = newValue;
  d->size++;
}

void dequeRemoveFront(struct deque *d) {
  if (d->beg + 1 >= d->cap)
    d->beg = 0;
  else
    d->beg++;
  d->size--;
}

void dequeRemoveBack(struct deque *d) {
  assert(d->size > 0);
  d->size--;
}

TYPE dequeFront(struct deque *d) { return d->data[d->beg]; }

TYPE dequeBack(struct deque *d) {
  int absIdx = ((d->beg + d->size) % d->cap) - 1;
  return d->data[absIdx];
}