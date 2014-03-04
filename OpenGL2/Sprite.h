#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <GL\glew.h>

#include <GLFW\glfw3.h>

#include "Utilities.h"
#include "Quad.h"
#include <SOIL.h>
#include "Logging.h"


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
	void SetUVData(); 
	void SetTexture(const char* a_pTexture); 
	virtual void Draw(); 
	void Input(); 

protected:
	Vertex m_aoVerts[4]; 
	Matrix4 * modelMatrix; 

	Vectors m_v2Scale; 
	Vector3 m_v3Position; 
	Vector4 m_v4SpriteColor; 

	Vectors m_minUVCoords; 
	Vectors m_maxUVCoords; 
	Vectors m_uvScale; 
	Vectors m_uvOffset; 
	float m_fZoom; 

	unsigned int m_uiTexture; 
	GLFWwindow * GameWindow; 
	//used late
	unsigned int m_uSourceBlendMode; 
	unsigned int m_uDestinationBlendMode; 
	int tex_loc; 
	int matrix_location; 
	unsigned int proj_location;
};






#endif