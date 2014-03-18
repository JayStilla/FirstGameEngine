#ifndef _TEXTMANAGER_H_
#define _TEXTMANAGER_H_
#include "Utilities.h"
#include <tinyxml2.h>
#include "AnimatedSprite.h"

struct Char 
{
	union{
		struct{
			std::string sName; 
			Vectors v2Size; 
			Vector4 v4Location; 
			float yOffset; 
		};
		struct{
			std::string Name; 
			float width, height; 
			float x0, x1, y0, y1; 
			float offset; 
		};
	};
};

struct Text{
	Vectors v2Size; 
	std::string sSheet; 
	float fKerning; 
};
class TextManager
{
public:
	static TextManager& Instance(); 

	void LoadFont(const char * a_pFontSheet); 
	void DrawString(std::string str, Vectors pos, float scale); 
private:
	static void CleanUp(); 

	TextManager();
	~TextManager(); 
	void LoadString(std::string str); 

	Sprite iSprite; 
	Text TextAtlas; 
	std::map<char, Char> charMap; 
	std::vector<Char> DrawList; 
	int CharCount; 

	static TextManager* MInstance; 

	GLuint PositionBuffer; 
	GLuint ColorBuffer; 
	GLuint UVBuffer; 
	GLuint MatrixBuffer; 

};




#endif