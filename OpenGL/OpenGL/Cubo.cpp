#include "Cubo.h"
#include <GL/glut.h>
#include <iostream>

Cubo::Cubo(std::string nom, int grosor, int col, int l)
    : Figura3D(nom, grosor, col), lado(l) {}

int Cubo::calcularVolumen() {
    return lado * lado * lado;
}

void Cubo::dibujar() {
    // Dibujar el cubo
    glBegin(GL_QUADS);

    // Frente
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex3f(-lado / 2.0f, -lado / 2.0f, lado / 2.0f);
    glVertex3f(lado / 2.0f, -lado / 2.0f, lado / 2.0f);
    glVertex3f(lado / 2.0f, lado / 2.0f, lado / 2.0f);
    glVertex3f(-lado / 2.0f, lado / 2.0f, lado / 2.0f);

    // Atrás
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex3f(-lado / 2.0f, -lado / 2.0f, -lado / 2.0f);
    glVertex3f(-lado / 2.0f, lado / 2.0f, -lado / 2.0f);
    glVertex3f(lado / 2.0f, lado / 2.0f, -lado / 2.0f);
    glVertex3f(lado / 2.0f, -lado / 2.0f, -lado / 2.0f);

    // Izquierda
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    glVertex3f(-lado / 2.0f, -lado / 2.0f, -lado / 2.0f);
    glVertex3f(-lado / 2.0f, -lado / 2.0f, lado / 2.0f);
    glVertex3f(-lado / 2.0f, lado / 2.0f, lado / 2.0f);
    glVertex3f(-lado / 2.0f, lado / 2.0f, -lado / 2.0f);

    // Derecha
    glColor3f(1.0f, 1.0f, 0.0f); // Amarillo
    glVertex3f(lado / 2.0f, -lado / 2.0f, -lado / 2.0f);
    glVertex3f(lado / 2.0f, lado / 2.0f, -lado / 2.0f);
    glVertex3f(lado / 2.0f, lado / 2.0f, lado / 2.0f);
    glVertex3f(lado / 2.0f, -lado / 2.0f, lado / 2.0f);

    // Arriba
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(-lado / 2.0f, lado / 2.0f, -lado / 2.0f);
    glVertex3f(-lado / 2.0f, lado / 2.0f, lado / 2.0f);
    glVertex3f(lado / 2.0f, lado / 2.0f, lado / 2.0f);
    glVertex3f(lado / 2.0f, lado / 2.0f, -lado / 2.0f);

    // Abajo
    glColor3f(0.5f, 0.5f, 0.5f); // Gris
    glVertex3f(-lado / 2.0f, -lado / 2.0f, -lado / 2.0f);
    glVertex3f(lado / 2.0f, -lado / 2.0f, -lado / 2.0f);
    glVertex3f(lado / 2.0f, -lado / 2.0f, lado / 2.0f);
    glVertex3f(-lado / 2.0f, -lado / 2.0f, lado / 2.0f);

    glEnd();

    std::cout << "Dibujando un cubo" << std::endl; // Mensaje en consola
}
