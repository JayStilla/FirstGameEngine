#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::~AnimatedSprite()
{
}
//overloaded constructor
AnimatedSprite::AnimatedSprite(const char* a_pSpriteSheet, GLFWwindow * window)
{
	//assigning the window
	GameWindow = window; 
	//setting a base time
	elapsedTime = 0; 
	//loading in a sprite sheet
	LoadSprite(a_pSpriteSheet);
	//loading in the animation atlas
	LoadAnimation(atlas.sAnimations.c_str());
	//setting the atlas for the animation
	SetTexture(atlas.sSheet.c_str()); 
	
	m_dFrames = (1.0/15.0); 
	currentAnimation = ""; 
	currentSprite = "idle"; 
	currentFrame = 0; 
	currentPlayType = SINGLE; 
	m_uvScale.x = atlas.v2Size.y; 
	m_uvScale.y = atlas.v2Size.x; 
	SetSprite(); 
	SetUVData(); 

}

void AnimatedSprite::SetSprite()
{
	if(currentAnimation == "")
	{
		m_minUVCoords.x = mSprites["idle"].y0; 
		m_minUVCoords.y = mSprites["idle"].x0; 
		m_maxUVCoords.x = mSprites["idle"].y1; 
		m_maxUVCoords.y = mSprites["idle"].x1; 

		m_v2Scale.x = mSprites["idle"].width; 
		m_v2Scale.y = mSprites["idle"].height; 
	}
	else
	{
		m_minUVCoords.x = mSprites[currentSprite].y0; 
		m_minUVCoords.y = mSprites[currentSprite].x0; 
		m_maxUVCoords.x = mSprites[currentSprite].y1; 
		m_maxUVCoords.y = mSprites[currentSprite].x1; 
		m_v2Scale.x = mSprites[currentSprite].width; 
		m_v2Scale.y = mSprites[currentSprite].height; 

	}
}

void AnimatedSprite::LoadSprite(const char* a_pSpriteSheet)
{
	//making a tiny xml document
	tinyxml2::XMLDocument doc; 
	//making 2 nodes
	tinyxml2::XMLNode *rootNode, *currentNode;
	//making 1 element
	tinyxml2::XMLElement *childElement;
	//making 1 string to use over and over
	std::string str; 
	doc.LoadFile(a_pSpriteSheet); //load the sprite sheet
	rootNode = doc.FirstChildElement("atlas"); //setting the root node
	currentNode = rootNode; 

	childElement = currentNode->ToElement(); //to not override the root node(safety precaution)
	atlas.v2Size.x = (float)childElement->IntAttribute("width"); 
	atlas.v2Size.y = (float)childElement->IntAttribute("height"); 
	atlas.sSheet = childElement->Attribute("sheet"); 
	atlas.sAnimations = childElement->Attribute("animations"); 

	for(childElement = currentNode->FirstChildElement(); childElement != NULL; childElement = childElement->NextSiblingElement())
	{
		str = childElement->Attribute("name"); 
		mSprites[str].Name = str; 
		mSprites[str].x0 = childElement->IntAttribute("x0"); 
		mSprites[str].x1 = childElement->IntAttribute("x1"); 
		mSprites[str].y0 = childElement->IntAttribute("y0"); 
		mSprites[str].y1 = childElement->IntAttribute("y1"); 
		mSprites[str].height = mSprites[str].y1 - mSprites[str].y0; 
		mSprites[str].width = mSprites[str].x1 - mSprites[str].x0; 
	}
	std::printf("done"); 
}	
void AnimatedSprite::LoadAnimation(const char* a_pAnimationSheet)
{
	//pretty much the same as above
	tinyxml2::XMLDocument doc; 
	tinyxml2::XMLNode *rootNode, *currentNode; 
	tinyxml2::XMLElement *childElement, *child; 
	std::string str, aniName; 
	doc.LoadFile(a_pAnimationSheet);

	for(childElement = currentNode->ToElement(); childElement != NULL; childElement = childElement->NextSiblingElement())
	{
		aniName = childElement->Attribute("name"); 
		for(child = childElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
		{
			str = child->Attribute("name");
			mAnimations[aniName].push_back(str); 
		}
	}
	std::printf("done"); 
}

void AnimatedSprite::SetAnimation(std::string animation, PlayType type)
{
	currentAnimation = animation; 
	currentFrame = 0; 
	loopFrame = 0; 
	currentPlayType = type; 
	switch(type)
	{
	case ONCE: 

		break; 
	case LOOP: 
		loopFrame = 0; 
	case PINGPONG: 
		break;
	case REVERSE: 
		currentFrame = mAnimations[currentAnimation].size(); 
		loopFrame = currentFrame; 
		break; 
	case RANDOMLOOP:
	case RANDOM:
		srand(time(NULL)); 
		currentFrame = (unsigned int)(rand()% mAnimations[currentAnimation].size()); 
		loopFrame = currentFrame; 
		break; 
	case LOOPSECTION:
		SetAnimation(animation,type,0); 
	case SINGLE:
		break; 
	default:
		break; 
	}

	currentSprite = mAnimations.at(currentAnimation)[currentFrame]; 
	SetSprite(); 
	SetUVData(); 
}

void AnimatedSprite::SetAnimation(std::string animation, PlayType type, int frame)
{
	switch(type)
	{
	case LOOPSECTION:
		currentAnimation = animation; 
		currentFrame = 0; 
		currentPlayType = type; 
		loopFrame = frame; 
		break; 
	default:
		SetAnimation(animation,type); 
		break; 
	}
}

void AnimatedSprite::PlayAnimation()
{
	elapsedTime += getDeltaTime(); 

	if(elapsedTime > m_dFrames)
	{
		elapsedTime = 0; 
		switch(currentPlayType)
		{
		case ONCE:
			if(mAnimations.at(currentAnimation)[currentFrame] != mAnimations.at(currentAnimation).back())
			{
				currentFrame++; 
				currentSprite = mAnimations.at(currentAnimation)[currentFrame]; 
			}
			break;
		case LOOPSECTION:
		case LOOP: 
			if(mAnimations.at(currentAnimation)[currentFrame] == mAnimations.at(currentAnimation).back())
			{
				currentFrame = loopFrame; 
				currentSprite = mAnimations.at(currentAnimation)[currentFrame]; 
			}
			else
			{
				currentFrame++; 
				currentSprite = mAnimations.at(currentAnimation)[currentFrame]; 
			}
			break; 
		case PINGPONG:
			break; 
		case REVERSE: 
			currentFrame = mAnimations[currentAnimation].size(); 
			loopFrame = currentFrame; 
			break; 
		case RANDOMLOOP:
		case RANDOM: 
			srand(time(NULL)); 
			currentFrame = rand() % mAnimations[currentAnimation].size(); 
			loopFrame = currentFrame; 
			break; 
		case SINGLE: 
			break; 
		default:
			break;
		}
		SetSprite(); 
		SetUVData(); 
	}
}

void AnimatedSprite::Draw()
{
	glBlendFunc(m_uSourceBlendMode, m_uDestinationBlendMode); 
	glUseProgram(m_ShaderProgram); 
	glActiveTexture(GL_TEXTURE0); 
	glUniform1i(tex_loc, 0); 

	modelMatrix->a_fMatricesMatrix3D[0] = m_v2Scale.x *m_fZoom; 
	modelMatrix->a_fMatricesMatrix3D[5] = m_v2Scale.y *m_fZoom; 
	modelMatrix->a_fMatricesMatrix3D[12] = m_v3Position.x; 
	modelMatrix->a_fMatricesMatrix3D[13] = m_v3Position.y + ( (m_v2Scale.y *m_fZoom)/2.f); 
	modelMatrix->a_fMatricesMatrix3D[14] = m_v3Position.z; 

	Matrix4 MVP = (*Ortho * *modelMatrix); 

	glUniformMatrix4fv(matrix_location, 1, GL_FALSE, MVP.a_fMatricesMatrix3D); 

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO); 
	glBufferData(GL_ARRAY_BUFFER, 4* sizeof(Vertex), m_aoVerts, GL_DYNAMIC_DRAW); 

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO); 
	glBindVertexArray(m_VAO); 

	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT,0); 
}

void AnimatedSprite::Input()
{
	Sprite::Input();
	if(GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_P))
	{
		SetAnimation("idle to run", LOOPSECTION, 1); 

	}
	if(GLFW_PRESS == glfwGetKey(GameWindow, GLFW_KEY_T))
	{
		SetAnimation("teleport",ONCE); 
	}

}

void AnimatedSprite::Update()
{
	this->AnimatedSprite::Input(); 
	this->AnimatedSprite::Draw(); 
	PlayAnimation(); 
}