/* CS261- Assignment 1 - Q. 0*/
/* Name: Alex Cheng
 * Date: 6/29/2018
 * Solution description: This program demonstrates the concept of pointer an
 * addresses in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int *iptr) {

  /*Print the value and address of the integer pointed to by iptr*/
  printf("iptr: %d, Address: %p\n", *iptr, iptr);
  /*Increment the value of the integer pointed to by iptr by 5*/
  *iptr += 5;
  /*Print the address of iptr itself*/
  printf("Address: %p\n", iptr);
}

void fooB(int *jptr) {

  /*Print the value and address of the integer pointed to by jptr*/
  printf("jptr: %d, Address: %p\n", *jptr, jptr);
  /*Decrement jptr by 1*/
  jptr -= 1;
  /*Print the address of jptr itself*/
  printf("Address: %p\n", jptr);
}

int main() {

  srand(time(NULL));
  /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/ int x = (rand() % 10) + 1;

  /*Print the value and address of x*/
  printf("x: %d, Address: %p\n", x, &x);
  /*Call fooA() with the address of x*/
  fooA(&x);
  /*Print the value of x*/
  printf("x: %d\n", x);
  /* Is the value of x different than the value that was printed at first? Why
   * or why not?
   * Yes, because we changed the value in the address that the
   * pointer was pointing to. */

  /*Call fooB() with the address of x*/
  fooB(&x);
  /*Print the value and address of x*/
  printf("x: %d, Address: %p\n", x, &x);
  /* Are the value and address of x different than the value and address that
   * were printed before the call to fooB(..)? Why or why not?
   * No, all we did was change the copy of the address we passed into fooB. The
   * value of x or its address were not changed. */
  return 0;
}
