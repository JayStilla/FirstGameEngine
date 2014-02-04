#ifndef _VECT2_H_
#define _VECT2_H_

#include <iostream>
using namespace std; 

#define _USE_MATH_DEFINES
#include "math.h" 

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

//////////////////////////////////VECTOR CLASS
class DLLEXPORT Vectors
{
public: 
	Vectors(); 
	Vectors(float newX, float newY); 
	~Vectors();

	float x; 
	float y; 


	Vectors pointSubtract(Vectors &v, float s); 
	Vectors pointAdd(Vectors &v, float s); 
	Vectors multiplyScalar(Vectors &v, float s); 
	Vectors pointSubtract(Vectors &v, Vectors &v2); 
	Vectors pointAdd(Vectors &v, Vectors &v2); 
	Vectors getNormal(Vectors &v); 
	float getMagnitude(Vectors &v); 

	inline friend ostream& operator<< (ostream &os, const Vectors &V2)
	{
		os << V2.x << " " << V2.y << " "; 
		
		return os; 
	}


};



#endif