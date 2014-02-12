#include "Sprite.h"

Sprite::Sprite(void)
{
	//Default Shaders for Default constructor

	const char * VertexShader =	// Vertex Shaders deal with objects in 3D space
		"#version 330\n"
		"layout(location = 0) in vec3 position;"
		"layout(location = 1) in vec4 color;"
		//"in vec2 texcoord;"
		"out vec4 vColor;"
		"void main() {"
		"	vColor = color;"
		"	gl_Position = vec4 (position, 1.0);"
		"}";

	const char * FragmentShader =	// Fragment Shaders dela with pixel data
		"#version 330\n"
		"in vec4 vColor;"
		//"in vec2 texcoord;"
		"out vec4 outColour;"
		"void main () {"
		"	outColour = vColor;"
		"}";
	// Compile Vertex Shader
	m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_VertexShader, 1, &VertexShader, NULL);
	glCompileShader(m_VertexShader);
	printShaderInfoLog(m_VertexShader);

	// Compile Fragment Shader
	m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_FragmentShader, 1, &FragmentShader, NULL);
	glCompileShader(m_FragmentShader);
	printShaderInfoLog(m_FragmentShader);

	// Link Shaders into Shader Program
	m_ShaderProgram = glCreateProgram();

	glAttachShader(m_ShaderProgram, m_FragmentShader);
	glAttachShader(m_ShaderProgram, m_VertexShader);

	glLinkProgram(m_ShaderProgram);
	printProgramInfoLog(m_ShaderProgram);

	glUseProgram(m_ShaderProgram);

	/////////////////////////////////////////////ORTHO CAM EDIT TO WORK WITH YOUR MATH LIB
	m_v2Scale = Vectors(g_gl_width, g_gl_height); 
	m_v3Position = Vector3(0,0,0); 

	modelMatrix = new Matrix4(); 

	*modelMatrix = modelMatrix->m_CreateIdentity(); 

	modelMatrix->a_fMatricesMatrix3D[12] = m_v3Position.x; 

	modelMatrix->a_fMatricesMatrix3D[13] = m_v3Position.y; 
	modelMatrix->a_fMatricesMatrix3D[14] = m_v3Position.z; 

	proj_location = glGetUniformLocation(m_ShaderProgram, "projection");  
}


Sprite::~Sprite(void)
{
}
Sprite::Sprite( const char* a_pTexture, int a_iWidth, int a_iHeight, Vector4 a_v4Color ,GLFWwindow * window)
{

	GameWindow = window;
	//Default Shaders for Default constructor

	LoadVertShader("../resources/VertexShader.glsl"); 
	LoadFragShader("../resources/FragShader.glsl"); 
	LinkShaders(); 


	m_v4SpriteColor = a_v4Color;

	m_aoVerts[0].Pos = Vector3(	-0.5f,  0.5f,  0.0f);
	m_aoVerts[1].Pos = Vector3(	0.5f,  0.5f,  0.0f);
	m_aoVerts[2].Pos = Vector3(	-0.5f,  -0.5f,  0.0f);
	m_aoVerts[3].Pos = Vector3(	0.5f,  -0.5f,  0.0f);

	
	/*m_aoVerts[0].Color = Vector4(1.0f,  0.0f,  0.0f, 1.0f);
	m_aoVerts[1].Color = Vector4(0.0f,  1.0f,  0.0f, 1.0f);
	m_aoVerts[2].Color = Vector4(0.0f,  0.0f,  1.0f, 1.0f);
	m_aoVerts[3].Color = Vector4(1.0f,  1.0f,  1.0f, 1.0f);*/
	


	m_aoVerts[0].Color = m_v4SpriteColor;
	m_aoVerts[1].Color = m_v4SpriteColor;
	m_aoVerts[2].Color = m_v4SpriteColor;
	m_aoVerts[3].Color = m_v4SpriteColor;



	m_aoVerts[0].UV = Vectors(0.0f,  0.0f);
	m_aoVerts[1].UV = Vectors(0.0f,  1.0f);
	m_aoVerts[2].UV = Vectors(1.0f,  0.0f);
	m_aoVerts[3].UV = Vectors(1.0f,  1.0f);

	GLuint elements[] =
	{
		0,1,2,3
	};

	//Gen Buffers
	glGenBuffers(1,&m_VBO);
	glGenBuffers(1,&m_EBO);
	glGenVertexArrays(1, &m_VAO);

	//Bind Buffers
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);

	//Put Data into buffers
	glBufferData(GL_ARRAY_BUFFER, 4* sizeof(Vertex), m_aoVerts, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	//Enable some attributes
	GLint posAttrib = glGetAttribLocation(m_ShaderProgram,"position");
	glEnableVertexAttribArray(posAttrib);
	GLint colAttrib = glGetAttribLocation(m_ShaderProgram,"color");
	glEnableVertexAttribArray(colAttrib);
	GLint uvAttrib = glGetAttribLocation(m_ShaderProgram,"texcoord");
	glEnableVertexAttribArray(uvAttrib);


	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(uvAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(7 * sizeof(float)));

	glBindVertexArray(0);
	m_v3Position = Vector3(0,0,0);
	
	matrix_location = glGetUniformLocation (m_ShaderProgram, "matrix");

	m_uiTexture = 0;
	m_minUVCoords = Vectors( 0.f, 0.f );
	m_maxUVCoords = Vectors( 1.f, 1.f );
	m_uvScale = Vectors( 1.f, 1.f );
	m_uvOffset = Vectors( 0.f, 0.f );

	m_uSourceBlendMode	= GL_SRC_ALPHA;
	m_uDestinationBlendMode = GL_ONE_MINUS_SRC_ALPHA;

	glGenTextures(1, &m_uiTexture);
	glActiveTexture (GL_TEXTURE0);

	int width, height;
	unsigned char* image = SOIL_load_image(a_pTexture, &width, &height, 0, SOIL_LOAD_RGBA);
	glBindTexture( GL_TEXTURE_2D,m_uiTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	tex_loc = glGetUniformLocation (m_ShaderProgram, "diffuseTexture");
	glUseProgram (m_ShaderProgram);
	glUniform1i (tex_loc, 0); // use active texture 0

}

void Sprite::Draw()
{
	glBlendFunc (m_uSourceBlendMode, m_uDestinationBlendMode);
	glUseProgram(m_ShaderProgram);
	glActiveTexture(GL_TEXTURE0);
	glUniform1i (tex_loc, 0); 

	modelMatrix[12] = m_v3Position.x;
	modelMatrix[13] = m_v3Position.y;
	modelMatrix[14] = m_v3Position.z;


	glUniformMatrix4fv (matrix_location, 1, GL_FALSE, modelMatrix);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBindVertexArray(m_VAO);

	glDrawElements(GL_TRIANGLE_STRIP, 4,GL_UNSIGNED_INT,0);

	//////////////////////MORE SHIT TO EDIT TO WORK WITH YOUR CODE/////////////
	modelMatrix->a_fMatricesMatrix3D[0] = m_v2Scale.x; 
	modelMatrix->a_fMatricesMatrix3D[5] = m_v2Scale.y; 
	modelMatrix->a_fMatricesMatrix3D[12] = m_v3Position.x; 
	modelMatrix->a_fMatricesMatrix3D[13] = m_v3Position.y;
	modelMatrix->a_fMatricesMatrix3D[14] = m_v3Position.z; 

	Matrix4 MVP = (*Ortho * *modelMatrix); 

	glUniformMatrix4fv(matrix_location,1,GL_FALSE,MVP.a_fMatricesMatrix3D); 
}

void Sprite::Input()
{
	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_W))
	{
		m_v3Position += Vector3(0.0f, 0.005f, 0.0f);
	}

	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_A))
	{
		m_v3Position += Vector3(-0.005f, 0.0f, 0.0f);
	}

	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_S))
	{
		m_v3Position += Vector3(0.0f, -0.005f, 0.0f);
	}

	if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_D))
	{
		m_v3Position += Vector3(0.005f, 0.0f, 0.0f);
	}

}