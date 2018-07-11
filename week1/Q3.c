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
		for(int i = loc; i < (stringLength(word)); i++){
			word[i] = word[i+1];
	}
}

void camelCase(char* word){
	/*Convert to camelCase*/
	int wordCount = 0;
	int isWord = 0;


	//65->90 Upper case
	//95 _
	//97->122 lower case

	//-----------------------------------------
	//Turn everything into '_' and letters
	//-----------------------------------------
	for(int i = 0; i < stringLength(word); i++){
		if ((word[i] > 31 && word[i] < 65) || (word[i] > 90 && word[i] < 95)){
			word[i] = 95;
		}
	}

	//-----------------------------------------
	//Determine > 2 words
	//-----------------------------------------

	for(int i = 0; i < stringLength(word); i++){
		if(word[i] != 95){
			isWord = 1;
			wordCount++;
		}else if(isWord == 1){
			isWord = 0;
		}
	}

	if (wordCount > 2){
		//-----------------------------------------
		//Remove extra 95's in front
		//-----------------------------------------
		for(int i = 0; i < stringLength(word); i++){
			if(word[i] == 95 && i == 0){
				removeChar(word, i);
				i = -1;
		}
	}

	//-----------------------------------------
	//Remove 95's in middle and back
	//-----------------------------------------
	for(int i = 0; i < stringLength(word); i++){
		if(word[i] == 95 && word[i-1] == 95){
			removeChar(word, i);
			i--;
		}
	}

	//-----------------------------------------
	//Lower case all letters
	//-----------------------------------------
	for(int i = 0; i < stringLength(word); i++){
		if(word[i] >= 65 && word[i] <= 90){
			word[i] = toLowerCase(word[i]);
		}
	}

	//-----------------------------------------
	//Capitalize first letter
	//-----------------------------------------
	for(int i = 0; i < stringLength(word); i++){
		if(word[i] >= 97 && word[i] <= 122 && (word[i-1] == 95 || i == 0)){
			word[i] = toUpperCase(word[i]);
		}
	}

	//-----------------------------------------
	//Remove the '_'
	//-----------------------------------------
	for(int i = 0; i < stringLength(word); i++){
		if(word[i] == 95){
			removeChar(word, i);
			i--;
		}
	}
}else{
		printf("invalid input string");
	}
}

int main(){
	char buffer[MAX_SIZE];

	/*Read the string from the keyboard*/
	printf("Please enter a string: ");
	fgets(buffer, MAX_SIZE, stdin);

	/*Call camelCase*/
	camelCase(buffer);

	/*Print the new string*/
	printString(buffer);

	return 0;
}
