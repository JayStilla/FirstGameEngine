#ifndef _ANIMATED_SPRITE_H_
#define _ANIMATED_SPRITE_H_



#include "Sprite.h"
#include <string> 
#include <tinyxml2.h>

struct AniSprite
{
	union{
		struct{
			std::string sName; 
			Vectors v2Size; 
			Vector4 v4Location; 
		}; 
		struct 
		{
			std::string Name; 
			float width, height; 
			float x0, x1, y0, y1; 
		};
	}; 
}; 

struct Atlas 
{
	Vectors v2Size; 
	std::string sSheet; 
	std::string sAnimations; 
};

typedef std::vector<std::string> frame; 

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(); 
	~AnimatedSprite(); 
	AnimatedSprite(const char* a_pSpriteSheet, GLFWwindow * window); 
	virtual void Draw(); 
	void Update(); 
	void SetAnimation(std::string animation, PlayType type);
	void SetAnimation(std::string animation, PlayType type, int frame); 
	void PlayAnimation(); 
	void SetSprite(); 
	void LoadSprite(const char* a_pSpriteSheet); 
	void LoadAnimation(const char* a_pAnimationSheet); 
	void Input(); 
	std::map<std::string,AniSprite> mSprites; 
	std::map<std::string,frame> mAnimations; 
	Atlas atlas; 

	std::string currentAnimation, currentSprite; 
	int currentFrame, loopFrame; 
	double m_dFrames;
	PlayType currentPlayType; 

	
	double elapsedTime; 
};

#endif