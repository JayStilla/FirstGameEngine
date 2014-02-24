#define GL_LOG_FILE "gl.log"
#ifndef _LOGGING_H_
#define _LOGGING_H_

#include <GL/glew.h>
#include <time.h> 
#include <fstream>
#include <string>
#include <istream>


bool restart_gl_log();

bool gl_log (const char* message, const char* filename, int line);

bool printShaderInfoLog(GLuint obj);

bool printProgramInfoLog(GLuint obj);


///////////////////////////////////////////TEXT FILE READER 
/*
Usage 
	 std::string vString, fString;
	 const char *vs, *fs;

// Read source code from files
	vString = textFileReader("./resources/exampleVert.glsl");
	fString = textFileReader("./resources/exampleFrag.glsl");

	vs = vString.c_str();
	fs = fString.c_str();

	// Set shader source
*/

std::string textFileReader(const char* a_szFileName);


#endif