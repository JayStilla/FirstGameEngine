#include "Matrix3.h"


Matrix3 Matrix3::operator*(Matrix3 &w)
{
	Matrix3 temp; 
	for(int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++) {
			//Multiply the row of  A by the column of B to get the row, column of product.
			for(int inner = 0; inner < 2; inner++){
				temp.a_fMatricesMatrix2D[row][col] += a_fMatricesMatrix2D[row][inner] * w.a_fMatricesMatrix2D[inner][col];
			}
		}
	}
	return temp;
}


Matrix3 Matrix3::m_CreateIdentity()
{
	//BUILDING AN IDENTITY MATRIX
	Matrix3 Identity;
	//ROW 0
	Identity.a_fMatricesMatrix2D[0][0] = 1;
	Identity.a_fMatricesMatrix2D[0][1] = 0;
	Identity.a_fMatricesMatrix2D[0][2] = 0;
	//ROW 1
	Identity.a_fMatricesMatrix2D[1][0] = 0;
	Identity.a_fMatricesMatrix2D[1][1] = 1; 
	Identity.a_fMatricesMatrix2D[1][2] = 0; 
	//ROW 2
	Identity.a_fMatricesMatrix2D[2][0] = 0; 
	Identity.a_fMatricesMatrix2D[2][1] = 0; 
	Identity.a_fMatricesMatrix2D[2][2] = 1; 

	return Identity; 

}

//BUILDING XY TRANSLATION///////////////////////////////////////
Matrix3 Matrix3::m_TranslationXY(float x, float y)
{
	Matrix3 Translation3D; 
	//ROW 0
	Translation3D.a_fMatricesMatrix2D[0][0] = 1; 
	Translation3D.a_fMatricesMatrix2D[0][1] = 0; 
	Translation3D.a_fMatricesMatrix2D[0][2] = x; 
	//ROW 1
	Translation3D.a_fMatricesMatrix2D[1][0] = 0; 
	Translation3D.a_fMatricesMatrix2D[1][1] = 1; 
	Translation3D.a_fMatricesMatrix2D[1][2] = y; 
	//ROW 2
	Translation3D.a_fMatricesMatrix2D[2][0] = 0; 
	Translation3D.a_fMatricesMatrix2D[2][1] = 0; 
	Translation3D.a_fMatricesMatrix2D[2][2] = 1; 

	return Translation3D;
}