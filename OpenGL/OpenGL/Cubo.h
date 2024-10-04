#pragma once
#ifndef CUBO_H
#define CUBO_H

#include "Figura3D.h"

class Cubo : public Figura3D {
private:
    int lado;

public:
    Cubo(std::string nom, int grosor, int col, int l);
    int calcularVolumen() override;
    void dibujar() override;
};

#endif
