/*
 * main.c
 *
 *  Created on: Apr 2, 2016
 *      Author: david
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parenthechecker.h"

int main(int argc, char ** args){

	printf("Hello World");
	FILE * cFile;
	char * cFileName = "main.c";
	printf("Opening file...");
	cFile = fopen(cFileName,  "r");


	/*C file section */
	if(cFile==NULL){
		fprintf(stderr, "Can't open input file name!");
		exit(1);
	}

	fseek(cFile, 0L, SEEK_END);
	long cSize = ftell(cFile);
	fseek(cFile, 0L, SEEK_SET);
	char input[cSize];
	fgets(input, cSize, cFile);
	printf("\fFile Imported. Beginning Scan.");
	int correct = checkC(cSize, input);
	printf("The %s file is %sbalanced.", cFileName, (correct)?"":"un");


	/*Pascal file section*/
	/* FILE * pasFile;
	 * char * pasFileName = "main.pas";
	 * pasFile = fopen(pasFileName, "r");
	 */

	return 0;
}
