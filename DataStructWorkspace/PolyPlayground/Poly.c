/*
 * Poly.c
 *
 *  Created on: Feb 29, 2016
 *      Author: David Culbreth
 */

#include "Poly.h"
#include "stdlib.h"

/*
 * 	NewPolyTerm: struct PolyTerm *
 * 	creates a new struct PolyTerm with the given coefficient and power, then returns its pointer.
 */
term * NewPolyTerm(double coeff, double power){
	term * newTerm = (term *)malloc(sizeof(term));
	newTerm->coeff = coeff;
	newTerm->power = power;
	newTerm->next = NULL;
	newTerm->prev = NULL;
	return newTerm;
}


poly NewPoly(){
	poly newPoly;
	newPoly.termCount = 0;
	newPoly.head = NULL;
	return newPoly;
}

void AddTerm(double coeff, double power, poly nomial){
	term * daTerm = NewPolyTerm(coeff, power);
	if(nomial.head == NULL){
		nomial.head = daTerm;
		nomial.termCount++;
		return;
	}
	term * current = nomial.head;
	while(current->coeff < coeff && current->next != NULL){
		current = current->next;
	}
	//this should bring us within one node of where we want to be. close enough.
	double diff = daTerm->coeff - current->coeff;

	if(diff > 0){
		//new term should be added AFTER current term
	}else if(diff < 0){
		//new term should be added BEFORE current term

	}else{
		//coeff and current coeff are added
	}

	//the last term should NOT loop back to the beginning. its term* next should be NULL
}

void RemoveTerm(double power, poly nomial){

}

poly polyProd(poly a, poly b){
	poly result;
	//TODO: MAKE polyProd functional
	return result;
}

poly polySum(poly a, poly b){
	poly result;
	//TODO: MAKE polySum functional
	return result;
}

poly polyDiff(poly a, poly b){
	poly result;
	//TODO: MAKE polyDiff functional
	return result;
}

poly polyQuot(poly a, poly b){
	poly result;
	//TODO: MAKE polyQuot functional
	return result;
}

double * polyRoots(poly p){
	double results[5];
	//TODO: MAKE polyRoots functional
	return results;
}
