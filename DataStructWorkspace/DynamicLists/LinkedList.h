/*
 * LinkedList.h
 *
 *  Created on: Feb 26, 2016
 *      Author: david
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode;

void InsertLNodeAtHead(int x, LNode * head);
void AppendLNode(int x, LNode * head);
void AppendLList(int length, int* elements, LNode * head);
LNode * GetNewLNode(int x, LNode * head);
LNode * GetTailLNode(LNode * head);
LNode * RemoveLNode(int x, LNode * head);
void printLList(LNode * head);
void printInverseLList(LNode * head);

#endif /* LINKEDLIST_H_ */
