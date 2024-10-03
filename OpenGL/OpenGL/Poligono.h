#pragma once
#include <vector>
#include "Punto3D.h"
#include "IncludeGL.h"

class Poligono {
public:
    void addVertex(const Punto3D& vertex) {
        vertices_.push_back(vertex);
    }

    void draw() const {
        if (vertices_.empty()) return;

        glColor3f(1.0f, 0.0f, 0.0f); // Rojo para el polígono

        glBegin(GL_POLYGON); // O GL_LINE_LOOP si prefieres solo los bordes
        for (const auto& vertex : vertices_) {
            float x, y, z;
            vertex.getPosition(x, y, z); // Debe coincidir con el método en Punto3D
            glVertex3f(x, y, z);
        }
        glEnd();
    }

private:
    std::vector<Punto3D> vertices_;
};
