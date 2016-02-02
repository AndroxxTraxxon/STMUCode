/*
 * main.c
 *
 *  Created on: Jan 24, 2016
 *      Author: david
 */

#include <stdio.h>
#include "vector3.h"

int main(int argc, char* args[]){
	vector3 p = mkVector(1,3,3);
	vector3 q = mkVector(4,-3,9);
	vector3 r = mkVector(7,2,1);
	vector3 s = mkVector(4,8,-5);


	vector3 a = diffVector(q, p);
	vector3 b = diffVector(r, p);
	vector3 c = diffVector(s, p);
	vector3 x = crossP(b,c);


	printf("P->Q: ");
	printV(a);
	printf("\n");
	printf("P->R: ");
	printV(b);
	printf("\n");
	printf("P->S: ");
	printV(c);
	printf("\n");
	printf("PRxPS: ");
	printV(x);
	printf("\n");

	double d = dotP(a, crossP(b,c));
	printV(c);
	printf("\n");
	printf("%lf", d);
	//printf("%.3lf", v3Mag(c)/2);
	getchar();
	return 0;
}
