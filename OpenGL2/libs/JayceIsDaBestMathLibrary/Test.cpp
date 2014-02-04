#include <iostream>
#include "MiscMath.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Vect2.h"
#include "Vect3.h"
#include "Vect4.h"
#include "math.h"

using namespace std;

CommonMath ComMath; 
Vector4 Vect4; 
Vector3 Vect3;
Vector3 Vect33; 
Matrix3 Mat3;
Matrix4 Mat4; 
Vectors V2; 

int main()
{
	cout << "---------------------------Matrix 3--------------------------------" << endl; 
	Matrix3 Identity;
	Identity = Mat3.m_CreateIdentity();
	cout << Identity; 
	cout << endl;

	Matrix3 TranslationXY; 
	TranslationXY = Mat3.m_TranslationXY(2, 2); 
	cout << TranslationXY; 
	cout << endl; 

	cout << "--------------------------MATRIX 4 --------------------------------" << endl; 

	Matrix4 RotationX; 
	RotationX = Mat4.m_RotationX(3); 
	cout << RotationX; 
	cout << endl; 

	Matrix4 RotationY; 
	RotationY = Mat4.m_RotationY(2); 
	cout << RotationY; 
	cout << endl;

	Matrix4 RotationZ; 
	RotationZ = Mat4.m_RotationZ(2); 
	cout << RotationZ; 
	cout << endl; 

	Matrix4 TranslationXYZ; 
	TranslationXYZ = Mat4.m_TranslationXYZ(2, 2, 2); 
	cout << TranslationXYZ; 
	cout << endl; 

	Matrix4 mat; 
	mat = Mat4.m_OrthoProjection(2,2,2,2,2,2);
	cout << mat; 
	cout << endl; 

	cout << "---------------------------COMMON MATH--------------------------------" << endl; 

	cout << ComMath.Pow2(2, 2)<< endl; 
	cout << ComMath.m_RadianConvert(360)<< endl; 
	cout << ComMath.m_degreeConvert(6) << endl; 
	Vect3.x = 2; Vect3.y = 2; Vect3.z =2; 
	Vect33.x = 4; Vect33.y = 4; Vect33.z = 4; 
	cout << ComMath.m_Lerp(Vect3, Vect33, 2) << endl; 

	cout << "---------------------------VECTOR 3--------------------------------" << endl; 
	Vect3.x = 2; Vect3.y =2; Vect3.z =2; 
	cout << Vect3.Magnitude()<<endl; 

	Vect3.x = 2; Vect3.y =2; Vect3.z =2; 
	cout << Vect33.Normalise(Vect3)<<endl; 

	Vect3.x = 2; Vect3.y =2; Vect3.z = 2; 
	cout << Vect33.GetNormal(Vect3) << endl; 

	Vect3.x = 2; Vect3.y = 2; Vect3.z =2; 
	cout <<Vect33.DotProduct(Vect3) << endl;

	Vect3.x = 4; Vect3.y = 4; Vect3.z = 4; 
	Vect33.x =4; Vect33.y = 4; Vect3.z = 4; 
	cout << Vect3.EulerAngle(Vect3, Vect33)<<endl; 

	Vect3.x = 2; Vect3.y = 2; Vect3.z = 2; 
	Vect33.x = 2; Vect33.y =2; Vect33.z = 2; 
	cout << Vect3.CrossProduct(Vect3, Vect33)<<endl;

	Matrix3 Transform; 
	Transform = Mat3; 
	Vect3.x =2; Vect3.y = 2; Vect3.z = 2; 
	cout << Vect3.m_TransformVector3(Mat3)<<endl; 

	Matrix3 tempM; 
	tempM = Mat3; 
	Vect3.x = 2; Vect3.y = 2; Vect3.z = 2; 
	cout << Vect3.Scale(Mat3); 
	cout << endl; 

	cout << "---------------------------VECTOR 4--------------------------------" << endl; 
	Vect4.x = 2; Vect4.y =2; Vect4.z =2; Vect4.w = 2;  
	cout << Vect4.m_Magnitude()<<endl;

	Vect4.x = 2; Vect4.y =2; Vect4.z =2; Vect4.w = 2; 
	cout << Vect4.m_GetNormal(Vect4)<<endl; 

	Vect4.x = 2; Vect4.y =2; Vect4.z =2; Vect4.w = 2; 
	cout << Vect4.m_Normalise(Vect4) <<endl; 

	Vect4.x = 2; Vect4.y =2; Vect4.z =2; Vect4.w = 2; 
	cout << Vect4.m_DotProduct(Vect4) << endl; 

	cout << Vect4.m_RGBconverter(0xFFFFFFFF)<<endl; 

	Matrix4 Transform2; 
	Transform2 = Mat4; 
	Vect4.x = 2; Vect4.y =2; Vect4.z =2; Vect4.w = 2; 
	cout << Vect4.m_TransformPoint(Mat4) << endl;

	Matrix4 Transform3; 
	Transform3 = Mat4; 
	Vect4.x = 2; Vect4.y =2; Vect4.z =2; Vect4.w = 2;
	cout << Vect4.m_TransformVector4(Vect4, Mat4); 
	cout << endl; 

	Matrix4 mat4; 
	mat4 = Mat4; 
	Vect4.x = 2; Vect4.y = 2; Vect4.z = 2; Vect4.w = 2; 
	cout << Vect4.Scale(Mat4); 
	cout << endl; 

	cout << "---------------------------VECTOR 2--------------------------------" << endl; 
	Vectors Point; 
	Point.x = 2; Point.y =2; 
	cout << V2.pointSubtract(Point, 2) << endl; 

	Vectors Point2; 
	Point2.x = 2; Point2.y =2;
	cout << V2.pointAdd(Point2, 2)<<endl;

	Vectors Point3; 
	Point3.x = 2; Point3.y =2;
	cout << V2.multiplyScalar(Point3, 2) << endl;

	Vectors Point4; 
	Point4.x = 2; Point4.y =2;
	cout << V2.getMagnitude(Point4)<<endl;

	Vectors Point5; 
	Point5.x = 2; Point5.y =2;
	cout<<V2.getNormal(Point5)<<endl; 

	getchar(); 
	return 0; 
}