/*
 * DoublyLinkedList.c
 *
 *  Created on: Feb 26, 2016
 *      Author: david
 */

#include "DoublyLinkedList.h"
#include <stdio.h>

DLNode * GetNewDLNode(int x, DLNode * head){
	DLNode * temp = (DLNode *)malloc(sizeof(DLNode));
	temp->data = x;
	head = (head == NULL)? temp:head;
	temp->next = temp;
	temp->prev = temp;
	return temp;
}



void InsertDLNodeAtHead(int x, DLNode * head){
	DLNode* newNode = GetNewDLNode(x, head);
	//link the proper nodes as next and previous
	newNode->next = head;
	newNode->prev = head->prev;
	//de-link adjacent nodes and link to newNode
	//DO TAIL NODE FIRST, OTHERWISE IT IS LOST!
	GetTailDLNode(head)->next = newNode;
	head->prev = newNode;
	//set head to new node
	head = newNode;
}

void AppendDLNode(int x, DLNode * head){
	DLNode * newNode = GetNewDLNode(x, head);
	//link the proper nodes as next and previous
	newNode->next = head;
	newNode->prev = head->prev;
	//de-link adjacent nodes and link to newNode
	//DO TAIL NODE FIRST, OTHERWISE IT IS LOST!
	GetTailDLNode(head)->next = newNode;
	head->prev = newNode;
}

void printDLList(DLNode * head){
	DLNode * nextToPrint = head;
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
void printInverseDLList(DLNode * head){
	DLNode * nextToPrint = head->prev;
	printf("[");
	do{
		printf("%i", nextToPrint->data);
		nextToPrint = nextToPrint->prev;
		if(nextToPrint!=head->prev){
			printf(",");
		}
	}while(nextToPrint != head->prev);
	printf("]");
}
void AppendDLList(int length, int * elements , DLNode * head){
	int i;
	for(i=0;i<length;i++){
		AppendDLNode(elements[i], head);
	}
}

DLNode * GetTailDLNode(DLNode * head){
	DLNode * pre = head->prev;
	return pre;
}

int Remove(DLNode * node){
	//Time complexity = O(1)
	DLNode * prev = node->prev;
	DLNode * next = node->next;
	prev->next = next;
	next->prev = prev;
	int val = node->data;
	free(node);
	node = NULL;
	return val;
}

void FreeDLChain(DLNode * head){
	//Time complexity = O(n) where n is the number of elements in the
	while(head!=NULL){
		Remove(head->prev);
	}
}
