#include "Triangulo.h"
#include <iostream>
#include <GL/glut.h>

Triangulo::Triangulo(std::string nom, int grosor, int col, float b, float h)
    : Figura2D(nom, grosor, col), base(b), altura(h) {}

int Triangulo::calcularArea() {
    return (base * altura) / 2;
}

int Triangulo::calcularPerimetro() {
    // Suponemos un triángulo equilátero para este ejemplo
    return 3 * base;
}


void Triangulo::cambiarTamaño(int nuevaBase, int nuevaAltura) {
    base = nuevaBase;
    altura = nuevaAltura;
}

void Triangulo::dibujar() {

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex2f(-base / 2.0f, 0.0f);
    glVertex2f(base / 2.0f, 0.0f);
    glVertex2f(0.0f, altura);
    glEnd();
    std::cout << "Dibujando un triángulo" << std::endl;
}
