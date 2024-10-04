#include "Cuadrado.h"
#include <iostream>
#include <GL/glut.h>


Cuadrado::Cuadrado(std::string nom, int grosor, int col, int l)
    : Figura2D(nom, grosor, col), lado(l) {}

int Cuadrado::calcularArea() {
    return lado * lado;
}

int Cuadrado::calcularPerimetro() {
    return 4 * lado;
}

void Cuadrado::cambiarTamaño(int nuevoLado) {
    lado = nuevoLado;
}


void Cuadrado::dibujar() {
    glBegin(GL_QUADS);
    glVertex2f(-lado / 2.0f, -lado / 2.0f);
    glVertex2f(lado / 2.0f, -lado / 2.0f);
    glVertex2f(lado / 2.0f, lado / 2.0f);
    glVertex2f(-lado / 2.0f, lado / 2.0f);
    glEnd();
    std::cout << "Dibujando un cuadrado" << std::endl;
}
