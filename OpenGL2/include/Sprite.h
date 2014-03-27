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
	 
	virtual void Draw(); 
	void Input(); 

	void SetPosition(Vector3 a_v3Pos);
	void SetPosition(float a_fX, float a_fY);
	Vector3 GetPosition();
	void SetScale(Vectors a_v2Scale);
	void SetScale(float a_fScale);
	void SetScale(float a_fScaleX,float a_fScaleY);
	Vectors GetScale();
	void SetVertexData( Vertex* a_vertexData );
	const Vertex* GetVertexData() const;

	Vector3 m_v3Position; 
	Vectors m_v2Scale; 
	 
	
protected:
	 
	
	Vector4 m_v4SpriteColor; 

	Vectors m_uvOffset; 
};


inline void	Sprite::SetVertexData( Vertex* a_vertexData )
{
	memcpy( &m_aoVerts, a_vertexData, sizeof(Vertex) * 4 );
}

inline const Vertex* Sprite::GetVertexData() const
{
	return static_cast<const Vertex*>( m_aoVerts );
}




#endif