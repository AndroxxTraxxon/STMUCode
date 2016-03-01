/*
 * main.c
 *
 *  Created on: Feb 29, 2016
 *      Author: David Culbreth
 */
#include "Poly.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	//fflush(stdout);
	//printf("Hello World!");
	poly p = NewPoly();
	AddTerm(1, 0, &p);
	AddTerm(1, 1, &p);
	poly q = polyPow(p, 5);
	//poly r = polyDiff(q,p);
	printPoly(p);
	printf("\n");
	printPoly(q);
	printf("\n");
	//printPoly(r);
	return 0;
}
