#include "Piramide.h"
#include <iostream>

Piramide::Piramide(std::string nom, int grosor, int col, int b, int h)
    : Figura3D(nom, grosor, col), base(b), altura(h) {}

int Piramide::calcularVolumen() {
    return (base * base * altura) / 3;
}

void Piramide::dibujar() {
    std::cout << "Dibujando una pirámide" << std::endl;

}
