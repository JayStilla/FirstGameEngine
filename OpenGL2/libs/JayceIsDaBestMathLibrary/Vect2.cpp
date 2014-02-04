#include "Vect2.h"


Vectors::Vectors()
{
}

Vectors::Vectors(float newX, float newY)
{
	x = newX; 
	y = newY; 
}

Vectors::~Vectors()
{
}
///////////////////////////////////////////////////////////////////////////VECTOR 2 FUNCTIONS
//equations that helps the variables that move in the game
//subtracting points and returning a new point
Vectors Vectors::pointSubtract(Vectors &v, float s)
{
	Vectors result(v.x - s, v.y - s); 
	return result; 
}

//Adding two points and returning it as a new point
Vectors Vectors::pointAdd(Vectors &v, float s)
{
	Vectors result(v.x + s, v.y + s); 
	return result;
}

//multiplying points by scalar to return a new point
Vectors Vectors::multiplyScalar(Vectors &v, float s)
{
	Vectors result(v.x*s, v.y*s); 
	return result; 
}

//subtracting points by each other for a new point
Vectors Vectors::pointSubtract(Vectors &v, Vectors &v2)
{
	Vectors result(v.x - v2.x, v.y - v2.y); 
	return result; 
}

//adding points by each other for a new point
Vectors Vectors::pointAdd(Vectors &v, Vectors &v2)
{
	Vectors result(v.x + v2.x, v.y+v2.y); 
	return result; 
}

//Getting the normal of a point and returning it as a new point
Vectors Vectors::getNormal(Vectors &v)
{
	float mag = sqrt (v.x*v.x + v.y*v.y);
	Vectors result(v.x/mag, v.y/mag); 
	return result; 
}

//Getting magnitude for point
float Vectors::getMagnitude(Vectors &v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}
