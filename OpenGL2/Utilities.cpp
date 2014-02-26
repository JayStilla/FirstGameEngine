#include "Utilities.h"


int g_gl_width = 1280;
int g_gl_height = 720;

Matrix4 * Ortho; 
void Orthographic(float a_fLeft, float a_fRight, float a_fTop, float a_fBottom, float a_fNear, float a_fFar, Matrix4 * mat)
{
	float deltaX = a_fRight - a_fLeft; 
	float deltaY = a_fTop - a_fBottom; 
	float deltaZ = a_fNear - a_fFar; 

	mat->a_fMatricesMatrix3D[0] = 2.0f/deltaX;
	mat->a_fMatricesMatrix3D[1] = 0.0f; 
	mat->a_fMatricesMatrix3D[2] = 0.0f;
	mat->a_fMatricesMatrix3D[3] = 0.0f; 

	mat->a_fMatricesMatrix3D[4] = 0.0f; 
	mat->a_fMatricesMatrix3D[5] = 2.0f/ deltaY; 
	mat->a_fMatricesMatrix3D[6] = 0.0f; 
	mat->a_fMatricesMatrix3D[7] = 0.0f; 

	mat->a_fMatricesMatrix3D[8] = 0.0f; 
	mat->a_fMatricesMatrix3D[9] = 0.0f; 
	mat->a_fMatricesMatrix3D[10] = 2.0f / deltaZ; 
	mat->a_fMatricesMatrix3D[11] = 0.0f; 

	mat->a_fMatricesMatrix3D[12] = ((a_fLeft + a_fRight)/(a_fLeft - a_fRight)); 
	mat->a_fMatricesMatrix3D[13] = ((a_fBottom + a_fTop)/(a_fBottom - a_fTop));
	mat->a_fMatricesMatrix3D[14] = (-(a_fNear + a_fFar)/(a_fFar - a_fNear)); 
	mat->a_fMatricesMatrix3D[15] = 1.0f; 
	
}

