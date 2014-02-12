#ifndef _MATRIX3_H_
#define _MATRIX3_H_
#include <iostream>

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

using namespace std; 

class DLLEXPORT Matrix3
{
public:
	float a_fMatricesMatrix2D [3][3];
	Matrix3 m_TranslationXY(float x, float y);

	Matrix3 operator*(Matrix3 &w);
		inline friend ostream& operator<< (ostream &os, const Matrix3 &Mat3)
	{
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				os<< Mat3.a_fMatricesMatrix2D[i][j]<< " "; 
			}
			os << endl; 
		}
		return os; 
	}
};



#endif