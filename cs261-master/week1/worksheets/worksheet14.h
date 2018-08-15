#ifndef TYPE
#define TYPE int
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct DynArr {
  TYPE *data;   /* pointer to the data array */
  int size;     /* Number of elements in the array */
  int capacity; /* capacity ofthe array */
};

void _setCapacityDynArr(struct DynArr *v, int newCap);

void initDynArr(struct DynArr *v, int capacity) {
  v->data = (TYPE *)malloc(sizeof(TYPE) * capacity);
  assert(v->data != 0);
  v->size = 0;
  v->capacity = capacity;
}

/* free the space on the heap */ /* make it point to null */
void freeDynArr(struct DynArr *v) {
  if (v->data != 0) {
    free(v->data);
    v->data = 0;
    v->size = 0;
    v->capacity = 0;
  }
}

int sizeDynArr(struct DynArr *v) { return v->size; }

void addDynArr(struct DynArr *v, TYPE val) {
  /* Check to see if a resize is necessary */
  if (v->size >= v->capacity)
    _setCapacityDynArr(v, 2 * v->capacity);
  v->data[v->size] = val;
  v->size++;
}

/*fill in code*/
void _setCapacityDynArr(struct DynArr *v, int newCap) {
  struct DynArr newArr;
  initDynArr(&newArr, newCap);
  for (int i = 0; i < v->size; i++) {
    addDynArr(&newArr, v->data[i]);
  }
  *v = newArr;
  freeDynArr(v);
}

TYPE getDynArr(struct DynArr *v, int position) {
  assert(position < v->size);
  assert(position >= 0);
  return v->data[position];
}

void putDynArr(struct DynArr *v, int position, TYPE value) {
  assert(position < v->size);
  assert(position >= 0);
  /* Check to see if a resize is necessary */
  if (v->size >= v->capacity)
    _setCapacityDynArr(v, 2 * v->capacity);
  /* Shift all items down one */
  for (int i = v->size; i > position; i--) {
    v->data[i] = v->data[i - 1];
  }
  v->data[position] = value; // overwrite current value with new value
  v->size++;
}

void removeAtDynArr(struct DynArr *v, int position) {
  assert(position < v->size);
  assert(position >= 0);
  v->size--; // decrement size
  /* Shift all items after position up one */
  for (int i = position; i < v->size; i++) {
    v->data[i] = v->data[i + 1];
  }
  v->data[v->size] = 0; // set the last value to 0
}

void swapDynArr(struct DynArr *v, int i, int j) {
  assert(i < v->size);
  assert(j < v->size);
  assert(i >= 0);
  assert(j >= 0);
  TYPE tmp = v->data[i];
  v->data[i] = v->data[j];
  v->data[j] = tmp;
}