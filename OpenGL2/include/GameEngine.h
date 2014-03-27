#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include <glm.hpp>
#include <GL/glew.h>
#define GLEW_STATIC
#define GLFW_DLL
#include <GLFW\glfw3.h>
#include <stdio.h>
#include <assert.h>
#include "Logging.h"
#include <iostream>
#include <SOIL.h>
#include "Logging.h"


static class Engine
{
private:

public:
	GLFWwindow * window; 

	Engine();	//constructor
	~Engine(); //deconstructor

	//unsigned int OpenWindow(); 
	void RunGame(); 

	//void glfw_window_size_callback(GLFWwindow* window, int width, int height); 

	void _update_fps_counter(GLFWwindow* window); 

	//void AddStack(); 
	//void UpdateStack(); 

};



#endif