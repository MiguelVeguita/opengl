#include "BMPTextureLoader.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#include "IncludeGL.h"
BMPTextureLoader::BMPTextureLoader() :TextureLoader()
{
}
GLuint BMPTextureLoader::LoadBMP(const char* fileName)
{
    FILE* file;
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int size;


    file = fopen(fileName, "rb");

    if (file == NULL)
    {
        printf("Error allocating space for image");
        return -1;
    }

    if (fread(header, 1, 54, file) != 54)
    {
        printf("Error nvaild file for image");
        return -1;
    }

    if (header[0] != 'B' || header[1] != 'M')
    {
        MessageBox(NULL, L"Error: Invaild file!", L"Error", MB_OK);
        return -1;
    }

    dataPos = *(int*)&(header[0x0A]);
    size = *(int*)&(header[0x22]);
    width = *(int*)&(header[0x12]);
    height = *(int*)&(header[0x16]);

    if (size == NULL)
        size = width * height * 3;
    if (dataPos == NULL)
        dataPos = 54;

    data = new unsigned char[size];

    fread(data, 1, size, file);

    fclose(file);

    return LoadParameter();
}

GLuint BMPTextureLoader::LoadParameter()
{
    return TextureLoader::LoadParameter();
}