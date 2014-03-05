#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <SOIL.h>
#include "libs\JayceIsDaBestMathLibrary\Matrix4.h"
#include "libs\JayceIsDaBestMathLibrary\Vect2.h"
#include "libs\JayceIsDaBestMathLibrary\Vect3.h"
#include "libs\JayceIsDaBestMathLibrary\Vect4.h"
#include <map>
#include <queue>
#include <vector>
#include <time.h>
#include <fstream>
#include <assert.h>
#include <functional>
#include <cstdlib>
#include <SOIL.h>

// keep track of window size for things like the viewport and the mouse cursor
extern int g_gl_width;
extern int g_gl_height;

struct Vertex
{	union
	{	struct 
		{	Vector3 Pos; 
			Vector4 Color; 
			Vectors UV; }; 
		struct
		{
			float X, Y, Z; 
			float R, G, B, A; 
			float U, V; 
		};};
		bool operator == (const Vertex& rhs)
		{
			return (X == rhs.X &&
					Y == rhs.Y &&
					Z == rhs.Z &&
					R == rhs.R &&
					G == rhs.G && B == rhs.B && A == rhs.A && U == rhs.U && V == rhs.V);
		}};


enum PlayType
{
	ONCE,
	LOOP,
	LOOPSECTION,
	PINGPONG, 
	REVERSE,
	RANDOMLOOP,
	RANDOM,
	SINGLE
};

extern Matrix4 * Ortho; 
void Orthographic(float a_fLeft, float a_fRight, float a_fTop, float a_fBottom, float a_fNear, float a_fFar, Matrix4 * mat); 

double getDeltaTime(); 
void resetDeltaTime(); 

#endif