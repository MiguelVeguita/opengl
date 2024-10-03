// Example2.h
#pragma once
#include "Example.h"
#include "Punto3D.h"
#include "Poligono.h"

class Example2 : public Example
{
public:
    Example2();

    virtual void init() override;
    virtual void Render() override;
    void DrawAxeYX();
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void Idle() override;

    void DrawAxes();
    void DrawTransformedAxes();
    void DrawTransformedPoint();
    void DrawTransformedLine();
    void DrawGrid();
    void ToggleMenu(); // M�todo para alternar entre el men� y el dibujo normal

private:
    Punto3D punto;
    Poligono poligono;
    bool showMenu; // Variable para controlar la visualizaci�n del men�
    int figureToDraw; // Variable para seleccionar qu� figura dibujar

    // Variables para las transformaciones
    float translationX;
    float translationY;
    float translationZ;
    float rotationAngleX;
    float rotationAngleY;
    float rotationAngleZ;
};
