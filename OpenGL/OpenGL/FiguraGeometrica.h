#pragma once
#include "IncludeGL.h"

class FiguraGeometrica {
public:
    FiguraGeometrica() {}

    void dibujarCubo(float size) const {
        glBegin(GL_QUADS);

        // Frontal
        glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
        glVertex3f(-size, -size, -size);
        glVertex3f(size, -size, -size);
        glVertex3f(size, size, -size);
        glVertex3f(-size, size, -size);

        // Trasero
        glColor3f(0.0f, 1.0f, 0.0f); // Color verde
        glVertex3f(-size, -size, size);
        glVertex3f(-size, size, size);
        glVertex3f(size, size, size);
        glVertex3f(size, -size, size);

        // Izquierdo
        glColor3f(0.0f, 0.0f, 1.0f); // Color azul
        glVertex3f(-size, -size, size);
        glVertex3f(-size, -size, -size);
        glVertex3f(-size, size, -size);
        glVertex3f(-size, size, size);

        // Derecho
        glColor3f(1.0f, 1.0f, 0.0f); // Color amarillo
        glVertex3f(size, -size, -size);
        glVertex3f(size, -size, size);
        glVertex3f(size, size, size);
        glVertex3f(size, size, -size);

        // Superior
        glColor3f(1.0f, 0.0f, 1.0f); // Color magenta
        glVertex3f(-size, size, -size);
        glVertex3f(size, size, -size);
        glVertex3f(size, size, size);
        glVertex3f(-size, size, size);

        // Inferior
        glColor3f(0.0f, 1.0f, 1.0f); // Color cian
        glVertex3f(-size, -size, -size);
        glVertex3f(-size, -size, size);
        glVertex3f(size, -size, size);
        glVertex3f(size, -size, -size);

        glEnd();
    }

    void dibujarEsfera(float radius, int slices, int stacks) const {
        GLUquadric* quadric = gluNewQuadric();
        gluSphere(quadric, radius, slices, stacks);
        gluDeleteQuadric(quadric);
    }
    void dibujarCilindro(float radius, float height, int slices, int stacks) const {
        GLUquadric* quadric = gluNewQuadric();
        gluCylinder(quadric, radius, radius, height, slices, stacks);
        gluDeleteQuadric(quadric);
    }

    void dibujarCono(float radius, float height, int slices, int stacks) const {
        GLUquadric* quadric = gluNewQuadric();
        gluCylinder(quadric, 0.0f, radius, height, slices, stacks); // Cono
        gluDeleteQuadric(quadric);
    }
    void dibujarCuadrado(float size) const {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
        glVertex2f(-size, -size); // Esquina inferior izquierda
        glVertex2f(size, -size);  // Esquina inferior derecha
        glVertex2f(size, size);   // Esquina superior derecha
        glVertex2f(-size, size);  // Esquina superior izquierda
        glEnd();
    }
    void dibujarTriangulo(float size) const {
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f); // Color verde
        glVertex2f(-size, -size);  // Esquina inferior izquierda
        glVertex2f(size, -size);   // Esquina inferior derecha
        glVertex2f(0.0f, size);    // Punto superior
        glEnd();
    }


};
