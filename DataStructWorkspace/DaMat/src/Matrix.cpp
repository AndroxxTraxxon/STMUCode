/*
 * Matrix.cpp
 *
 *  Created on: Jan 25, 2016
 *      Author: david
 */

#include "Matrix.h"

#include <vector>
using namespace std;

namespace DaMat{

	template<typename T> class Matrix{
		int dimensions[];
		int dimensionCount;

		Matrix<T> (typename C, int[] sizes) {
			int i = 0;
			while(sizes[i++] > 0);
			dimensionCount = i;
			malloc()
			for(i=0; i < dimensionCount;i++){

			}
			// TODO Auto-generated constructor stub

		}

		Matrix<T>()

		~Matrix<T>() {
			// TODO Auto-generated destructor stub
		}
	};

}
