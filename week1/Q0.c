/* CS261- Assignment 1 - Q. 0*/
/* Name: Cory Kertz
 * Date: 06/30/2018
 * Solution description:
 */

 // Runs with:
 // gcc -Wall -std=c99 -o bin/Q0 Q0.c
 // ./bin/Q0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){

     /*Print the value and address of the integer pointed to by iptr*/
    printf("%d\n%p\n", *iptr, &(*iptr));

     /*Increment the value of the integer pointed to by iptr by 5*/
    (*iptr)+=5;

     /*Print the address of iptr itself*/
    printf("%p\n", &iptr);
}


void fooB(int* jptr){

     /*Print the value and address of the integer pointed to by jptr*/
    printf("%d\n%p\n", *jptr, &(*jptr));

     /*Decrement jptr by 1*/
    (*jptr)--;

     /*Print the address of jptr itself*/
    printf("%p\n", &jptr);
}


int main(){

    /*Declare an integer x and initialize it randomly to a value in [0,10]
*/
    srand (time(NULL));
    int x = rand() % 11;

    /*Print the value and address of x*/
    printf("%d\n%p\n", x, &x);



    /*Call fooA() with the address of x*/
    fooA(&x);

    /*Print the value of x*/
    printf("%d\n",x);

    //-------------------------------------------------
    //Is the value of x different than the value that
    //was printed at first? Why or why not?
    //-------------------------------------------------
    //Yes. The value for X that was orginally printed
    //is five more than after fooA(int *) was called
    //this is because the variable x was passed as a
    //reference to the memory location of the int x
    //therefor when we added 5 to the value in fooA
    //we were adding 5 to the int at the referenced
    //location.
    //-------------------------------------------------

    /*Call fooB() with the address of x*/
    fooB(&x);

    /*Print the value and address of x*/
    printf("%d\n%p\n", x, &x);

    //-------------------------------------------------
    //Are the value and address of x different than the
    //value and address that were printed before the
    //call to fooB(..)? Why or why not?
    //-------------------------------------------------
    //Yes and No. The value for X is one less than
    //before fooB(int *) was called this is because the
    //variable x was passed as a reference to the memory
    //location of the int x therefore when we decremented
    //the value in fooB we were subtracting 1 from the int
    //at the referenced location.  The address of X was
    //unchanged by the passage to fooB(int *) because
    //the decrement was preformed on the value of which
    //the pointer pointed and not to the referneced
    //memory location itself.
    //-------------------------------------------------

  return 0;
}
