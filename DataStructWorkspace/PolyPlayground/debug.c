/*
 * debug.c
 *
 *  Created on: Mar 2, 2016
 *      Author: david
 */
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

void clearInputBuffer(void);

void dbgHalt(char * message){
	if(!message){
		printf("ERROR: UNKNOWN ISSUE");
	}else{
		printf("ERROR: %s", message);
	}
	clearInputBuffer();
	printf("Press any key to continue");
	exit(EXIT_FAILURE);
}

void clearInputBuffer (void)
{
  while ( getchar() != '\0' );
}
