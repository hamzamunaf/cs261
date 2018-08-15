/* CS261- Assignment 1 - Q.2*/
/* Name: Alex Cheng
 * Date: 7/11/2018
 * Solution description: This program demonstrates the concept of passing values
 * into functions in C.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int *a, int *b, int c) {
  /*Swap the addresses stored in the pointer variables a and b*/
  int *tmp = a;
  a = b;
  b = tmp;
  /*Decrement the value of integer variable c*/
  c--;
  /*Return c*/
  return c;
}

int main() {
  /*Declare three integers x,y and z and initialize them randomly to values in
   * [0,10] */
  srand(time(NULL));
  int x = rand() % 11;
  int y = rand() % 11;
  int z = rand() % 11;
  /*Print the values of x, y and z*/
  printf("x: %d, y: %d, z: %d\n", x, y, z);
  /*Call foo() appropriately, passing x,y,z as parameters*/
  foo(&x, &y, z);
  /*Print the values of x, y and z*/
  printf("x: %d, y: %d, z: %d\n", x, y, z);
  /*Print the value returned by foo*/
  printf("foo: %d\n", foo(&x, &y, z));

  return 0;
}

/* a. Yes, the return value is different from z since z is passed in as a copy,
 * changing it in the function will not change the value of z.

 * b. No, the values are the same since we are passing in an address as a copy
 * then swapping the copies of the addresses. The original x,y addresses are
 * unchanged so the values are unchanged */