#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // start out with zero work effort expended
  int units = 0,

      // also no items have been created
      items = 0,

      // we have a container of size 5
      container = 8;

  printf("| Cont|items|units|\n");
  while (container <= 400) {
    while (items < container) {
      // -----------------------------------------------
      // To compute the average, count 1 “unit” of cost
      // each time a value is added to the dynamic array
      // without requiring a reallocation.
      // -----------------------------------------------
      items += 1;
      units += 1;
      printf("| %3d | %3d | %3d | %3f |\n", container, items, units,
             (float)units / (float)items);
    }

    // -----------------------------------------------
    // When the reallocation occurs, count one “unit”
    // of cost for each assignment performed as part
    // of the reallocation process, plus one more for
    // placing the new element into the newly enlarged
    // array.
    // -----------------------------------------------
    units += items;
    container += 2;
  }
  return 0;
}
