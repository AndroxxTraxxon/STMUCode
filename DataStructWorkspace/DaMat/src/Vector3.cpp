/*
 * Vector3.cpp
 *
 *  Created on: Jan 25, 2016
 *      Author: david
 */

#include "Vector3.h"

Vector3::Vector3(double x, double y, double z) {
	initVars(x,y,z);
}

Vector3::~Vector3() {
	// TODO Auto-generated destructor stub
	initVars(0,0,0);
}

Vector3 Vector3::i(){
	return Vector3(1,0,0);
}

Vector3 Vector3::j(){
	return Vector3(0,1,0);
}

Vector3 Vector3::k(){
	return Vector3(0,0,1);
}

void Vector3::initVars(double i, double j, double k){
	x = i;
	y = j;
	z = k;
}

Vector3 Vector3::clone(Vector3 original){
	Vector3 theNewOne = Vector3(original.x, original.y, original.z);
	return theNewOne;

}

Vector3 Vector3::diff(Vector3 a, Vector3 b){
	Vector3 c = clone(a);
	c.x -= b.x;
	c.y -= b.y;
	c.z -= b.z;
	return c;
}
