/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

static int MAX_SIZE = 1000;
//65->90 Upper case
//95 _
//97->122 lower case

char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
	ch -= 32;
return ch;
}

char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/
	ch -= 32;
return ch;
}

int stringLength(char s[]) {
   /*Return the length of the string*/
	 int len = 0;
	 while(len < MAX_SIZE && s[len+1] != '\0'){
		 len++;
	 }
return len;
}


void printString(char s[]){
	for(int i = 0; i < stringLength(s); i++){
		printf("%c", s[i]);
	}
	printf("\n");
}

void removeChar(char* word, int loc){

}

void camelCase(char* word){
	/*Convert to camelCase*/
	for(int i = 0; i < stringLength(word); i++){
		if (word[i] >= 65 && word[i] <= 90){
			word[i] = word[i] + 32;
		}

	}


}

int main(){
	char buffer[MAX_SIZE];
	//FILE *fp = tmpfile();
	/*Read the string from the keyboard*/
	printf("Please enter a string: ");


	fgets(buffer, MAX_SIZE, stdin);
	printString(buffer);
	printf("Length: %i\n", stringLength(buffer));
	camelCase(buffer);
	printString(buffer);
	/*Call camelCase*/

	//fclose(fp);


	/*Print the new string*/


	return 0;
}
