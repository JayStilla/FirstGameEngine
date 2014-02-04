#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <GL\glew.h>

#include <GLFW\glfw3.h>

#include "Utilities.h"
#include "Quad.h"
#include <SOIL.h>
#include "Logging.h"
#include "libs\JayceIsDaBestMathLibrary\Vect2.h"
#include "libs\JayceIsDaBestMathLibrary\Vect3.h"
#include "libs\JayceIsDaBestMathLibrary\Vect4.h"

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



class Sprite: public Quad
{
public:
	Sprite(void); 
	~Sprite(void); 
	Sprite(const char*, int, int, Vector4, GLFWwindow*); 
	void Draw(); 
	void Input(); 

private:
	Vertex m_aoVerts[4]; 
	float * modelMatrix; 

	Vectors m_v2Scale; 
	Vector3 m_v3Position; 
	Vector4 m_v4SpriteColor; 

	Vectors m_minUVCoords; 
	Vectors m_maxUVCoords; 
	Vectors m_uvScale; 
	Vectors m_uvOffset; 

	unsigned int m_uiTexture; 
	GLFWwindow * GameWindow; 
	//used late
	unsigned int m_uSourceBlendMode; 
	unsigned int m_uDestinationBlendMode; 
	int tex_loc; 
	int matrix_location; 

};






#endif