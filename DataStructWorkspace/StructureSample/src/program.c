/*
 * program.c
 *
 *  Created on: Jan 13, 2016
 *      Author: David Culbreth
 */

#include <stdio.h>
#include <stdlib.h>


struct Card {

	char *face;
	char *suit;

};

struct BitCard{
	//example of initializing a bit field

	unsigned face : 4;
	unsigned suit : 2;
	//This next line will be used as "padding" in memory
	unsigned : 3;
	//The 3
	unsigned color: 1;


};

union number{
	//within a union,
	int x;
	double y;

};

typedef struct Card * cardPtr;

int main(){


	union number value;
	value.x = 100;

	printf("%s: %d\n%s: %lf\n" ,
			"int", value.x,
			"double", value.y);

	value.y = 200.0;

		printf("%s: %d\n%s: %lf\n" ,
				"int", value.x,
				"double", value.y);

	printf("Hello World!");
	getchar();



	//malloc video
	//int *nums  = malloc(20);//allocates 20 bytes of unused memory, and assigns the pointer the beginning to nums
	int *nums = malloc(sizeof(int) * 5); // this is the more proper way to do it: same thing as line

	int i;
	for (i = 0 ; i < sizeof(nums)/sizeof(int); i++){
		printf("%i%s", nums[i], "\n");
	}
	free(nums);
	return 0;
}


