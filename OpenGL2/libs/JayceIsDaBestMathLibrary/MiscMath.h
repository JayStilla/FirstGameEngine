#ifndef _MISCMATH_H_
#define _MISCMATH_H_

#define _USE_MATH_DEFINES
#include "math.h"
#include "Vect3.h"

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT CommonMath
{
public:
	float x; 
	int y; 
	float z; 
	float Pow2(float x, int y); 
	float m_RadianConvert(float b);
	float m_degreeConvert(float b); 
	Vector3 m_Lerp(Vector3 &a, Vector3 &b, float tx);

};




#endif