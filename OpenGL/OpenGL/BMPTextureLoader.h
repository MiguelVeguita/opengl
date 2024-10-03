#pragma once
#include "TextureLoader.h"
class BMPTextureLoader :
    public TextureLoader
{

public:
    BMPTextureLoader();
    GLuint LoadBMP(const char* fileName);
    virtual GLuint LoadParameter() override;
};
