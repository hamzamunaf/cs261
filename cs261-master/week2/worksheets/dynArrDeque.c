#include "dynArrDeque.h"

int main() {
  struct deque d;
  initArrDeque(&d, 5);
  dequeAddFront(&d, 1);
  dequeAddBack(&d, 2);
  dequeAddBack(&d, 4);
  dequeAddBack(&d, 6);
  dequeAddBack(&d, 8);
  dequeAddBack(&d, 50);
  dequeRemoveBack(&d);
  dequeRemoveBack(&d);
  dequeRemoveFront(&d);
  for (int i = 0; i < d.cap; i++) {
    printf("%d\n", d.data[i]);
  }
  printf("beg:%d - %d   deqfront:%d\n", d.beg, d.data[d.beg], dequeFront(&d));
  printf("end:%d - %d   deqback:%d\n", d.size, d.data[d.size], dequeBack(&d));
}