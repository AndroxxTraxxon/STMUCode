/*
 * main.c
 *
 *  Created on: Jan 22, 2016
 *      Author: david
 */
#include "my_string.h"
#include "stdlib.h"
#include <stdio.h>

int main(int argc, char* args[]){
	string_type h = Create("Hello ", 6);
	string_type w = Create("World!", 6);
	string_type combine = Concatenate(h,w);

	string_type strings[] = {
			Create("defunct", 8),
			Create("abeyance", 9),
			Create("irrelevant", 11),
			Create("acquiesce", 10),
			Create("western", 8),
			Create("zealous", 8),
			Create("electric", 9),
			Create("trihedral", 10),
			Create("unimodal", 9),
			Create("vanquish", 9),
			Create("ambient", 8),
			Create("abbreviate", 11),
			Create("edifice", 8),
			Create("genre", 6),
			Create("ferrous", 8),
			Create("breve", 6),
			Create("BROCADE", 8),
			Create("brocades", 9),
			Create("supercalifragilisticexpialidocious", 34)
	};

	Print(combine);
	printf("\n###################\n");
	int count = sizeof(strings)/sizeof(string_type);
	string_type sortedList[count];

	int i;
	for(i = 0; i < count ; i++){
			Print(strings[i]);
			sortedList[i] = Clone(strings[i]);
			printf("\n");
	}

	printf("#####################\n");

	quickSort(sortedList, 0, count-1);
	printf("%lu\n", sizeof(string_type));
	for(i = 0; i < count; i++){
			Print(sortedList[i]);
			printf(" : ");
			Print(strings[i]);
			printf("\n");
	}
	getchar();
	return 0;
}


