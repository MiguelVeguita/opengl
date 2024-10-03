#pragma once
#include "IncludeGL.h"

class Punto3D {
public:
    Punto3D(float x = 0.0f, float y = 0.0f, float z = 0.0f)
        : x_(x), y_(y), z_(z) {}

    void setPosition(float x, float y, float z) {
        x_ = x; y_ = y; z_ = z;
    }

    void getPosition(float& x, float& y, float& z) const {
        x = x_; y = y_; z = z_;
    }

    void draw() const {
        glPointSize(40.0f); // Tamaño del punto
        glBegin(GL_POINTS); // Comienza a dibujar puntos
        glVertex3f(x_, y_, z_); // Especifica el vértice del punto
        glEnd(); // Finaliza el dibujo
    }

private:
    float x_, y_, z_;
};
