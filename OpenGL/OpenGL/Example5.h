#pragma once
#include "Example.h"
#include "Figura.h"
#include "Cubo.h"
#include "Esfera.h"
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Vector3.h"
#include "TextureLoader.h"

class Example5 : public Example
{
    Figura* shape;      // Puntero a la figura base
    Figura* square;   // Puntero al cuadrado
    Figura* triangle; // Puntero al triángulo
    Figura* sphere;     // Puntero a la esfera
    Vector3 pos;        // Posición
    TextureLoader* _TextureLoader; // Cargador de texturas
    GLuint texture;     // Textura

public:
    Example5();
    virtual void init() override;
    virtual void Render() override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void Idle() override;
    void DrawShape();
};
