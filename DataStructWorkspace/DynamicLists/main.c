/*
 * main.c
 *
 *  Created on: Feb 26, 2016
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

void InsertAtHead(int x);
void Append(int x);
void AppendList(int length, int* elements);
Node * GetNewNode(int x);
Node * GetTailNode();

void printList(void);
void printInverseList(void);

Node * head = NULL;

int main(void){
	head = NULL;

	InsertAtHead(10);
	Append(20);
	int nums[] = {1,2,3,4,5,6,7};
	AppendList(7,nums);
	printList();
	printInverseList();

	return 0;
}

Node * GetNewNode(int x){
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->data = x;
	head = (head == NULL)? temp:head;
	temp->next = temp;
	temp->prev = temp;
	return temp;
}


void InsertAtHead(int x){
	Node* newNode = GetNewNode(x);
	//link the proper nodes as next and previous
	newNode->next = head;
	newNode->prev = head->prev;
	//de-link adjacent nodes and link to newNode
	//DO TAIL NODE FIRST, OTHERWISE IT IS LOST!
	GetTailNode()->next = newNode;
	head->prev = newNode;
	//set head to new node
	head = newNode;
}

void Append(int x){
	Node* newNode = GetNewNode(x);
	//link the proper nodes as next and previous
	newNode->next = head;
	newNode->prev = head->prev;
	//de-link adjacent nodes and link to newNode
	//DO TAIL NODE FIRST, OTHERWISE IT IS LOST!
	GetTailNode()->next = newNode;
	head->prev = newNode;
}

void printList(){
	Node * nextToPrint = head;
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
void printInverseList(){
	Node * nextToPrint = head->prev;
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
void AppendList(int length, int * elements ){
	int i;
	for(i=0;i<length;i++){
		Append(elements[i]);
	}
}

Node * GetTailNode(){
	Node * pre = head->prev;
	return pre;
}


