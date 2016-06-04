/*
 * main.c
 *
 *  Created on: Jan 24, 2016
 *      Author: david
 */

#include <stdio.h>
#include "vector3.h"

int main(int argc, char* args[]){
	vector3 p = mkVector(2,3,4);
	vector3 q = mkVector(1,5,1);
	vector3 r = mkVector(3,2,5);


	vector3 a = diffVector(q, p);
	vector3 b = diffVector(r, p);
	vector3 x = crossP(a,b);


	printf("P->Q: ");
	printV(a);
	printf("\n");
	printf("P->R: ");
	printV(b);
	printf("\n");
	printf("PRxPS: ");
	printV(x);

	printf("\n");
	//printf("%.3lf", v3Mag(c)/2);
	getchar();
	return 0;
}
