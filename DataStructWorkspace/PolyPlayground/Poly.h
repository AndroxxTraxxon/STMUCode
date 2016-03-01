/*
 * Poly.h
 *
 *  Created on: Feb 29, 2016
 *      Author: david
 */

#ifndef POLY_H_
#define POLY_H_


typedef struct PolyTerm{
	double power;
	double coeff;
	struct PolyTerm * next;
	struct PolyTerm * prev;

}term;

typedef struct PolyString{
	int termCount;
	term * head;
	term polystr[];
}poly;

/*
 * 	NewPolyTerm: struct PolyTerm *
 * 	creates a new struct PolyTerm with the given coefficient and power, then returns its pointer.
 */
term * NewPolyTerm(double coeff, double power);

/*
 * 	NewPoly : struct PolyString
 * 	creates a new struct PolyString and returns it.
 */
poly NewPoly();


/*
 * 	AddTerm : void
 * 	adds a new term to an existing struct PolyString
 */
void AddTerm(double coeff, double power, poly nomial);

/*
 * 	RemoveTerm : void
 * 	removes the term from an existing struct PolyString that has the given power, if said PolyString
 * 	contains a term with that power.
 */
void RemoveTerm(double power, poly nomial);

/*
 *	polyProd : poly
 *	returns a new Polynomial that contains the product value of struct PolyString a and b
 */
poly polyProd(poly a, poly b);

/*
 *	polySum : poly
 *	returns a new Polynomial that contains the Sum value of struct PolyString a and b
 */
poly polySum(poly a, poly b);

/*
 * 	polyDiff : poly
 *	returns a new Polynomial that contains the difference value of struct PolyString a and b
 */
poly polyDiff(poly a, poly b);

/*
 *	polyQuot : poly
 *	returns a new Polynomial that contains the product value of struct PolyString a and b
 */
poly polyQuot(poly a, poly b);


/*
 *	polyRoots : double *
 *	returns a double array containing the roots of a polynomial.
 *	the first number of the array will be the number of roots (it will have integer value, despite being a double)
 *	the following numbers will contain the roots of the polynomial, in no particular order,
 *	such that an array structured as such [n, k1, k2, k3, ..., kn]
 *	will correspond to an the following product of sums: (x - k1)(x - k2)(x - k3)...(x - kn)
 */
double * polyRoots(poly p);



#endif /* POLY_H_ */
