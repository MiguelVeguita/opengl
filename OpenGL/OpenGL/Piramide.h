#pragma once
#include <GL/gl.h> // Aseg�rate de incluir la librer�a OpenGL

#ifndef PIRAMIDE_H
#define PIRAMIDE_H


#include "Figura3D.h"

class Piramide : public Figura3D {
private:
    int base;
    int altura;

public:
    Piramide(std::string nom, int grosor, int col, int b, int h);
    int calcularVolumen() override;
    void dibujar() override;


};

#endif
