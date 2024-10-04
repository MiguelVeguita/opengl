#pragma once
#ifndef FIGURA_H
#define FIGURA_H

#include <string>

class Figura {
protected:
    std::string nombre;
    int grosorBorde;
    int color;

public:
    Figura(std::string nom, int grosor, int col);
    virtual void dibujar() = 0;  // Método virtual puro
    virtual ~Figura() = default; // Destructor virtual
};

#endif

