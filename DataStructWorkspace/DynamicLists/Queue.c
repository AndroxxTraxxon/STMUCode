/*  Queue.c
 *
 *  Created on: Feb 26, 2016
 *      Author: david
 */

#include "Queue.h"
#include "LinkedList.h"
#include <stdlib.h>

void Enqueue(LNode * node, LNode * head){

	if(head == NULL){
		head = node;
	}else{
		GetTailLNode(head)->next = node;
	}

}

LNode Dequeue (LNode * node){
	LNode pop = *node;
	node = node->next;
	return pop;
}

LNode Peek(LNode * node){
	return *node;
}

