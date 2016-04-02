/*
 * ParentheChecker.c
 *
 *  Created on: Apr 2, 2016
 *      Author: david
 */
#include "ParentheChecker.h"
#include <string.h>
#include <stdio.h>

stack newStack(){
	stack s;
	s.head = NULL;
	return s;
}


void pushC(char c, stack s){
	term * t = malloc(sizeof(term));
	t->c = c;
	t->next = NULL;
	push(t,s);
}

void push(term * t, stack s){
	t->next = s.head;
	s.head = t;
}
/*
 * push(t,s) will push term t onto the top of stack s.
 */
term pop(stack s){
	if(s.head == NULL){
		return *s.head;
	}
	term * top = s.head;
	s.head = s.head->next;
	top->next = NULL;
	return *top;
}
/*
 * pop(h) will remove the top term from stack s and return it.
 */
char peek(stack s){
	return s.head->c;
}
/*
 * peek(h) will return the char value of the top term in the stack s.
 */

int checkAny(int delimPairCount, char ** delimiters, long textLength, char * text){
	/*
	 *	The delimiter pairs should be entered in an order such that delimiters[even number] is the opening brackets
	 *	And the delimiters[odd number] is the closing brackets
	 */
	stack bookends;
	bookends.head = NULL;
	char * currentDelimiter;
	int textIndex, delimIndex, delimMatch, delimLen;
	for(textIndex = 0; textIndex < textLength; textLength++){//go through the input file, character by character
		//for each character:
		for(delimIndex = 0; delimIndex < delimPairCount * 2; delimIndex++){//check against all possible bracket combinations.
			currentDelimiter = delimiters[delimIndex];//the current bracket in the delimiters array.
			if(text[textIndex]==currentDelimiter[0]){//if the first character of the delimiter matches,
				delimMatch = 1;//assume we have a match
				delimLen = strlen(currentDelimiter);
				if(delimLen>1){//if the length of the delimiter is greater than one (like for "begin")
					int tempIndex = 0;
					while(tempIndex < delimLen && text[textIndex + tempIndex]!='\0'){
						//check the rest of the delimiter against the following characters
						if(text[textIndex + tempIndex] != currentDelimiter[tempIndex]){
							delimMatch = 0;
							break;
						}
					}

				}

				if (delimMatch == 1) {//if we have a match between the text and a delimiter
					if(delimIndex%2==0){//if the current char is an opener
						pushC(text[textIndex], bookends);//add it to the stack
					}else{//otherwise, the delimiter is a closer.
						if(peek(bookends)==(delimiters[delimIndex-1])[0]){//check to see if the top of the stack is a match
							pop(bookends);//if the delimiters match, pop the stack
						}
						else{
							//if they do not match, then exit the function with a -1.
							return -1;
						}
					}
				}
			}
		}
	}



	return 0;
}
int checkPascal(long textLen, char * text){
	char * delimiters[] = {"begin", "end", "(", ")", "[", "]", "{", "}"};
	int pairs = 4;
	checkAny(pairs, delimiters, textLen, text);
	return 0;
}

int checkC(long textLen, char * text){
	char * delimiters[] = {"/*", "*/", "(", ")", "[", "]", "{", "}"};
		int pairs = 4;
		checkAny(pairs, delimiters, textLen, text);
	return 0;
}
