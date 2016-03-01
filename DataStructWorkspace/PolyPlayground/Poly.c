/*
 * Poly.c
 *
 *  Created on: Feb 29, 2016
 *      Author: David Culbreth
 */

#include "Poly.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * 	NewPolyTerm: struct PolyTerm *
 * 	creates a new struct PolyTerm with the given coefficient and power, then returns its pointer.
 */
term * NewPolyTerm(double coeff, double power){
	//O(1)
	term * newTerm = (term *)malloc(sizeof(term));
	newTerm->coeff = coeff;
	newTerm->power = power;
	newTerm->next = NULL;
	newTerm->prev = NULL;
	return newTerm;
}

term * dupTerm(term * node){
	//O(1)
	term * duplicate = NewPolyTerm(node->coeff, node->power);
	return duplicate;
}


poly NewPoly(){
	//O(1)
	poly newPoly;
	newPoly.termCount = 0;
	newPoly.head = NULL;
	//printf("Made a new Poly!");
	return newPoly;
}

poly dupPoly(poly p){
	poly duplicate = NewPoly();
	duplicate.termCount = p.termCount;

	if(p.head != NULL){
		AppendTerm(p.head, &duplicate);
		term * next = p.head->next;
		while(next!=NULL){
			AppendTerm(next, &duplicate);
			next = next->next;
		}
	}
	return duplicate;
}

void AddTerm(double coeff, double power, poly * nomial){
	//worst case O(N)
	if(coeff != 0){
		if(nomial->head == NULL){
			term * daTerm = NewPolyTerm(coeff, power);
			nomial->head = daTerm;
			nomial->termCount++;
			return;
		}
		term * current = nomial->head;
		while(current->power > power && current->next != NULL){
			current = current->next;
		}
		//this should bring us within one node of where we want to be. close enough.
		double diff = power - current->power;

		if(diff == 0){
			current->coeff+= coeff;
			if(current->coeff == 0){
				RemoveTerm(current->power, nomial);
			}
		}else{
			term * daTerm = NewPolyTerm(coeff, power);
			if(diff < 0){
				//new term should be added AFTER current term
				daTerm->next = current->next;
				daTerm->prev = current;
				current->next = daTerm;
				if(daTerm->next != NULL)
					daTerm->next->prev = daTerm;
			}else{
				//new term should be added BEFORE current term
				daTerm->next = current;
				daTerm->prev = current->prev;
				current->prev = daTerm;
				if(daTerm->prev != NULL)
					daTerm->prev->next = daTerm;
				if(nomial->head == current)
					nomial->head = daTerm;
			}
			nomial->termCount++;
		}
	}
	//the last term should NOT loop back to the beginning. its term* next should be NULL
}

void AppendTerm(term * node, poly * nomial){
	//worst case: O(N)
	node = dupTerm(node);//have to disconnect the old node from the new node.
	if(nomial->head == NULL){
		nomial->head = node;
		nomial->termCount++;
		return;
	}
	term * current = nomial->head;
	//The while loop makes this O(N) for a list of length N
	while(current->power > node->power && current->next != NULL){
		current = current->next;
	}
	//this should bring us within one node of where we want to be. close enough.
	double diff = node->power - current->power;

	if(diff == 0){
		current->coeff+= node->coeff;
	}else{
		if(diff < 0){
			//new term should be added AFTER current term
			node->next = current->next;
			node->prev = current;
			current->next = node;
			if(node->next != NULL)
				node->next->prev = node;
		}else{
			node->next = current;
			node->prev = current->prev;
			current->prev = node;
			if(node->prev != NULL)
				node->prev->next = node;
		}
		nomial->termCount++;
	}
}

void RemoveTerm(double power, poly * nomial){
	//worst case: O(N)
	term * current = nomial->head;
	while(current != NULL && current->power != power){
		current = current->next;
	}

	if(current->prev != NULL)
		current->prev->next = current->next;
	if(current->next != NULL){
		current->next->prev = current->prev;
	}
	free(current);
	nomial->termCount--;
}

poly polySum(poly a, poly b){
	//O(N)
	poly result = NewPoly();
	term * current = a.head;
	while(current != NULL){
		AppendTerm(current, &result);
		current = current->next;
	}
	current = b.head;
	while(current != NULL){
		AppendTerm(current, &result);
		current = current->next;
	}
	return result;
}

poly polyDiff(poly a, poly b){
	// O(N)
	poly result = NewPoly();
	//returns a-b
	term * current = a.head;
		while(current != NULL){
			AppendTerm(current, &result);
			current = current->next;
		}
		current = b.head;
		while(current != NULL){
			AddTerm(-1 * current->coeff, current->power, &result);
			current = current->next;
		}

	return result;
}

poly polyPow(poly a, int pow){
	poly resultant = dupPoly(a);
	int i;
	for(i=0; i < pow-1; i++){
		resultant = polyProd(resultant, a);
	}

	return resultant;
}

poly polyProd(poly a, poly b){
	//worst case O(N^3)
	poly result = NewPoly();
	term * aTerm = a.head;
	term * bTerm = b.head;
	double coeff;
	double pow;
	while(aTerm != NULL){
		while (bTerm != NULL){
			coeff = aTerm->coeff * bTerm->coeff;
			pow = aTerm->power + bTerm->power;
			AddTerm(coeff, pow, &result); // O(N)
			bTerm = bTerm->next;
		}
		bTerm = b.head;
		aTerm = aTerm->next;
	}
	//TODO: MAKE polyProd functional
	return result;
}

poly polyQuot(poly a, poly b){
	poly result = NewPoly();

	//TODO: MAKE polyQuot functional
	return result;
}

double * polyRoots(poly p){
	double * results;

	//TODO: MAKE polyRoots functional
	return results;
}

void printPoly(poly nomial){
	term * current = nomial.head;
	if(current == NULL){
		printf("ERROR: FIRST NODE NULL");
	}else{
		printf("%s", "(");
		while(current != NULL){
			printf("%s", (current==nomial.head)?"":" ");
				if(current->coeff>0 && current != nomial.head){
					printf("+ ");
				}
				printTerm(current);
			current = current->next;
		}
		printf("%s", ")");
	}

}
void printTerm(term * node){

	char varName[] = "X";
	if(node->coeff !=0){
		if(node->coeff == 1){
			if(node->power==0){
				printf("1");
			}
		}
		else if((node->coeff-(int)node->coeff)==0){
			printf("%.0lf", node->coeff);
		}else{
			printf("%.3lf", node->coeff);
		}
	}

	//printf("%.2lf", node->coeff);
	if(node->power !=0){
		if(node->power == 1){
			printf("%s", varName);
		}
		else if((node->power-(int)node->power)==0){
			printf("%s%s%.0lf", varName,"^", node->power);
		}else{
			printf("%s%s%.2lf", varName,"^", node->power);
		}
	}
}
