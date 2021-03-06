/*
 * vector3.c
 *
 *  Created on: Jan 24, 2016
 *      Author: david
 */

#include "vector3.h"
#include "string.h"
#include <math.h>
#include <stdio.h>

double v3Mag(vector3 v){
	return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

vector3 cpVector(vector3 v)
//returns a vector that is a copy of v
{
	vector3 copy;
	copy.x = v.x;
	copy.y = v.y;
	copy.z = v.z;
	return copy;
}

vector3 normalize(vector3 v)
//returns a vector in the same direction as v
//with a magnitude of 1
{
	vector3 normalized = sclVector(1/v3Mag(v), v);
	return normalized;
}

vector3 mkVector(double x, double y, double z)
//makes a new vector
{
	vector3 v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}

vector3 sclVector(double scl, vector3 v)
//returns vector v multiplied by a scale of scl
{
	vector3 cp = cpVector(v);
	cp.x *= scl;
	cp.y *= scl;
	cp.z *= scl;
	return cp;
}
vector3 addVector(vector3 v1, vector3 v2)
//returns v1 + v2
{
	vector3 v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return v;
}

vector3 diffVector(vector3 v1, vector3 v2)
//returns v1-v2
{
	vector3 v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return v;
}

vector3 i(){
	vector3 v;
	v.x = 1;
	v.y = 0;
	v.z = 0;
	return v;
}
vector3 j(){
	vector3 v;
	v.x = 0;
	v.y = 1;
	v.z = 0;
	return v;
}
vector3 k(){
	vector3 v;
	v.x = 0;
	v.y = 0;
	v.z = 1;
	return v;
}

vector3 v3zero(){
	vector3 v;
	v.x = 0;
	v.y = 0;
	v.z = 0;
	return v;
}


double dotP(vector3 v1, vector3 v2){

	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
vector3 crossP(vector3 v1, vector3 v2){
	vector3 out;
	out.x =v1.y * v2.z - v2.y * v1.z;
	out.y =v2.x * v1.z - v1.x * v2.z;
	out.z =v1.x * v2.y - v2.x * v1.y;
	return out;
}

void printV(vector3 v){

	printf("<%.4lf, %.4lf, %.4lf>", v.x, v.y, v.z);
}

