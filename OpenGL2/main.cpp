#include <GL/glew.h>
#define GLFW_DLL
#include <GLFW\glfw3.h>
#include <stdio.h>
#include <assert.h>
#include "Logging.h"

//leep track of window size for things like the viewport and the mouse cursor
int g_gl_width = 640; 
int g_gl_height = 480;

//a call-back function
void glfw_window_size_callback (GLFWwindow* window, int width, int height)
{
	g_gl_width = width; 
	g_gl_height = height; 
	/*update any perspective matrices used here*/
}


void glfw_error_callback(int error, const char* description)
{
	fputs(description, stderr);
	gl_log(description, __FILE__, __LINE__); 
}

void _update_fps_counter (GLFWwindow* window) {
	static double previous_seconds = glfwGetTime ();
	static int frame_count;
	double current_seconds = glfwGetTime ();
	double elapsed_seconds = current_seconds - previous_seconds;
	if (elapsed_seconds > 0.25) {
		previous_seconds = current_seconds;
		double fps = (double)frame_count / elapsed_seconds;
		char tmp[128];
		sprintf (tmp, "opengl @ fps: %.2lf", fps);
		glfwSetWindowTitle (window, tmp);
		frame_count = 0;
	}
	frame_count++;
}



int main()
{
	//AntiAliasing
	glfwWindowHint(GLFW_SAMPLES,4); 


	char message[256];
	sprintf (message, "starting GLFW %s", glfwGetVersionString()); 
	assert (gl_log (message, __FILE__, __LINE__)); 
	glfwSetErrorCallback (glfw_error_callback); 

	if(!glfwInit())
	{
		fprintf (stderr, "ERROR: could not start GLFW3\n"); 
		return 1; 
	}

	//get the primary monitor
	GLFWmonitor* mon = glfwGetPrimaryMonitor(); 
	//this lets us use the video mode for the monitor we pass
	const GLFWvidmode* vmode = glfwGetVideoMode(mon); 

	GLFWwindow* window = glfwCreateWindow(vmode->width, vmode->height, "Extended GL Init", mon, NULL); 

	//GLFWwindow * window = glfwCreateWindow(640, 480, "Hello Triangle" , NULL, NULL) ; 
	if (!window)
	{
		fprintf (stderr, "ERROR: could not open window with GLFW3\n"); 
		glfwTerminate(); 
		return 1; 
	}
	glfwMakeContextCurrent (window); 
	//start GLEW extension handler
	glewExperimental = GL_TRUE; 
	glewInit(); 
	//get version info
	const GLubyte* renderer = glGetString (GL_RENDERER); //get renderer string
	const GLubyte* version = glGetString(GL_VERSION); //version as a string
	printf ("Renderer: %s\n", renderer); 
	printf ("OpenGL version supported %s\n", version); 

	//tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable (GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc (GL_LESS); 
	// depth- testing interprets a smaller value as "closer"

	/* OTHER STUFF GOES HERE NEXT */
	float points[] = 
	{
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f, 
		-0.5f, -0.5f, 0.0f,
	};

	//Creating and binding the Vertex Buffer Object
	GLuint VBO = 0; 
	glGenBuffers (1, &VBO); 
	glBindBuffer (GL_ARRAY_BUFFER, VBO); 
	glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (float), points, GL_STATIC_DRAW); 

	//Creating and binding the Vertex Array Object
	GLuint VAO = 0; 
	glGenVertexArrays (1, &VAO); 
	glBindVertexArray (VAO); 
	glEnableVertexAttribArray(0); 
	glBindBuffer (GL_ARRAY_BUFFER, VBO); 
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); 

	const char* vertex_shader = 
		"#version 330\n"
		"in vec3 vp;"
		"void main () {"
		" gl_Position = vec4 (vp, 1.0);"
		"}"; 
	const char* fragment_shader = 
		"#version 330\n"
		"out vec4 frag_colour;"
		"void main() {"
		"	frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
		"}"; 

	//Create a shader 
	GLuint vs = glCreateShader (GL_VERTEX_SHADER); 
	//put the actural char* into the shader
	glShaderSource (vs, 1, &vertex_shader, NULL); 
	//compile the shader
	glCompileShader(vs); 
	printShaderInfoLog(vs);
	GLuint fs = glCreateShader (GL_FRAGMENT_SHADER); 
	glShaderSource (fs, 1, &fragment_shader, NULL); 
	glCompileShader (fs);
	printShaderInfoLog(fs);
	//Create the container that holds your shaders
	GLuint shaderProgram = glCreateProgram (); 
	//attach the shader you compiled
	glAttachShader (shaderProgram, fs); 
	glAttachShader (shaderProgram, vs); 
	//this is links the shaders together, its kinda like a compile
	glLinkProgram (shaderProgram); 
	printProgrammingInfoLog(shaderProgram);

	float points2[] = 
	{
		0.0f, 1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f, 
		1.0f, -1.0f, 0.0f,
	};

	GLuint squareVBO; 
	glGenBuffers(1, &squareVBO); 
	glBindBuffer(GL_ARRAY_BUFFER, squareVBO); 
	glBufferData (GL_ARRAY_BUFFER, 9 * sizeof(float), points2, GL_STATIC_DRAW); 


	GLuint squareVAO = 0; 
	glGenVertexArrays (1, &squareVAO); 
	glBindVertexArray (squareVAO); 
	glEnableVertexAttribArray(0); 
	glBindBuffer (GL_ARRAY_BUFFER, squareVBO); 
	glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL); 

	const char* ver_shader = 
		"#version 330\n"
		"in vec3 vp;"
		"void main () {"
		" gl_Position = vec4 (vp, 1.0);"
		"}"; 
	const char* frag_shader = 
		"#version 330\n"
		"out vec4 frag_colour;"
		"void main() {"
		"	frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
		"}";

	//while loop to perform functions
	while(!glfwWindowShouldClose (window))
	{
		_update_fps_counter (window); 
		//wipe the drawing surface clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glViewport (0, 0, g_gl_width, g_gl_height); 
		glUseProgram (shaderProgram); 
		glBindVertexArray(VAO); 
		//draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawArrays (GL_TRIANGLES, 0, 3); 

		glBindVertexArray(squareVAO); 
		glDrawArrays (GL_LINE_LOOP, 0, 3); 
		//update other events like input handling
		glfwPollEvents(); 
		//put the stuff we've been drawing onto the display
		glfwSwapBuffers (window); 
		glfwPollEvents(); 
		if(GLFW_PRESS == glfwGetKey (window, GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(window, 1); 
		}
		
	}


	//close GL context and any other GLFW resources 
	glfwTerminate(); 
	getchar(); 
	return 0; 

}