#include "Piramide.h"
#include <GL/glut.h>
#include <iostream>

Piramide::Piramide(std::string nom, int grosor, int col, int b, int h)
    : Figura3D(nom, grosor, col), base(b), altura(h) {}

int Piramide::calcularVolumen() {
    return (base * base * altura) / 3;  // Fórmula del volumen de una pirámide
}

void Piramide::dibujar() {
    glBegin(GL_TRIANGLES);

    // Lado 1
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex3f(0.0f, altura, 0.0f);
    glVertex3f(-base / 2.0f, 0.0f, base / 2.0f);
    glVertex3f(base / 2.0f, 0.0f, base / 2.0f);

    // Lado 2
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex3f(0.0f, altura, 0.0f);
    glVertex3f(base / 2.0f, 0.0f, base / 2.0f);
    glVertex3f(base / 2.0f, 0.0f, -base / 2.0f);

    // Lado 3
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    glVertex3f(0.0f, altura, 0.0f);
    glVertex3f(base / 2.0f, 0.0f, -base / 2.0f);
    glVertex3f(-base / 2.0f, 0.0f, -base / 2.0f);

    // Lado 4
    glColor3f(1.0f, 1.0f, 0.0f); // Amarillo
    glVertex3f(0.0f, altura, 0.0f);
    glVertex3f(-base / 2.0f, 0.0f, -base / 2.0f);
    glVertex3f(-base / 2.0f, 0.0f, base / 2.0f);

    glEnd();

    // Dibujar la base (cuadrado)
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f); // Gris
    glVertex3f(-base / 2.0f, 0.0f, -base / 2.0f);
    glVertex3f(base / 2.0f, 0.0f, -base / 2.0f);
    glVertex3f(base / 2.0f, 0.0f, base / 2.0f);
    glVertex3f(-base / 2.0f, 0.0f, base / 2.0f);
    glEnd();

    std::cout << "Dibujando una pirámide" << std::endl;
}
