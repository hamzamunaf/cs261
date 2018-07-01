/* CS261- Assignment 1 - Q. 0*/
/* Name: Cory Kertz
 * Date: 06/30/2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
          
     /*Increment the value of the integer pointed to by iptr by 5*/
          
     /*Print the address of iptr itself*/
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
               
     /*Decrement jptr by 1*/
      
     /*Print the address of jptr itself*/
}


int main(){
    
    /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/
    srand(time(NULL));
    int x = rand() % 10;
    
    /*Print the value and address of x*/
    printf(%x, x);
    printf(%x, &x);
    
    /*Call fooA() with the address of x*/
    
    /*Print the value of x*/
    
    /*Call fooB() with the address of x*/
    
    /*Print the value and address of x*/
 
    
    return 0;
}


