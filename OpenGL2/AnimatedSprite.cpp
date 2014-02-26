#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::~AnimatedSprite()
{
}

AnimatedSprite::AnimatedSprite(const char* a_pSpriteSheet, GLFWwindow * window)
{
	GameWindow = window; 
	elapsedTime = 0; 
	LoadSprite(a_pSpriteSheet); 
	LoadAnimation(atlas.sAnimations.c_str()); 
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

		m_uv2Scale.x = mSprites["idle"].width; 
		m_uv2Scale.y = mSprites["idle"].height; 
	}
	else
	{
		m_minUVCoords.x = mSprites[currentSprite].y0; 
		m_minUVCoords.y = mSprites[currentSprite].x0; 
		m_maxUVCoords.x = mSprites[currentSprite].y1; 
		m_maxUVCoords.y = mSprites[currentSprite].x1; 
		m_uv2Scale.x = mSprites[currentSprite].width; 
		m_uv2Scale.y = mSprites[currentSprite].height; 

	}
}

void AnimatedSprite::LoadSprite(const char* a_pSpriteSheet)
{
	tinyxml2::XMLDocument doc; 
	tinyxml2::XMLNode *rootNode, *currentNode; 
	tinyxml2::XMLElement *childElement; 
	std::string str; 
	doc.LoadFile(a_pSpriteSheet); //load the sprite sheet
	rootNode = doc.FirstChildElement("atlas"); //setting the root node
	currentNode = rootNode; 

	childElement = currentNode->ToElement(); 
	atlas.v2Size.x = (float)childElement->IntAttribute("width"); 
	atlas.v2Size.y = (float)childElement->IntAttribute("height"); 
	atlas.sSheet = childElement->Attribute("sheet"); 
	atlas.sAnimations = childElement->Attribute("animations"); 

	for(childElement = currentNode->FirstChildElement(); childElement != NULL; childElement = childElement->NextSibling())
	{
		str = childElement->Attribute("name"); 
		mSprites[str].Name = str; 
		mSprites[str].x0 = childElement->IntAttribute("x0"); 
		mSprites[str].x1 = childElement->IntAttribute("x1"); 
		mSprites[str].y0 = childElement->IntAttribute("y0"); 
		mSprites[str].y1 = childElement->IntAttribute("y1"); 
		mSprites[str].height = mSprites[str].y1 - mSprites[str].y0; 
		mSprites[str].width = mSprites
	}
}	
