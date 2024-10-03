#pragma once
#include "IncludeGL.h"
class TextureLoader
{
protected:
	GLuint texture;
	unsigned int width, height;
	unsigned char* data;
public:
	TextureLoader();
	virtual GLuint LoadParameter();
};