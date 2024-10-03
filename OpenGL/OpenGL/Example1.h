#pragma once
#include "Example.h"
#include "Punto3D.h"   
#include "Poligono.h" 

class Example1 : public Example
{
public:
    Example1();

    virtual void init() override;
    virtual void Render() override;
    void DrawAxeYX();
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void Idle() override;

    void DrawAxes();
    void DrawPoint();
    void DrawLine();
    void DrawCadena();
    void DrawFigura();
    void DrawGrid();
    void ToggleMenu(); // Método para alternar entre el menú y el dibujo normal

private:
    Punto3D punto;
    Poligono poligono;
    bool showMenu; // Variable para controlar la visualización del menú
    int figureToDraw; // Variable para seleccionar qué figura dibujar
};
