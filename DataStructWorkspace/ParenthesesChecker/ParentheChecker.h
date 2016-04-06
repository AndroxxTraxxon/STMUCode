/*
 * ParentheChecker.h
 *
 *  Created on: Apr 2, 2016
 *      Author: david
 */

#ifndef PARENTHECHECKER_H_
#define PARENTHECHECKER_H_

#include <stdlib.h>

typedef struct charTerm{
	char c;
	struct charTerm * next;
}term;

typedef struct charStack{
	term * head;
}stack;


stack newStack();

void push(term * t, stack * s);
/*
 * push(t,s) will push term t onto the top of stack s.
 */
term * pop(stack * s);
/*
 * pop(h) will remove the top term from stack s and return it.
 */
char peek(stack * s);
/*
 * peek(h) will return the char value of the top term in the stack s.
 */

int checkAny(int delimiterPairCount, char ** delimiters, long textLength, char * text);
int checkPascal(long textLen, char * text);
int checkC(long textLen, char * text);

#endif /* PARENTHECHECKER_H_ */
