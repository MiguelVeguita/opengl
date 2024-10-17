#pragma once
#include "Example.h"
#include "Figura.h"

class Example7 : public Example {
    Figura* cubo;
    Figura* cuadrado;
    Figura* esfera;
    Figura* piramide;

public:
    Example7();
    virtual void init() override;
    virtual void Render() override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void Idle() override;
    void dibujarfifuras();

    // Métodos para dibujar usando Vertex Array Simple
    void dibujarCuboSimple();
    void dibujarCuadradoSimple();
   // void dibujarEsferaSimple();
    void dibujarPiramideSimple();

    // Métodos para dibujar usando Vertex Array Indexado
    void dibujarCuboIndexado();
    void dibujarCuadradoIndexado();
   // void dibujarEsferaIndexado();
    void dibujarPiramideIndexado();

    // Métodos para dibujar usando Vertex Array Instanciado
    void dibujarCuboInstanciado();
    void dibujarCuadradoInstanciado();
   // void dibujarEsferaInstanciado();
    void dibujarPiramideInstanciado();
};

