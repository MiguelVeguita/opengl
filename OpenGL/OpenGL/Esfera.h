#pragma once
#ifndef ESFERA_H
#define ESFERA_H

#include "Figura3D.h"

class Esfera : public Figura3D {
private:
    int radio;

public:
    Esfera(std::string nom, int grosor, int col, int r);
    int calcularVolumen() override;
    void dibujar() override;

};

#endif
