/*
 * DoublyLinkedList.h
 *
 *  Created on: Feb 26, 2016
 *      Author: david
 */

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include <stdlib.h>
typedef struct DLNode{
	//the DLNode struct uses 8 + sizeof(<T>) for data type <T>.
	//4 bytes per
	int data;
	struct DLNode * next;
	struct DLNode * prev;
}DLNode;

void InsertDLNodeAtHead(int x, DLNode * head);
void AppendDLNode(int x, DLNode * head);
void AppendDLList(int length, int* elements, DLNode * head);
DLNode * GetNewDLNode(int x, DLNode * head);
DLNode * GetTailDLNode(DLNode * head);
DLNode * RemoveDLNode(int x, DLNode * head);
void printDLList(DLNode * head);
void printInverseDLList(DLNode * head);

#endif /* DOUBLYLINKEDLIST_H_ */
