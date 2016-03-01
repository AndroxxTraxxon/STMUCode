/*
 * Stack.h
 *
 *  Created on: Feb 29, 2016
 *      Author: david
 */

#ifndef STACK_H_
#define STACK_H_

#include "LinkedList.h"

typedef LNode* Stack;

void PushStack(int val, Stack top);
int PopStack(Stack top);
int TopStack(Stack top);
Stack CreateNewStack();



#endif /* STACK_H_ */
