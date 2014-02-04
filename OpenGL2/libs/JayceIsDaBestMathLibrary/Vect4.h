#ifndef _VECT4_H_
#define _VECT4_H_

#define _USE_MATH_DEFINES
#include "math.h"
#include <iostream>

using namespace std;

class Matrix4;

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT Vector4
{
public:
	Vector4();
	Vector4(float newX, float newY, float newZ, float newW); 
	~Vector4();
	float x; 
	float y; 
	float z; 
	float w; 

	float m_Magnitude();	
	Vector4 m_GetNormal(Vector4 &v); 
	Vector4 m_Normalise(Vector4 &v); 
	float m_DotProduct(Vector4 &b);  
	Vector4 m_RGBconverter(int hexValue);
	Vector4 m_TransformPoint(Matrix4 &c);
	Vector4 m_TransformVector4(Vector4 &a, Matrix4 &w);
	Vector4 Scale(Matrix4 &mat4);
	

	inline friend ostream& operator<< (ostream &os, const Vector4 &Vect4)
	{
		os << Vect4.x << " " << Vect4.y << " " << Vect4.z << " " << Vect4.w << " "; 

		return os; 
	}

};



#endif