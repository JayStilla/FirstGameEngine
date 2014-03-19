#include "Sprite.h"

Sprite::Sprite(void)
{
	srand(time(NULL));
	LoadVertShader("VertexShader.glsl");
	LoadFragShader("FragShader.glsl");
	LinkShaders();

	m_v4SpriteColor = Vector4(1,1,1,1);
	

	m_aoVerts[0].Color = m_v4SpriteColor;
	m_aoVerts[1].Color = m_v4SpriteColor;
	m_aoVerts[2].Color = m_v4SpriteColor;
	m_aoVerts[3].Color = m_v4SpriteColor;

	m_aoVerts[0].UV = Vectors(0.0f,  0.0f);
	m_aoVerts[1].UV = Vectors(0.0f,  1.0f);
	m_aoVerts[2].UV = Vectors(1.0f,  0.0f);
	m_aoVerts[3].UV = Vectors(1.0f,  1.0f);

	
	m_v2Scale = Vectors(1,1);


	m_v3Position = Vector3(g_gl_width/2,g_gl_height/2,0);

}


Sprite::~Sprite(void)
{
}
Sprite::Sprite( const char* a_pTexture, int a_iWidth, int a_iHeight, Vector4 a_v4Color ,GLFWwindow * window)
{
 
	GameWindow = window;
	
	LoadVertShader("VertexShader.glsl");
	LoadFragShader("FragShader.glsl");
	LinkShaders();
	GLint uvAttrib = glGetAttribLocation(m_ShaderProgram,"texcoord");
	glEnableVertexAttribArray(uvAttrib);
	matrix_location = glGetUniformLocation (m_ShaderProgram, "matrix");
	LoadTexture(a_pTexture);


	m_v4SpriteColor = a_v4Color;

	
	m_aoVerts[0].Color = m_v4SpriteColor;
	m_aoVerts[1].Color = m_v4SpriteColor;
	m_aoVerts[2].Color = m_v4SpriteColor;
	m_aoVerts[3].Color = m_v4SpriteColor;
	
	m_v2Scale = Vectors(a_iWidth,a_iHeight);

	m_v3Position = Vector3(g_gl_width/2,g_gl_height/2,0);

}


void Sprite::Draw()
{
	modelMatrix->a_fMatricesMatrix3D[0]  = m_v2Scale.x * m_fZoom;
	modelMatrix->a_fMatricesMatrix3D[5]  = m_v2Scale.y * m_fZoom;
	modelMatrix->a_fMatricesMatrix3D[12] = m_v3Position.x;
	modelMatrix->a_fMatricesMatrix3D[13] = m_v3Position.y;
	modelMatrix->a_fMatricesMatrix3D[14] = m_v3Position.z;


	*MVP =  (*Ortho * *modelMatrix) ;


	glUniformMatrix4fv (matrix_location, 1, GL_FALSE, MVP->a_fMatricesMatrix3D);
	Quad::Draw();
	
}

void Sprite::Input()
{
	  if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_W))
        {
			m_v3Position += Vector3(0.0f, 1.f, 0.0f);
	  }

        if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_A))
        {
                m_v3Position += Vector3(-1.f, 0.0f, 0.0f);
        }
        if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_S))
        {
			m_v3Position += Vector3(0.0f, -1.f, 0.0f);
		}
		 if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_D))
        {
			m_v3Position += Vector3(1.0f, 0.f, 0.0f);
		}
		 if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_C))
        {
                 m_fZoom *= (1 - getDeltaTime());
        }
		  if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_Z))
        {
                 m_fZoom *=( 1 + getDeltaTime());

        }

		 if (GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_V))
        {
			
               SetColor(
				   Vector4((rand()%255)/255.f,(rand()%255)/255.f,(rand()%255)/255.f,1.f),
				   Vector4((rand()%255)/255.f,(rand()%255)/255.f,(rand()%255)/255.f,1.f),
				   Vector4((rand()%255)/255.f,(rand()%255)/255.f,(rand()%255)/255.f,1.f),
				   Vector4((rand()%255)/255.f,(rand()%255)/255.f,(rand()%255)/255.f,1.f)
				   );

        }

}

void Sprite::SetPosition(Vector3 a_v3Pos)
{
	m_v3Position = a_v3Pos;

}
void Sprite::SetPosition(float a_fX, float a_fY)
{
	m_v3Position.x  = a_fX;
	m_v3Position.y  = a_fY;

}
Vector3 Sprite::GetPosition()
{
	return m_v3Position;

}
void Sprite::SetScale(Vectors a_v2Scale)
{
	m_v2Scale = a_v2Scale;
}
void Sprite::SetScale(float a_fScale)
{
	m_v2Scale.x = a_fScale;
	m_v2Scale.y = a_fScale;
}

void Sprite::SetScale(float a_fScaleX,float a_fScaleY)
{
	m_v2Scale.x = a_fScaleX;
	m_v2Scale.y = a_fScaleY;
}
Vectors Sprite::GetScale()
{
	return m_v2Scale;

}