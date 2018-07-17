/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArrayC.h"

//-------------------------------------------------------------------------
// Let's bring in a couple functions to make our lives easier...
//
//-------------------------------------------------------------------------



/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post:
*/

int isBalanced(char* s)
{
	/* FIXME: You will write this function */

	DynArr *stack = newDynArr(15);
  //assert(s != 0);

  char nextC;
	nextC = nextChar(s);

  while(nextC != '\0')
  {
      if(nextC == '(' || nextC == '[' || nextC == '{')
      		pushDynArr(stack, nextC);

      if(nextC == ')' && topDynArr(stack) == '(')
					popDynArr(stack);

      if(nextC == ']' && topDynArr(stack) == '[')
          popDynArr(stack);

      if(nextC == '}' && topDynArr(stack) == '{')
          popDynArr(stack);

      nextC = nextChar(s);
  }
  if(!isEmptyDynArr(stack)) {
      deleteDynArr(stack);
      return 0;
  }
  else {
      deleteDynArr(stack);
      return 1;
  }
}

int main(int argc, char* argv[]){

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);


	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}
