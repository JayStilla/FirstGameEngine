#include "Matrix4.h"
#include "MiscMath.h"
#include "math.h"

//BUILDING X ROTATION////////////////////////////
Matrix4 Matrix4::m_RotationX(float rot)
{
	phi = rot; 
	Matrix4 RotationX;
	//ROW 0
	RotationX.a_fMatricesMatrix3D[0][0] = 1; 
	RotationX.a_fMatricesMatrix3D[0][1] = 0; 
	RotationX.a_fMatricesMatrix3D[0][2] = 0; 
	RotationX.a_fMatricesMatrix3D[0][3] = 0; 
	//ROW 1
	RotationX.a_fMatricesMatrix3D[1][0] = 0; 
	RotationX.a_fMatricesMatrix3D[1][1] = cos(phi); 
	RotationX.a_fMatricesMatrix3D[1][2] = -sin(phi); 
	RotationX.a_fMatricesMatrix3D[1][3] = 0; 
	//ROW 2
	RotationX.a_fMatricesMatrix3D[2][0] = 0; 
	RotationX.a_fMatricesMatrix3D[2][1] = sin(phi); 
	RotationX.a_fMatricesMatrix3D[2][2] = cos(phi); 
	RotationX.a_fMatricesMatrix3D[2][3] = 0; 
	//ROW 3
	RotationX.a_fMatricesMatrix3D[3][0] = 0; 
	RotationX.a_fMatricesMatrix3D[3][1] = 0; 
	RotationX.a_fMatricesMatrix3D[3][2] = 0; 
	RotationX.a_fMatricesMatrix3D[3][3] = 1; 

	return RotationX; 

}

//BUILDING Y ROTATION//////////////////////////////////
Matrix4 Matrix4::m_RotationY(float rot)
{
	theta = rot; 
	Matrix4 RotationY; 
	//ROW 0	
	RotationY.a_fMatricesMatrix3D[0][0] = cos(theta); 
	RotationY.a_fMatricesMatrix3D[0][1] = 0; 
	RotationY.a_fMatricesMatrix3D[0][2] = sin(theta); 
	RotationY.a_fMatricesMatrix3D[0][3] = 0; 
	//ROW 1
	RotationY.a_fMatricesMatrix3D[1][0] = 0; 
	RotationY.a_fMatricesMatrix3D[1][1] = 1; 
	RotationY.a_fMatricesMatrix3D[1][2] = 0; 
	RotationY.a_fMatricesMatrix3D[1][3] = 0; 
	//ROW 2 
	RotationY.a_fMatricesMatrix3D[2][0] = -sin(theta); 
	RotationY.a_fMatricesMatrix3D[2][1] = 0; 
	RotationY.a_fMatricesMatrix3D[2][2] = cos(theta); 
	RotationY.a_fMatricesMatrix3D[2][3] = 0; 
	//ROW 3
	RotationY.a_fMatricesMatrix3D[3][0] = 0; 
	RotationY.a_fMatricesMatrix3D[3][1] = 0; 
	RotationY.a_fMatricesMatrix3D[3][2] = 0; 
	RotationY.a_fMatricesMatrix3D[3][3] = 1; 
	return RotationY; 

}

//BUILDING Z ROTATION///////////////////////////////////////
Matrix4 Matrix4::m_RotationZ(float rot)
{
	rot = psi; 
	Matrix4 RotationZ; 
	//ROW 0 
	RotationZ.a_fMatricesMatrix3D[0][0] = cos(psi); 
	RotationZ.a_fMatricesMatrix3D[0][1] = -sin(psi); 
	RotationZ.a_fMatricesMatrix3D[0][2] = 0; 
	RotationZ.a_fMatricesMatrix3D[0][3] = 0; 
	//ROW 1
	RotationZ.a_fMatricesMatrix3D[1][0] = sin(psi); 
	RotationZ.a_fMatricesMatrix3D[1][1] = cos(psi); 
	RotationZ.a_fMatricesMatrix3D[1][2] = 0; 
	RotationZ.a_fMatricesMatrix3D[1][3] = 0; 
	//ROW 2
	RotationZ.a_fMatricesMatrix3D[2][0] = 0; 
	RotationZ.a_fMatricesMatrix3D[2][1] = 0; 
	RotationZ.a_fMatricesMatrix3D[2][2] = 1; 
	RotationZ.a_fMatricesMatrix3D[2][3] = 0; 
	//ROW 3
	RotationZ.a_fMatricesMatrix3D[3][0] = 0; 
	RotationZ.a_fMatricesMatrix3D[3][1] = 0; 
	RotationZ.a_fMatricesMatrix3D[3][2] = 0; 
	RotationZ.a_fMatricesMatrix3D[3][3] = 1; 
	return RotationZ; 
}

//BUILDING XYZ TRANSLATION///////////////////////////////////////
Matrix4 Matrix4::m_TranslationXYZ(float x, float y, float z)
{
	Matrix4 TranslationXYZ;
	//ROW 0 
	TranslationXYZ.a_fMatricesMatrix3D[0][0] = 1; 
	TranslationXYZ.a_fMatricesMatrix3D[0][1] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[0][2] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[0][3] = x; 
	//ROW 1
	TranslationXYZ.a_fMatricesMatrix3D[1][0] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[1][1] = 1; 
	TranslationXYZ.a_fMatricesMatrix3D[1][2] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[1][3] = y; 
	//ROW 2
	TranslationXYZ.a_fMatricesMatrix3D[2][0] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[2][1] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[2][2] = 1; 
	TranslationXYZ.a_fMatricesMatrix3D[2][3] = z; 
	//ROW 3
	TranslationXYZ.a_fMatricesMatrix3D[3][0] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[3][1] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[3][2] = 0; 
	TranslationXYZ.a_fMatricesMatrix3D[3][3] = 1; 
	return TranslationXYZ;  
}

Matrix4 Matrix4::m_OrthoProjection(float l, float r, float b, float n, float f, float t)
{
	Matrix4 mat; 
	mat.a_fMatricesMatrix3D[0][0] = 2 * n / (r - 1); 
	mat.a_fMatricesMatrix3D[0][1] = 0; 
	mat.a_fMatricesMatrix3D[0][2] = 0;
    mat.a_fMatricesMatrix3D[0][3] = 0;
 
    mat.a_fMatricesMatrix3D[1][0] = 0;
    mat.a_fMatricesMatrix3D[1][1] = 2 * n / (t - b);
    mat.a_fMatricesMatrix3D[1][2] = 0;
    mat.a_fMatricesMatrix3D[1][3] = 0;
 
    mat.a_fMatricesMatrix3D[2][0] = (r + l) / (r - l);
    mat.a_fMatricesMatrix3D[2][1] = (t + b) / (t - b);
    mat.a_fMatricesMatrix3D[2][2] = -(f + n) / (f - n);
    mat.a_fMatricesMatrix3D[2][3] = -1;
 
    mat.a_fMatricesMatrix3D[3][0] = 0;
    mat.a_fMatricesMatrix3D[3][1] = 0;
    mat.a_fMatricesMatrix3D[3][2] = -2 * f * n / (f - n);
    mat.a_fMatricesMatrix3D[3][3] = 0;

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


