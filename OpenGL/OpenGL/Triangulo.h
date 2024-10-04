#pragma once
#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura2D.h"

class Triangulo : public Figura2D {
private:
    int base;
    int altura;

public:
    Triangulo(std::string nom, int grosor, int col, float b, float h);
    int calcularArea() override;
    int calcularPerimetro() override;
    void cambiarTamaño(int nuevaBase, int nuevaAltura);
    void dibujar() override;

};

#endif
