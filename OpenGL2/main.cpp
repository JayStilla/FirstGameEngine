#include <GL/glew.h>
#define GLFW_DLL
#include <GLFW\glfw3.h>
#include <stdio.h>
#include <assert.h>
#include "Logging.h"
#include <iostream>
#include <SOIL.h>
#include "Sprite.h"
#include "TextManager.h"
#include "Utilities.h"
#include "Quad.h"
#include "AnimatedSprite.h"


// a call-back function
void glfw_window_size_callback (GLFWwindow* window, int width, int height) {
	g_gl_width = width;
	g_gl_height = height;

	/* update any perspective matrices used here */
}

void glfw_error_callback(int error, const char* description)
{
	fputs(description, stderr);
	gl_log(description,__FILE__, __LINE__); 

}

int main()
{
	resetDeltaTime(); 
	//setup to log some GLFW stuff

	char message[256];
	sprintf_s(message, "starting GLFW %s", glfwGetVersionString ());
	assert (gl_log (message, __FILE__, __LINE__));
	glfwSetErrorCallback (glfw_error_callback);
	
	

	//open an OS window using GLFW
	if(!glfwInit())
	{
		fprintf (stderr,"ERROR: could not start GLFW3\n");
		return 1;
	}
	//Anti-Aliasing
	glfwWindowHint (GLFW_SAMPLES, 4);

	//get the primary monitor
	GLFWmonitor* mon = glfwGetPrimaryMonitor ();
	//this lets us the the video mode for the monitor we pass
	const GLFWvidmode* vmode = glfwGetVideoMode (mon);
	GLFWwindow* window = glfwCreateWindow (
		vmode->width, vmode->height, "Extended GL Init",NULL/* mon*/, NULL
		);
	glfwSetWindowSize(window, g_gl_width, g_gl_height);

	if (!window) {
		fprintf (stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}
	//not sure if this works
	//log_gl_params ();

	glfwMakeContextCurrent(window);

	//start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString (GL_VERSION); // version as a string
	printf ("Renderer: %s\n", renderer);
	printf ("OpenGL version supported %s\n", version);

	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable (GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer"

	//Sprite * tester = new Sprite("megamanx.png",240,272, Vector4(1,1,1,1),window); 
	AnimatedSprite * AniTest = new AnimatedSprite("MegamanXSheet.xml", window);  
	AniTest->SetAnimation("teleport", ONCE); 

	Ortho = new Matrix4(); 
	Orthographic(0, g_gl_width, g_gl_height, 0, 0, -1, Ortho); 

	TextManager::Instance().LoadFont("../NESish.xml");

	while (!glfwWindowShouldClose (window)) {
		glEnable(GL_ALPHA_TEST); 
		glAlphaFunc(GL_GREATER, .5); 
		glEnable(GL_ALPHA); 
		glEnable (GL_CULL_FACE); // cull face
		glCullFace (GL_BACK); //cull back face
		glFrontFace (GL_CW); // GL_CCW for counter clock-wise

		// wipe the drawing surface clear
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//resize window
		glViewport (0, 0, g_gl_width, g_gl_height);

		AniTest->Update(); 
		TextManager::Instance().DrawString("What it do!",Vectors(0,g_gl_height/2),1); 
		//tester->Draw();
		//tester->Input(); 
	
		// update other events like input handling 
		glfwPollEvents ();
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers (window);

		resetDeltaTime(); 
		//When do i exit?
		if (GLFW_PRESS == glfwGetKey (window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose (window, 1);
		}
	}

	// close GL context and any other GLFW resources
	glfwTerminate();
	return 0;
}
