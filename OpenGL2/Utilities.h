#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <SOIL.h>
#include "libs\JayceIsDaBestMathLibrary\Matrix4.h"

// keep track of window size for things like the viewport and the mouse cursor
extern int g_gl_width;
extern int g_gl_height;

extern Matrix4 * Ortho; 
void Orthographic(float a_fLeft, float a_fRight, float a_fTop, float a_fBottom, float a_fNear, float a_fFar, Matrix4 * mat); 



#endif