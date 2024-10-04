#include "Esfera.h"
#include <iostream>
#include <GL/glut.h>


Esfera::Esfera(std::string nom, int grosor, int col, int r)
    : Figura3D(nom, grosor, col), radio(r) {}

int Esfera::calcularVolumen() {
    return (4 / 3.0) * 3.1416 * radio * radio * radio;
}

void Esfera::dibujar() {
    glutSolidSphere(radio, 20, 20); // Dibuja la esfera
    std::cout << "Dibujando una esfera" << std::endl;
}
