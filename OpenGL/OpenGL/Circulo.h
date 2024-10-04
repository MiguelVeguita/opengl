#pragma once
#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura2D.h"

class Circulo : public Figura2D {
private:
    int radio;


public:
    Circulo(std::string nom, int grosor, int col, int r);
    int calcularArea() override;
    int calcularPerimetro() override;
    void cambiarTamaño(int nuevoRadio);
    void dibujar() override;
};

#endif
