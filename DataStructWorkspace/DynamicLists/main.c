/*
 * main.c
 *
 *  Created on: Feb 26, 2016
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"






DLNode * head = NULL;

int main(void){
	head = GetNewDLNode(0,head);
	int nums[] = {1,2,3,4,5,6,7};
	AppendDLList(7, nums, head);
	printDLList(head);
	printInverseDLList(head);

	return 0;
}


