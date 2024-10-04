#pragma once
#ifndef FIGURA3D_H
#define FIGURA3D_H

#include "Figura.h"

class Figura3D : public Figura {
public:
    Figura3D(std::string nom, int grosor, int col);
    virtual int calcularVolumen() = 0;  // Método virtual puro
};

#endif
