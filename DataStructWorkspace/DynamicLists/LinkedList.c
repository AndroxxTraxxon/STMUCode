/*
 * LinkedList.c
 *
 *  Created on: Feb 26, 2016
 *      Author: David Culbreth
 */

#include "LinkedList.h"
#include <stdio.h>

LNode * GetNewLNode(int x, LNode * head){
	LNode * temp = (LNode *)malloc(sizeof(LNode));
	temp->data = x;
	head = (head == NULL)? temp:head;
	temp->next = temp;
	return temp;
}



void InsertLNodeAtHead(int x, LNode * head){
	LNode * newNode = GetNewLNode(x, head);
	//link the proper nodes as next and previous
	newNode->next = head;
	//de-link adjacent nodes and link to newNode
	//DO TAIL NODE FIRST, OTHERWISE IT IS LOST!
	GetTailLNode(head)->next = newNode;
	//set head to new node
	head = newNode;
}

void AppendLNode(int x, LNode * head){
	LNode * newNode = GetNewLNode(x, head);
	//link the proper nodes as next and previous
	newNode->next = head;
	//de-link adjacent nodes and link to newNode
	//DO TAIL NODE FIRST, OTHERWISE IT IS LOST!
	GetTailLNode(head)->next = newNode;
}

void printLList(LNode * head){
	LNode * nextToPrint = head;
	printf("[");
	do{
		printf("%i", nextToPrint->data);
		nextToPrint = nextToPrint->next;
		if(nextToPrint!=head){
			printf(",");
		}
	}while(nextToPrint != head);
	printf("]");
}
void printInverseLList(LNode * head){
	printInverseLList(head->next);
	printf(" %i", head->data);
}
void AppendLList(int length, int * elements , LNode * head){
	int i;
	for(i=0;i<length;i++){
		AppendLNode(elements[i], head);
	}
}

LNode * GetTailLNode(LNode * head){
	LNode * currentNode = head;
	while(currentNode->next != NULL)
		currentNode = currentNode->next;
	return currentNode;
}
