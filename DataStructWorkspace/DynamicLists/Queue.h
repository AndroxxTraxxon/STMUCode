/*
 * Queue.h
 *
 *  Created on: Feb 26, 2016
 *      Author: david
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "LinkedList.h"

void Enqueue(LNode * node, LNode * head);
LNode Dequeue(LNode * node);
LNode Peek(LNode * node);

#endif /* QUEUE_H_ */
