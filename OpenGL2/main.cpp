#include <GL/glew.h>
#define GLEW_STATIC
#define GLFW_DLL
#include <GLFW\glfw3.h>
#include <stdio.h>
#include <assert.h>
#include "Logging.h"
#include <iostream>
#include <SOIL.h>
#include "Sprite.h"
#include <ft2build.h>
#include "Text.h"
#include "Utilities.h"
#include FT_FREETYPE_H



//Drawing text TEST
//Computes a scaling value so that the strings
//float computeScale(const char* strs[4]) {
//	float maxWidth = 0;
//	for(int i = 0; i < 4; i++) {
//		float width = t3dDrawWidth(strs[i]);
//		if (width > maxWidth) {
//			maxWidth = width;
//		}
//	}
//	
//	return 2.6f / maxWidth;
//}
//
//float _angle = -30.0f;
//float _scale;
////The four strings that are drawn
//const char* STRS[4] = {"Video", "Tutorials", "Rock", ".com"};
//
//void cleanup() {
//	t3dCleanup();
//}
//
//void handleKeypress(unsigned char key, int x, int y) {
//	switch (key) {
//		case 27: //Escape key
//			cleanup();
//			exit(0);
//	}
//}
//
//void initRendering() {
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_NORMALIZE);
//	glShadeModel(GL_SMOOTH);
//	t3dInit();
//}
//
//void handleResize(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
//}
//
//void drawScene() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(0.0f, 0.0f, -8.0f);
//	
//	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
//	
//	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
//	GLfloat lightPos0[] = {-0.5f, 0.5f, 1.0f, 0.0f};
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
//	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
//	
//	glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
//	glRotatef(-_angle, 0.0f, 1.0f, 0.0f);
//	
//	//Draw the strings along the sides of a square
//	glScalef(_scale, _scale, _scale);
//	glColor3f(0.3f, 1.0f, 0.3f);
//	for(int i = 0; i < 4; i++) {
//		glPushMatrix();
//		glRotatef(90 * i, 0, 1, 0);
//		glTranslatef(0, 0, 1.5f / _scale);
//		t3dDraw3D(STRS[i], 0, 0, 0.2f);
//		glPopMatrix();
//	}
//	
//	glfwSwapBuffers(window);
//}
//
//void update(int value) {
//	_angle += 1.5f;
//	if (_angle > 360) {
//		_angle -= 360;
//	}
//	
//	glfwPostRedisplay();
//	glfwTimerFunc(25, update, 0);
//}

/////////////////////////////////////////////END TEST

// a call-back function
void glfw_window_size_callback (GLFWwindow* window, int width, int height) {
	g_gl_width = width;
	g_gl_height = height;

	/* update any perspective matrices used here */
}

void glfw_error_callback(int error, const char* description)
{
	fputs(description, stderr); 

}

int main()
{
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

	// uncomment these lines if on Apple OS X
	/*	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	*/	
	//Anti-Aliasing
	glfwWindowHint (GLFW_SAMPLES, 4);

	//get the primary monitor
	GLFWmonitor* mon = glfwGetPrimaryMonitor ();
	//this lets us the the video mode for the monitor we pass
	const GLFWvidmode* vmode = glfwGetVideoMode (mon);
	GLFWwindow* window = glfwCreateWindow (
		vmode->width, vmode->height, "Extended GL Init",NULL/* mon*/, NULL
		);
	glfwSetWindowSize(window, 640, 480);

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

	/* OTHER STUFF GOES HERE NEXT */



	//Column Major Order 
	float matrix[] =
	{
		1.0,0.0f,0.0f,0.0f, //first column
		0.0,1.0f,0.0f,0.0f, //second column
		0.0,0.0f,1.0f,0.0f, //third column
		0.5,0.0f,0.0f,1.0f  //fourth column
	};

	float speed = 1.0f; // move at 1 unit per second
	float last_position = 0.0f;

	//Quad * tester = new Quad();

	Vector4 SpriteColour(1,1,1,1);

	Sprite * tester = new Sprite("Glasses.png",240,272, Vector4(1,1,1,1),window); 

	//int matrix_location = glGetUniformLocation (shaderProgram, "matrix");
	//glUniform1i(glGetUniformLocation(shaderProgram, "Texture"), 0);

	Ortho = new Matrix4(); 
	Orthographic(0, g_gl_width, g_gl_height, 0, 0, -1, Ortho); 

	while (!glfwWindowShouldClose (window)) {

		/* add a timer for doing animation
		static double previous_seconds = glfwGetTime ();
		double current_seconds = glfwGetTime ();
		double elapsed_seconds = current_seconds - previous_seconds;
		previous_seconds = current_seconds;
		// reverse direction when going to far left or right
		if (fabs(last_position) > 1.0f) {
		speed = -speed;
		}
		*/

		glEnable (GL_CULL_FACE); // cull face
		glCullFace (GL_BACK); //cull back face
		glFrontFace (GL_CW); // GL_CCW for counter clock-wise

		// wipe the drawing surface clear
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//resize window
		glViewport (0, 0, g_gl_width, g_gl_height);

		//TESTING TEXT

		
		//_scale = computeScale(STRS);

		//glfwDisplayFunc(drawScene);
		//glfwGetKey(handleKeypress);
		//glfwReshapeFunc(handleResize);
		//glfwTimerFunc(25, update, 0);

		//glfwMainLoop();


		///////////////////////////////////////END TEST

		// update the matrix
		//  matrix[12] = elapsed_seconds * speed + last_position;
		//  last_position = matrix[12];
		//set the shader for this VAO
		//	 glUseProgram (shaderProgram);
		//Here is where we attach the marix
		//	 glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix);
		//bind the VAO to be drawn
		//	 glBindVertexArray (VAO);
		// draw points 0-3 from the currently bound VAO with current			in-use shader
		//	 glDrawArrays (GL_TRIANGLES, 0, 3);

		tester->Input();
		tester->Draw();

		// update other events like input handling 
		glfwPollEvents ();
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers (window);

		//When do i exit?
		if (GLFW_PRESS == glfwGetKey (window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose (window, 1);
		}
	}

	// close GL context and any other GLFW resources
	glfwTerminate();
	return 0;


}