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
			Create("defunct", 8), //0
			Create("abeyance", 9),//1
			Create("irrelevant", 11),//2
			Create("acquiesce", 10),//3
			Create("western", 8),//4
			Create("zealous", 8),//5
			Create("electric", 9),//6
			Create("trihedral", 10),//7
			Create("unimodal", 9),//8
			Create("vanquish", 9),//9
			Create("ambient", 8),//10
			Create("abbreviate", 11),//11
			Create("edifice", 8),//12
			Create("genre", 6),//13
			CreateStr("ferrous"),//14
			Create("breve", 6),//15
			Create("BROCADE", 8),//16
			Create("brocades", 9),//17
			Create("supercalifragilisticexpialidocious", 34)//18
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


