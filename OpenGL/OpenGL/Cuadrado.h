#pragma once
#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura2D.h"

class Cuadrado : public Figura2D {
private:
    int lado;

public:
    Cuadrado(std::string nom, int grosor, int col, int l);
    int calcularArea() override;
    int calcularPerimetro() override;
    void cambiarTamaño(int nuevoLado);
    void dibujar() override;

};

#endif
