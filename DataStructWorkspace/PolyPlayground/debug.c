/*
 * debug.c
 *
 *  Created on: Mar 2, 2016
 *      Author: david
 */

#include "debug.h"

void dbgHalt(char * message){
	if(!message){
		printf("ERROR: UNKNOWN ISSUE");
	}else{
		printf("ERROR: %s", message);
	}
	clearInputBuffer();
	printf("Press any key to continue");
	getch();
	exit(1);
}

void clearInputBuffer (void)
{
  while ( getchar() != '\0' );
}
