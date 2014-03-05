#ifndef _QUAD_H_
#define _QUAD_H_


#include <GL\glew.h>
#include "Logging.h"
#include "Utilities.h"

class Quad
{
public:
	Quad(void); 
	~Quad(void); 
	GLuint m_VBO; //Vertex Buffer
	GLuint m_EBO; //Element Buffer
	GLuint m_VAO; //Vertex Attributes

	GLuint m_FragmentShader; 
	GLuint m_VertexShader; 

	GLuint m_ShaderProgram; 
	unsigned int m_uiTexture; 
	unsigned int m_uSourceBlendMode;
	unsigned int m_uDestinationBlendMode;
	int tex_loc; 
	int matrix_location; 
	unsigned int proj_location;
	float m_fZoom; 

	GLFWwindow * GameWindow; 
	Matrix4 * modelMatrix;

	Vectors m_minUVCoords; 
	Vectors m_maxUVCoords; 
	Vectors m_uvScale;
	Vertex m_aoVerts[4];

	void Draw(); 
	bool LoadVertShader(const char* filePath); 
	bool LoadFragShader(const char* filePath);
	bool LinkShaders(); 
	void LoadTexture(const char* a_pTexture); 
private:

};














#endif