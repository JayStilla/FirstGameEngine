#include "MiscMath.h"

float CommonMath::Pow2(float x, int y)
{
	z =pow(x,y); 
	return z; 
}

float CommonMath::m_RadianConvert(float b)
{
	float a = (b/180)*M_PI; 
	return a; 
}

float CommonMath::m_degreeConvert(float b)
{
	float a = (b*180)/M_PI; 
	return a; 
}

Vector3 CommonMath::m_Lerp(Vector3 &a, Vector3 &b, float tx)
{

	//A and B are two points while tx is the normalized vector
	Vector3 Lerp = (a + ( b - a ) * tx ); 
	return Lerp; 
}

