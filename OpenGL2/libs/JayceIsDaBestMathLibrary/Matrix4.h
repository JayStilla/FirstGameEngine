#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include <iostream>
#include "Vect3.h"
#include "Vect4.h"
using namespace std; 

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

//

class DLLEXPORT Matrix4
{
public:

	Matrix4(); 
	~Matrix4(); 

	float phi; 
	float theta; 
	float psi;

	float a_fMatricesMatrix3D [16];
	Matrix4 m_RotationX(float rot); 
	Matrix4 m_RotationY(float rot); 
	Matrix4 m_RotationZ(float rot); 
	Matrix4 m_TranslationXYZ(float x, float y, float z); 
	Matrix4 m_OrthoProjection(float l, float r, float b, float n, float f, float t); 
	void m_OrthoVariables(float angle, float imageAspectRatio, float n, float f); 
	Matrix4 m_CreateIdentity();
	Matrix4 operator*(Matrix4 &w);
	Matrix4 operator=(Matrix4 &w); 

	inline friend ostream& operator<< (ostream &os, const Matrix4 &Mat4)
	{
		for(int i=0; i<4; i++)
		{
				os<< Mat4.a_fMatricesMatrix3D[i]<< " "; 
			os << endl; 
		}
		return os; 
	}
};



#endif