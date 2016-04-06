/*
 * main.c
 *
 *  Created on: Apr 2, 2016
 *      Author: david
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ParentheChecker.h"

int main(int argc, char ** args){
	fflush(stdout);
	printf("Hello World");
	FILE * cFile;
	char * cFileName = "main.c";
	printf("\nOpening file...");
	cFile = fopen(cFileName,  "r");


	/* C file section*/
	if(cFile==NULL){
		fprintf(stderr, "Can't open input file name!");
		exit(1);
	}

	fseek(cFile, 0L, SEEK_END);
	long cSize = ftell(cFile);
	fseek(cFile, 0L, SEEK_SET);
	printf("The size is %ld.\n", cSize);
	char * cInput = (char *)malloc(sizeof(char)* cSize);
	int i;
	for(i=0; i < cSize; i++){
		*(cInput+i) = fgetc(cFile);
	}

	printf("File Imported. Beginning Scan...\n");

	int correct = checkC(cSize, cInput);//will be 0 if it is balanced.
	printf("The <%s> file is %sbalanced.", cFileName, (correct)?"un":"");


	/*Pascal file section*/
	FILE * pasFile;
	char * pasFileName = "pascalTest.pas";
	pasFile = fopen(pasFileName, "r");

	if(cFile==NULL){
		fprintf(stderr, "Can't open input file name!");
		exit(1);
	}

	fseek(pasFile, 0L, SEEK_END);
	long pSize = ftell(pasFile);
	fseek(pasFile, 0L, SEEK_SET);
	printf("The size is %ld.\n", cSize);
	char * pInput = (char *)malloc(sizeof(char)* pSize);
	for(i=0; i < pSize; i++){
		*(pInput+i) = fgetc(pasFile);
	}

	printf("File Imported. Beginning Scan...\n");

	correct = checkPascal(pSize, pInput);//will be 0 if it is balanced.
	printf("The <%s> file is %sbalanced.", pasFileName, (correct)?"un":"");


	return 0;
}
