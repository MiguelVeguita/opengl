#pragma once
#include "Example.h"
#include "FiguraGeometrica.h"
#include "Vector3.h"
#include "BMPTextureLoader.h" // Incluye el cargador de texturas BMP
class Example5 :
    public Example
{
    FiguraGeometrica* shape;
    Vector3 pos;
    BMPTextureLoader* _TextureLoader; // Cambiado a BMPTextureLoader
    GLuint texture;
public:
    Example5();
    virtual void init() override;
    virtual void Render() override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void Idle() override;
    void dibujarFiguras();
    ~Example5(); // Declaración del destructor
};
