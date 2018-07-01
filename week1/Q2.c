/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int* parkinglot = NULL;
    parkinglot = a;
    a = b;
    b = parkinglot;
    
    /*Decrement the value of integer variable c*/
    c--;
    
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    srand (time(NULL));
    int x = (rand() % 10),
    y = (rand() % 10),
    z = (rand() % 10);
    
    
    
    /*Print the values of x, y and z*/
    
    printf("X: %d\n Y: %d\n Z: %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int result = foo(&x, &y, z);
    
    /*Print the values of x, y and z*/
    printf("X: %d\n Y: %d\n Z: %d\n", x, y, z);
    
    /*Print the value returned by foo*/
    printf("Result of foo: %d\n", result);
    
    return 0;
}
    
    


