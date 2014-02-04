#include "Vect3.h"

Vector3::Vector3()
{
}

Vector3::Vector3(float newX, float newY, float newZ)
{
	x = newX; 
	y = newY; 
	z = newZ; 
}

Vector3::~Vector3()
{
}

////////////////////////////////////////////////////////////////////////VECTOR 3 FUNCTIONS
float Vector3::Magnitude()
{
	return sqrt ((x*x) + (y*y) + (z*z));
}

Vector3 Vector3::GetNormal(Vector3 &v)
{
	float mag = sqrt ((v.x*v.x) + (v.y*v.y) + (v.z*v.z)); 
	Vector3 result(v.x/mag, v.y/mag, v.z/mag); 
	return result; 
}

Vector3 Vector3::Normalise(Vector3 &v)
{
	float mag = sqrt ((x*x) + (y*y) + (z*z)); 
	Vector3 normVector(v.x/mag, v.y/mag, v.z/mag); 
	return normVector;
}

float Vector3::DotProduct(Vector3 &b)
{
	return (x*b.x) + (y*b.y) + (z*b.z);
}

Vector3 Vector3::CrossProduct(Vector3 &a, Vector3 &c)
{
	Vector3 cpV3(y*c.z - z*c.y, z*c.x - x*c.z, x*c.y - y*c.x); 
	return cpV3;
}

float Vector3::EulerAngle(Vector3 &a, Vector3 &b)
{
	float scalar = Vector3::DotProduct(b); 
	float aMag = Vector3::Magnitude(); 
	float bMag = Vector3::Magnitude(); 
	float timeMag = aMag * bMag; 

	float angle = acosf(scalar/timeMag); 
	return angle; 
}

Vector3 Vector3::m_TransformVector3(Matrix3 &w)
{
	Vector3 b;
	b.x = x * w.a_fMatricesMatrix2D[0][0] + y * w.a_fMatricesMatrix2D[1][0] + z * w.a_fMatricesMatrix2D[2][0]; 
	b.y = x * w.a_fMatricesMatrix2D[0][1] + y * w.a_fMatricesMatrix2D[1][1] + z * w.a_fMatricesMatrix2D[2][1];
	b.z = x * w.a_fMatricesMatrix2D[0][2] + y * w.a_fMatricesMatrix2D[1][2] + z * w.a_fMatricesMatrix2D[2][2]; 
	return b; 
}

Vector3 Vector3::Scale(Matrix3 &tempM)
{
	Vector3 temp;
	temp.x =  x * tempM.a_fMatricesMatrix2D[0][0] +  y * 0 +  z * 0;
	temp.y =  x * 0 +  y * tempM.a_fMatricesMatrix2D[1][1] +	 z * 0;
	temp.z =  x * 0 +  y * 0 +  z * tempM.a_fMatricesMatrix2D[2][2];
	return temp;
}