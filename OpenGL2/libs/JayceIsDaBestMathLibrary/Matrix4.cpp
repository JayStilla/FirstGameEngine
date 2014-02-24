#include "Matrix4.h"
#include "MiscMath.h"
#include "math.h"

Matrix4::Matrix4()
{
}

Matrix4::~Matrix4()
{
}

Matrix4 Matrix4::operator=(Matrix4 &w)
{
	for(int i = 0; i < 16; i++)
	{
		a_fMatricesMatrix3D[i] = w.a_fMatricesMatrix3D[i]; 
	}
	return *this; 
}

Matrix4 Matrix4::operator*(Matrix4 &w)
{
	Matrix4 temp;
	//column 0
	temp.a_fMatricesMatrix3D[0] = w.a_fMatricesMatrix3D[0] * a_fMatricesMatrix3D[0] + 
								w.a_fMatricesMatrix3D[4] * a_fMatricesMatrix3D[1] + 
								w.a_fMatricesMatrix3D[8] * a_fMatricesMatrix3D[2] + 
								w.a_fMatricesMatrix3D[12] * a_fMatricesMatrix3D[3];

	temp.a_fMatricesMatrix3D[4] = w.a_fMatricesMatrix3D[0] * a_fMatricesMatrix3D[4] + 
								w.a_fMatricesMatrix3D[4] * a_fMatricesMatrix3D[5] + 
								w.a_fMatricesMatrix3D[8] * a_fMatricesMatrix3D[6] + 
								w.a_fMatricesMatrix3D[12] * a_fMatricesMatrix3D[7]; 
	temp.a_fMatricesMatrix3D[8] = w.a_fMatricesMatrix3D[0] * a_fMatricesMatrix3D[8]; 
								w.a_fMatricesMatrix3D[4] * a_fMatricesMatrix3D[9] + 
								w.a_fMatricesMatrix3D[8] * a_fMatricesMatrix3D[10] +
								w.a_fMatricesMatrix3D[12] * a_fMatricesMatrix3D[11];
	temp.a_fMatricesMatrix3D[12] = w.a_fMatricesMatrix3D[0] * a_fMatricesMatrix3D[12] + 
								w.a_fMatricesMatrix3D[4] * a_fMatricesMatrix3D[13] + 
								w.a_fMatricesMatrix3D[8] * a_fMatricesMatrix3D[14] + 
								w.a_fMatricesMatrix3D[12] * a_fMatricesMatrix3D[15]; 
	//column 1 
	temp.a_fMatricesMatrix3D[1] = w.a_fMatricesMatrix3D[1] * a_fMatricesMatrix3D[0] + 
								w.a_fMatricesMatrix3D[5] * a_fMatricesMatrix3D[1] + 
								w.a_fMatricesMatrix3D[9] * a_fMatricesMatrix3D[2] + 
								w.a_fMatricesMatrix3D[13] * a_fMatricesMatrix3D[3]; 
	temp.a_fMatricesMatrix3D[5] = w.a_fMatricesMatrix3D[1] * a_fMatricesMatrix3D[4] + 
								w.a_fMatricesMatrix3D[5] * a_fMatricesMatrix3D[5] + 
								w.a_fMatricesMatrix3D[9] * a_fMatricesMatrix3D[6] + 
								w.a_fMatricesMatrix3D[13] * a_fMatricesMatrix3D[7]; 
	temp.a_fMatricesMatrix3D[9] = w.a_fMatricesMatrix3D[1] * a_fMatricesMatrix3D[8] + 
								w.a_fMatricesMatrix3D[5] * a_fMatricesMatrix3D[9] + 
								w.a_fMatricesMatrix3D[9] * a_fMatricesMatrix3D[10] + 
								w.a_fMatricesMatrix3D[13] * a_fMatricesMatrix3D[11]; 
	temp.a_fMatricesMatrix3D[13] = w.a_fMatricesMatrix3D[1] * a_fMatricesMatrix3D[12] + 
								w.a_fMatricesMatrix3D[5] * a_fMatricesMatrix3D[13] + 
								w.a_fMatricesMatrix3D[9] * a_fMatricesMatrix3D[14] + 
								w.a_fMatricesMatrix3D[13] * a_fMatricesMatrix3D[15]; 
	//column 2
	temp.a_fMatricesMatrix3D[2] = w.a_fMatricesMatrix3D[2] * a_fMatricesMatrix3D[0] + 
								w.a_fMatricesMatrix3D[6] * a_fMatricesMatrix3D[1] + 
								w.a_fMatricesMatrix3D[10] * a_fMatricesMatrix3D[2] + 
								w.a_fMatricesMatrix3D[14] * a_fMatricesMatrix3D[3];  
	temp.a_fMatricesMatrix3D[6] = w.a_fMatricesMatrix3D[2] * a_fMatricesMatrix3D[4] + 
								w.a_fMatricesMatrix3D[6] * a_fMatricesMatrix3D[5] + 
								w.a_fMatricesMatrix3D[10] * a_fMatricesMatrix3D[6] + 
								w.a_fMatricesMatrix3D[14] * a_fMatricesMatrix3D[7]; 
	temp.a_fMatricesMatrix3D[10] = w.a_fMatricesMatrix3D[2] * a_fMatricesMatrix3D[8] + 
								w.a_fMatricesMatrix3D[6] * a_fMatricesMatrix3D[9] + 
								w.a_fMatricesMatrix3D[10] * a_fMatricesMatrix3D[10] + 
								w.a_fMatricesMatrix3D[14] * a_fMatricesMatrix3D[11]; 
	temp.a_fMatricesMatrix3D[14] = w.a_fMatricesMatrix3D[2] * a_fMatricesMatrix3D[12] + 
								w.a_fMatricesMatrix3D[6] * a_fMatricesMatrix3D[13] + 
								w.a_fMatricesMatrix3D[10] * a_fMatricesMatrix3D[14] + 
								w.a_fMatricesMatrix3D[14] * a_fMatricesMatrix3D[15]; 
	//column 3
	temp.a_fMatricesMatrix3D[3] = w.a_fMatricesMatrix3D[3] * a_fMatricesMatrix3D[0] + 
								w.a_fMatricesMatrix3D[7] * a_fMatricesMatrix3D[1] + 
								w.a_fMatricesMatrix3D[11] * a_fMatricesMatrix3D[2] + 
								w.a_fMatricesMatrix3D[15] * a_fMatricesMatrix3D[3]; 
	temp.a_fMatricesMatrix3D[7] = w.a_fMatricesMatrix3D[3] * a_fMatricesMatrix3D[4] + 
								w.a_fMatricesMatrix3D[7] * a_fMatricesMatrix3D[5] + 
								w.a_fMatricesMatrix3D[11] * a_fMatricesMatrix3D[6] + 
								w.a_fMatricesMatrix3D[15] * a_fMatricesMatrix3D[7];
	temp.a_fMatricesMatrix3D[11] = w.a_fMatricesMatrix3D[3] * a_fMatricesMatrix3D[8] + 
								w.a_fMatricesMatrix3D[7] * a_fMatricesMatrix3D[9] + 
								w.a_fMatricesMatrix3D[11] * a_fMatricesMatrix3D[10] + 
								w.a_fMatricesMatrix3D[15] * a_fMatricesMatrix3D[11]; 
	temp.a_fMatricesMatrix3D[15] = w.a_fMatricesMatrix3D[3] * a_fMatricesMatrix3D[12] + 
								w.a_fMatricesMatrix3D[7] * a_fMatricesMatrix3D[13] + 
								w.a_fMatricesMatrix3D[11] * a_fMatricesMatrix3D[14] + 
								w.a_fMatricesMatrix3D[15] * a_fMatricesMatrix3D[15]; 

	return temp;
}

//BUILDING X ROTATION////////////////////////////
Matrix4 Matrix4::m_RotationX(float rot)
{
	phi = rot; 
	Matrix4 RotationX;
	//ROW 0
	RotationX.a_fMatricesMatrix3D[0] = 1; 
	RotationX.a_fMatricesMatrix3D[4] = 0; 
	RotationX.a_fMatricesMatrix3D[8] = 0; 
	RotationX.a_fMatricesMatrix3D[12] = 0; 
	//ROW 1
	RotationX.a_fMatricesMatrix3D[1] = 0; 
	RotationX.a_fMatricesMatrix3D[5] = cos(phi); 
	RotationX.a_fMatricesMatrix3D[9] = -sin(phi); 
	RotationX.a_fMatricesMatrix3D[13] = 0; 
	//ROW 2
	RotationX.a_fMatricesMatrix3D[2] = 0; 
	RotationX.a_fMatricesMatrix3D[6] = sin(phi); 
	RotationX.a_fMatricesMatrix3D[10] = cos(phi); 
	RotationX.a_fMatricesMatrix3D[14] = 0; 
	//ROW 3
	RotationX.a_fMatricesMatrix3D[3] = 0; 
	RotationX.a_fMatricesMatrix3D[7] = 0; 
	RotationX.a_fMatricesMatrix3D[11] = 0; 
	RotationX.a_fMatricesMatrix3D[15] = 1; 

	return RotationX; 

}

//BUILDING Y ROTATION//////////////////////////////////
Matrix4 Matrix4::m_RotationY(float rot)
{
	theta = rot; 
	Matrix4 RotationY; 
	//ROW 0	
	RotationY.a_fMatricesMatrix3D[0] = cos(theta); 
	RotationY.a_fMatricesMatrix3D[4] = 0; 
	RotationY.a_fMatricesMatrix3D[8] = sin(theta); 
	RotationY.a_fMatricesMatrix3D[12] = 0; 
	//ROW 1
	RotationY.a_fMatricesMatrix3D[1] = 0; 
	RotationY.a_fMatricesMatrix3D[5] = 1; 
	RotationY.a_fMatricesMatrix3D[9] = 0; 
	RotationY.a_fMatricesMatrix3D[13] = 0; 
	//ROW 2 
	RotationY.a_fMatricesMatrix3D[2] = -sin(theta); 
	RotationY.a_fMatricesMatrix3D[6] = 0; 
	RotationY.a_fMatricesMatrix3D[10] = cos(theta); 
	RotationY.a_fMatricesMatrix3D[14] = 0; 
	//ROW 3
	RotationY.a_fMatricesMatrix3D[3] = 0; 
	RotationY.a_fMatricesMatrix3D[7] = 0; 
	RotationY.a_fMatricesMatrix3D[11] = 0; 
	RotationY.a_fMatricesMatrix3D[15] = 1; 
	return RotationY; 

}

//BUILDING Z ROTATION///////////////////////////////////////
Matrix4 Matrix4::m_RotationZ(float rot)
{
	rot = psi; 
	Matrix4 RotationZ; 
	//ROW 0 
	RotationZ.a_fMatricesMatrix3D[0] = cos(psi); 
	RotationZ.a_fMatricesMatrix3D[4] = -sin(psi); 
	RotationZ.a_fMatricesMatrix3D[8] = 0; 
	RotationZ.a_fMatricesMatrix3D[12] = 0; 
	//ROW 1
	RotationZ.a_fMatricesMatrix3D[1] = sin(psi); 
	RotationZ.a_fMatricesMatrix3D[5] = cos(psi); 
	RotationZ.a_fMatricesMatrix3D[9] = 0; 
	RotationZ.a_fMatricesMatrix3D[13] = 0; 
	//ROW 2
	RotationZ.a_fMatricesMatrix3D[2] = 0; 
	RotationZ.a_fMatricesMatrix3D[6] = 0; 
	RotationZ.a_fMatricesMatrix3D[10] = 1; 
	RotationZ.a_fMatricesMatrix3D[14] = 0; 
	//ROW 3
	RotationZ.a_fMatricesMatrix3D[3] = 0; 
	RotationZ.a_fMatricesMatrix3D[7] = 0; 
	RotationZ.a_fMatricesMatrix3D[11] = 0; 
	RotationZ.a_fMatricesMatrix3D[15] = 1; 
	return RotationZ; 
}

//BUILDING XYZ TRANSLATION///////////////////////////////////////
Matrix4 Matrix4::m_TranslationXYZ(float x, float y, float z)
{
	Matrix4 TranslationXYZ;
	//ROW 0 
	TranslationXYZ.a_fMatricesMatrix3D[0] = 1; 
	TranslationXYZ.a_fMatricesMatrix3D[4] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[8] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[12] = x; 
	//ROW 1
	TranslationXYZ.a_fMatricesMatrix3D[1] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[5] = 1; 
	TranslationXYZ.a_fMatricesMatrix3D[9] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[13] = y; 
	//ROW 2
	TranslationXYZ.a_fMatricesMatrix3D[2] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[6] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[10] = 1; 
	TranslationXYZ.a_fMatricesMatrix3D[14] = z; 
	//ROW 3
	TranslationXYZ.a_fMatricesMatrix3D[3] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[7] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[11] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[15] = 1; 
	return TranslationXYZ;  
}

Matrix4 Matrix4::m_OrthoProjection(float l, float r, float b, float n, float f, float t)
{
	Matrix4 mat; 
	mat.a_fMatricesMatrix3D[0] = 2 * n / (r - 1); 
	mat.a_fMatricesMatrix3D[4] = 0; 
	mat.a_fMatricesMatrix3D[8] = 0;
    mat.a_fMatricesMatrix3D[12] = 0;
 
    mat.a_fMatricesMatrix3D[1] = 0;
    mat.a_fMatricesMatrix3D[5] = 2 * n / (t - b);
    mat.a_fMatricesMatrix3D[9] = 0;
    mat.a_fMatricesMatrix3D[13] = 0;
 
    mat.a_fMatricesMatrix3D[2] = (r + l) / (r - l);
    mat.a_fMatricesMatrix3D[6] = (t + b) / (t - b);
    mat.a_fMatricesMatrix3D[10] = -(f + n) / (f - n);
    mat.a_fMatricesMatrix3D[14] = -1;
 
    mat.a_fMatricesMatrix3D[3] = 0;
    mat.a_fMatricesMatrix3D[7] = 0;
    mat.a_fMatricesMatrix3D[11] = -2 * f * n / (f - n);
    mat.a_fMatricesMatrix3D[15] = 0;

	return mat; 
}

void Matrix4::m_OrthoVariables(float angle, float imageAspectRatio, float n, float f)
{
	Matrix4 mat;
	CommonMath RadCon;
	float scale = tan(RadCon.m_RadianConvert(angle * 0.5)) *n; 
	float r = imageAspectRatio * scale, l = -r; 
	float t = scale, b = -t; 
	Matrix4::m_OrthoProjection(l, r, b, n, f, t); 
}

Matrix4 Matrix4::m_CreateIdentity()
{
	//BUILDING AN IDENTITY MATRIX
	Matrix4 Identity;
	//ROW 0
	Identity.a_fMatricesMatrix3D[0] = 1;
	Identity.a_fMatricesMatrix3D[4] = 0;
	Identity.a_fMatricesMatrix3D[8] = 0;
	Identity.a_fMatricesMatrix3D[12] = 0;
	//ROW 1
	Identity.a_fMatricesMatrix3D[1] = 0;
	Identity.a_fMatricesMatrix3D[5] = 1; 
	Identity.a_fMatricesMatrix3D[9] = 0;
	Identity.a_fMatricesMatrix3D[13] = 0;
	//ROW 2
	Identity.a_fMatricesMatrix3D[2] = 0; 
	Identity.a_fMatricesMatrix3D[6] = 0; 
	Identity.a_fMatricesMatrix3D[10] = 1;
	Identity.a_fMatricesMatrix3D[14] = 0;
	//Row 3
	Identity.a_fMatricesMatrix3D[3] = 0;
	Identity.a_fMatricesMatrix3D[7] = 0; 
	Identity.a_fMatricesMatrix3D[11] = 0; 
	Identity.a_fMatricesMatrix3D[15] = 1; 

	return Identity; 

}
