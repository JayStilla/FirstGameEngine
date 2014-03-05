#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <GL\glew.h>

#include <GLFW\glfw3.h>

#include "Utilities.h"
#include "Quad.h"
#include "Logging.h"


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
	Vector3 m_v3Position; 
	Vectors m_v2Scale; 
	 
	
protected:
	 
	
	Vector4 m_v4SpriteColor; 

	Vectors m_uvOffset; 
};






#endif