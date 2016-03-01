<<<<<<< HEAD
/*
 * Queue.c
 *
 *  Created on: Feb 26, 2016
 *      Author: David Culbreth
 */

#include "Queue.h"
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


=======
/*
 * Queue.c
 *
 *  Created on: Feb 26, 2016
 *      Author: david
 */

#include "Queue.h"
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


>>>>>>> refs/remotes/origin/master
