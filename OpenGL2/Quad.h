#ifndef _QUAD_H_
#define _QUAD_H_


#include <GL\glew.h>
#include "Logging.h"
#include "libs\JayceIsDaBestMathLibrary\Vect2.h"
#include "libs\JayceIsDaBestMathLibrary\Vect3.h"
#include "libs\JayceIsDaBestMathLibrary\Vect4.h"



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

	void Draw(); 
private:

};














#endif