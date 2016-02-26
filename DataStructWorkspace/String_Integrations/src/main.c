/*
 * main.c
 *
 *  Created on: Jan 22, 2016
 *      Author: david
 */
#include "my_string.h"
//#include "stdlib.h"
#include <stdio.h>

void printStringList(string_type*, int length);
void flushInputBuffer();

int main(int argc, char* args[]){

	printf("Hello World!");
	string_type strings[] = {//make the list of strings
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

	printf("\n###################\n");
	int count = sizeof(strings)/sizeof(string_type); 				//figure out how long the list is
	string_type sortedList[count]; 									//make another array, with the same size, so that I can copy stuff into it and sort it

	int i;
	for(i = 0; i < count ; i++){
			printf("%s%3d%s", "Element ", i, ": ");
			Print(strings[i]);
			sortedList[i] = Clone(strings[i]);
			printf("\n");
	}

	printf("#####################\n");

	quickSort(sortedList, 0, count-1);
	printf("%s\n","Sorted List ");
	printStringList(sortedList, count);

	printf("%s\n", "Choose two words to concatenate from the sorted list...");

	int input = -1, a = -1, b = -1;
	do{
		printf("\n%s%s%s%d%s%d%s","Enter a selection for the ",(a==-1)?" first ":" second "," word, ",0," thru ",count-1,":");
		scanf("%d", &input);
		if(!(input >=0 && input < count)){
			printf("%s", "\nInvalid input!");
			flushInputBuffer();

		}else{
			if(a == -1){
				a = input;
				printf("%s%s%s", "The first word is ", sortedList[a].element,".");
			}else{
				b = input;
				printf("%s%s%s", "The second word is ", sortedList[b].element,".");
			}
		}
	}while(a==-1 || b == -1);
	string_type concat = Concatenate(sortedList[a], sortedList[b]);
	printf("\n%s", "The concatenation of the two selected words is ");
	Print(concat);
	printf("\nPress [ENTER] to continue...");
	getchar();
	getchar();
	return 0;
}

void printStringList(string_type* strings, int length){
	int i;
	printf("#####################\n");
	for(i = 0; i < length; i++){
		printf("%s%3d%s", "Element ", i, ": ");
		Print(strings[i]);
		printf("\n");
	}
	printf("#####################\n");
}

void flushInputBuffer(){
	char c;
	while((c = getchar()) != '\n')
			/* discard */ ;
}

