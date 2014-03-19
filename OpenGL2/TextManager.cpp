#include "TextManager.h"

TextManager* TextManager::MInstance = 0; 

TextManager& TextManager::Instance()
{
	if(MInstance == 0)
		MInstance = new TextManager(); 
	return *MInstance;
}

TextManager::TextManager()
{
	atexit(&CleanUp); 

	glGenBuffers(1,&PositionBuffer); 
	glGenBuffers(1,&ColorBuffer); 
	glGenBuffers(1,&UVBuffer); 
	glGenBuffers(1,&MatrixBuffer); 
}

TextManager::~TextManager()
{
}

void TextManager::CleanUp()
{
	delete MInstance; 
	MInstance = 0; 
}

void TextManager::LoadFont(const char * a_pFontSheet)
{
	tinyxml2::XMLDocument doc; 
	tinyxml2::XMLNode *rootNode, *currentNode; 
	tinyxml2::XMLElement *childElement; 
	std::string str; 
	char ch; 
	doc.LoadFile(a_pFontSheet); 
	rootNode = doc.FirstChildElement("TextureAtlas"); 
	currentNode = rootNode; 

	childElement = currentNode->ToElement(); 
	TextAtlas.sSheet = childElement->Attribute("imagePath"); 
	TextAtlas.v2Size.x = (float)childElement->IntAttribute("width"); 
	TextAtlas.v2Size.y = (float)childElement->IntAttribute("height"); 
	TextAtlas.fKerning = (float)childElement->IntAttribute("kerning"); 

	iSprite.LoadTexture(TextAtlas.sSheet.c_str()); 
	iSprite.m_uvScale = TextAtlas.v2Size; 
	GLint uvAttrib = glGetAttribLocation(iSprite.m_ShaderProgram,"texcoord"); 
	glEnableVertexAttribArray(uvAttrib); 
	iSprite.matrix_location = glGetUniformLocation(iSprite.m_ShaderProgram, "matrix"); 

	for (childElement = currentNode->FirstChildElement(); childElement != NULL; childElement = childElement->NextSiblingElement())
	{
		str = childElement->Attribute("name"); 
		if(str.length() > 1)
		{
			if(str == "&amp")
				ch = '&'; 
			else if (str == "&apos")
				ch = '\''; 
			else if (str == "&astr")
				ch = '*'; 
			else if(str == "&bar")
				ch = '|';
			else if (str == "&bslsh")
				ch = '\\';
			else if (str == "&col")
				ch = ':';
			else if(str == "&fslsh")
				ch = '/';
			else if(str == "&gt")
				ch = '>'; 
			else if (str == "&lt")
				ch = '<'; 
			else if (str == "&quest")
				ch = '?';
			else if (str == "&quot")
				ch = '\"';
			else if (str == "&under")
				ch = '_';
		}
		else{
			ch = str.at(0); 
		}
		charMap[ch].Name = str; 
		charMap[ch].x0 = childElement->IntAttribute("x"); 
		charMap[ch].y0 = childElement->IntAttribute("y"); 
		charMap[ch].width = childElement->IntAttribute("width"); 
		charMap[ch].height = childElement->IntAttribute("height"); 
		charMap[ch].x1 = charMap[ch].x0 + charMap[ch].width; 
		charMap[ch].y1 = charMap[ch].y0 + charMap[ch].height; 
		charMap[ch].offset = childElement->IntAttribute("offset"); 
	}
	ch = ' '; 
	charMap[ch].Name = " "; 
	charMap[ch].x0 = 0; 
	charMap[ch].y0 = 0; 
	charMap[ch].width = 8; 
	charMap[ch].height = 8; 
	charMap[ch].x1 = 0; 
	charMap[ch].y1 = 0; 
	charMap[ch].offset = 0; 
	ch = '\n'; 
	charMap[ch].Name = "&ret"; 
	charMap[ch].x0 = 0; 
	charMap[ch].y0 = 0; 
	charMap[ch].width = 0; 
	charMap[ch].height = 0; 
	charMap[ch].x1 = 0; 
	charMap[ch].y1 = 0; 
	charMap[ch].offset = 0; 
}

void TextManager::LoadString(std::string str)
{
	DrawList.clear(); 
	char c; 
	for(CharCount = 0; CharCount < str.length();CharCount++)
	{
		c = str.at(CharCount); 
		DrawList.push_back(charMap[c]); 
	}
}

void TextManager::DrawString(std::string str, Vectors pos, float scale)
{
	LoadString(str); 

	Char c; 

	float newPos = 0; 
	for(int i = 0; i<DrawList.size(); i++)
	{
		c = DrawList[i];
		if(i != 0){
			if(c.Name == "&ret"){
				pos.x -= 20; 
				newPos = pos.y -4; 
			}
			else{
				newPos = iSprite.GetPosition().x + c.width/2 + DrawList[i-1].width/2 + TextAtlas.fKerning;
			}
			iSprite.SetPosition(Vector3(newPos, pos.y, 0.f)); 
		}
		else 
			iSprite.SetPosition(Vector3(pos.x + c.width/2, pos.y, 0.f)); 

		iSprite.m_minUVCoords = Vectors(c.x0, c.y0); 
		iSprite.m_maxUVCoords = Vectors(c.x1, c.y1); 
		iSprite.SetScale(c.width*scale, c.height*scale); 

		iSprite.SetUVData(); 

		iSprite.modelMatrix->a_fMatricesMatrix3D[0] = iSprite.GetScale().x *iSprite.m_fZoom;
		iSprite.modelMatrix->a_fMatricesMatrix3D[5] = iSprite.GetScale().y *iSprite.m_fZoom;					iSprite.modelMatrix->a_fMatricesMatrix3D[12] = iSprite.GetPosition().x; 
		iSprite.modelMatrix->a_fMatricesMatrix3D[13] = iSprite.GetPosition().y - (c.offset *iSprite.m_fZoom); 
		iSprite.modelMatrix->a_fMatricesMatrix3D[14] = iSprite.GetPosition().z; 


		*iSprite.MVP = (*Ortho * *iSprite.modelMatrix); 


		iSprite.Quad::Draw(); 
	}
}