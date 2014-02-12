#include "Vect4.h"
#include "Matrix4.h"

Vector4::Vector4()
{
}

Vector4::Vector4(float newX, float newY, float newZ, float newW)
{
	x = newX; 
	y = newY; 
	z = newZ; 
	w = newW; 
}

Vector4::~Vector4()
{
}

float Vector4::m_Magnitude()
{
	return sqrt ((x*x) + (y*y) + (z*z) + (w*w));
}

Vector4 Vector4::m_GetNormal(Vector4 &v)
{
	float mag = sqrt ((v.x*v.x)+(v.y*v.y)+(v.z*v.z)+(v.w*v.w));
	Vector4 normVector4(v.x/mag, v.y/mag, v.z/mag, v.w/mag);
	return normVector4;
}

Vector4 Vector4::m_Normalise(Vector4 &v)
{
	float mag = sqrt((x*x)+(y*y)+(z*z)+(w*w)); 
	Vector4 normaliseVector4(v.x/mag, v.y/mag, v.z/mag, v.w/mag); 
	return normaliseVector4;
}

float Vector4::m_DotProduct(Vector4 &b)
{
	return ((x*b.x)+(y*b.y)+(z*b.z)+(w*b.w));
}



Vector4 Vector4::m_RGBconverter(int hexValue)
{
	Vector4 RGBconverter; 
	RGBconverter.x = ((hexValue >> 24) & 0xFF)/255.0; 
	RGBconverter.y = ((hexValue >> 16 ) & 0xFF)/255.0; 
	RGBconverter.z = ((hexValue >> 8) & 0xFF)/255.0; 
	RGBconverter.w = (hexValue & 0xFF)/255.0; 

	return RGBconverter; 
}

Vector4 Vector4::m_TransformVector4(Vector4 &a, Matrix4 &w)
{
	Vector4 b; 
	b.x = a.x * w.a_fMatricesMatrix3D[0] + a.y * w.a_fMatricesMatrix3D[1] + a.z * w.a_fMatricesMatrix3D[2] + a.w * w.a_fMatricesMatrix3D[3];
	b.y = a.x * w.a_fMatricesMatrix3D[4] + a.y * w.a_fMatricesMatrix3D[5] + a.z * w.a_fMatricesMatrix3D[6] + a.w * w.a_fMatricesMatrix3D[7];
	b.z = a.x * w.a_fMatricesMatrix3D[8] + a.y * w.a_fMatricesMatrix3D[9] + a.z * w.a_fMatricesMatrix3D[10] + a.w * w.a_fMatricesMatrix3D[11]; 
	b.w = a.x * w.a_fMatricesMatrix3D[12] + a.y * w.a_fMatricesMatrix3D[13] + a.z * w.a_fMatricesMatrix3D[14] + a.w * w.a_fMatricesMatrix3D[15];
	return b; 
}

Vector4 Vector4::m_TransformPoint(Matrix4 &c)
{
	Vector4 b; 
	b.x = x * c.a_fMatricesMatrix3D[0] + y * c.a_fMatricesMatrix3D[1] + z * c.a_fMatricesMatrix3D[2] + w * c.a_fMatricesMatrix3D[3];
	b.y = x * c.a_fMatricesMatrix3D[4] + y * c.a_fMatricesMatrix3D[5] + z * c.a_fMatricesMatrix3D[6] + w * c.a_fMatricesMatrix3D[7]; 
	b.z = x * c.a_fMatricesMatrix3D[8] + y * c.a_fMatricesMatrix3D[9] + z * c.a_fMatricesMatrix3D[10] + w * c.a_fMatricesMatrix3D[11]; 
	b.w = x * c.a_fMatricesMatrix3D[12] + y * c.a_fMatricesMatrix3D[13] + z * c.a_fMatricesMatrix3D[14] + w * c.a_fMatricesMatrix3D[15]; 
	if(b.w != 1 && b.w !=0)
	{
		b.x /= b.w;
		b.y /= b.w; 
		b.z /= b.w;
	}
	return b; 
}
Vector4 Vector4::Scale(Matrix4 &mat4)
{
	Vector4 temp;
	temp.x = x * mat4.a_fMatricesMatrix3D[0] + y * 0 + z * 0 + w * 0;
	temp.y = x * 0 + y * mat4.a_fMatricesMatrix3D[5] + z * 0  + w * 0;
	temp.z = x * 0 + y * 0 + z * mat4.a_fMatricesMatrix3D[10] + w * 0;
	temp.w = x * 0 + y * 0 + z * 0 + w * mat4.a_fMatricesMatrix3D[15];
	return temp;
}
