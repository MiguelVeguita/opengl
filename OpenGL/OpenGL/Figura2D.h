#pragma once
#ifndef FIGURA2D_H
#define FIGURA2D_H

#include "Figura.h"

class Figura2D : public Figura {
public:
    Figura2D(std::string nom, int grosor, int col);
    virtual int calcularArea() = 0;         // Método virtual puro
    virtual int calcularPerimetro() = 0;    // Método virtual puro
};

#endif

