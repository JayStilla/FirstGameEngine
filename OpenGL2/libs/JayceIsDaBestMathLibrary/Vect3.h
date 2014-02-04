#ifndef _VECT3_H_
#define _VECT3_H_

#define _USE_MATH_DEFINES
#include "math.h"
#include "Matrix3.h"

#ifdef DLL
        #define DLLEXPORT __declspec(dllexport)
#else
        #define DLLEXPORT __declspec(dllimport)
#endif

class DLLEXPORT Vector3
{
public:
	Vector3(); 
	Vector3(float newX, float newY, float newZ); 
	~Vector3(); 
	float x; 
	float y; 
	float z; 

	float Magnitude();
	Vector3 Normalise(Vector3 &v); 
	Vector3 GetNormal(Vector3 &v);
	float DotProduct(Vector3 &b); 
	float EulerAngle(Vector3 &a, Vector3 &b); 
	Vector3 CrossProduct(Vector3 &a, Vector3 &c);
	Vector3 m_TransformVector3(Matrix3 &w);
	Vector3 Scale(Matrix3 &TempM);

	Vector3 operator-(Vector3 &b)
	{
		Vector3 c; 
		c.x = x - b.x; 
		c.y = y - b.y; 
		c.z = z - b.z;
		return c; 
	}
	Vector3 operator*(Vector3 &b)
	{
		Vector3 c; 
		c.x = x * b.x; 
		c.y = y * b.y; 
		c.z = z * b.z; 
		return c; 
	}
	Vector3 operator*(float b)
	{
		Vector3 c; 
		c.x = b * x;
		c.y = b * y; 
		c.z = b * z; 
		return c;
	}
	Vector3 operator+(Vector3 b)
	{
		Vector3 c; 
		c.x = x + b.x; 
		c.y = y + b.y; 
		c.z = z + b.z; 
		return c; 
	}

	Vector3 operator +=(Vector3 b)
	{
		Vector3 pos; 
		pos.x = x += b.x; 
		pos.y = y += b.y;
		pos.z = z += b.z; 
		return pos; 
	}

	inline friend ostream& operator<< (ostream &os, const Vector3 &Vect3)
	{
		os << Vect3.x << " " << Vect3.y << " " << Vect3.z << " "; 

		return os; 
	}


};


#endif