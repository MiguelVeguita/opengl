#include "Circulo.h"
#include <iostream>

Circulo::Circulo(std::string nom, int grosor, int col, int r)
    : Figura2D(nom, grosor, col), radio(r) {}

int Circulo::calcularArea() {
    return 3.1416 * radio * radio;
}

int Circulo::calcularPerimetro() {
    return 2 * 3.1416 * radio;
}

void Circulo::cambiarTamaño(int nuevoRadio) {
    radio = nuevoRadio;
}

void Circulo::dibujar() {
    std::cout << "Dibujando un círculo" << std::endl;
}
