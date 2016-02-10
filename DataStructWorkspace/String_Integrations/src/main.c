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
	string_type h = CreateStr("Hello ");
	string_type w = CreateStr("World!");
	//string_type combine = CreateStr("combination");
	string_type combine = Concatenate(h,w);

	string_type strings[] = {
			CreateStr("defunct"), //0
			CreateStr("abeyance"),//1
			CreateStr("irrelevant"),//2
			CreateStr("acquiesce"),//3
			CreateStr("western"),//4
			CreateStr("zealous"),//5
			CreateStr("electric"),//6
			CreateStr("trihedral"),//7
			CreateStr("unimodal"),//8
			CreateStr("vanquish"),//9
			CreateStr("ambient"),//10
			CreateStr("abbreviate"),//11
			CreateStr("edifice"),//12
			CreateStr("genre"),//13
			CreateStr("ferrous"),//14
			CreateStr("breve"),//15
			CreateStr("BROCADE"),//16
			CreateStr("bRoCaDeS"),//17
			CreateStr("supercalifragilisticexpialidocious")//18
	};



	Print(combine);
	printf("\n###################\n");
	int count = sizeof(strings)/sizeof(string_type);
	string_type sortedList[count];

	int i;
	for(i = 0; i < count ; i++){
			printf("%s%2d%s", "Element ", i, ": ");
			Print(strings[i]);
			sortedList[i] = Clone(strings[i]);
			printf("\n");
	}

	printf("#####################\n");

	quickSort(sortedList, 0, count-1);
	printf("%s","Sorted List ");
	printf("#####################\n");
	for(i = 0; i < count; i++){
		printf("%s%d%s", "Element ", i, ": ");
					Print(sortedList[i]);
			//printf(" : ");
			//Print(strings[i]);
			printf("\n");
	}
	getchar();
	return 0;
	printf("#####################\n");
	printf("%s\n%s", "Choose two words to concatenate:", "Enter a number, 0 thru 18");
	scanf("");
}


