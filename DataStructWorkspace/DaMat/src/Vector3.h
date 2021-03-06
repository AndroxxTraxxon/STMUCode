/*
 * Vector3.h
 *
 *  Created on: Jan 25, 2016
 *      Author: david
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

class Vector3 {
public:
	double x,y,z;
	static Vector3 i();
	static Vector3 j();
	static Vector3 k();
	Vector3();
	Vector3(double x, double y, double z);
	virtual ~Vector3();
	static Vector3 crossP(Vector3 a, Vector3 b);
	static double dotP(Vector3 a, Vector3 b);
	Vector3 clone(Vector3 original);
	Vector3 diff(Vector3 a, Vector3 b);

private:
	void initVars(double i, double j, double k);
};

#endif /* VECTOR3_H_ */
