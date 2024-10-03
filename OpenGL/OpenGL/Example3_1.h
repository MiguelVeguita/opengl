#pragma once
#include "Example.h"
#include "FiguraGeometrica.h"

class Example3_1 : public Example {
public:
    virtual void init() override;
    virtual void Render() override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void Idle() override;
    void DrawGrid();
    void DrawAxes();
    void MouseMotionFunc(int x, int y);
    void RenderFigures();

    // Otras variables necesarias para la c�mara
    float cameraPosX, cameraPosY, cameraPosZ;
    float cameraYaw, cameraPitch; // Para manejar la orientaci�n de la c�mara

private:
    FiguraGeometrica figura;

    // Agrega m�todos para manejar la l�gica de la c�mara
    void UpdateCamera();
};
