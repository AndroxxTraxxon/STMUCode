/*
 * Vector3.h
 *
 *  Created on: Jan 24, 2016
 *      Author: david
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

typedef struct {
	double x;
	double y;
	double z;

}vector3;

vector3 i();
vector3 j();
vector3 k();
vector3 v3zero();

double v3Mag(vector3 v);
vector3 normalize(vector3 v);
double dotP(vector3 v1, vector3 v2);
vector3 crossP(vector3 v1, vector3 v2);
vector3 mkVector(double x, double y, double z);
vector3 cpVector(vector3 v);
vector3 sclVector(double scl, vector3 v);
vector3 addVector(vector3 v1, vector3 v2);
vector3 diffVector(vector3 v1, vector3 v2);
void printV(vector3 v);

#endif /* VECTOR3_H_ */
