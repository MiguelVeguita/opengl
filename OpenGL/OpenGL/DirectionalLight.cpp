#include "DirectionalLight.h"
#include <GL/glut.h>

DirectionalLight::DirectionalLight() {
    position[3] = 0.0f; // Luz direccional
    direction[0] = 0.0f; // Inicializa dirección
    direction[1] = -1.0f; // Inicializa dirección (hacia abajo)
    direction[2] = 0.0f; // Inicializa dirección
}

void DirectionalLight::SetDirection(float x, float y, float z) {
    direction[0] = x;
    direction[1] = y;
    direction[2] = z;
}

void DirectionalLight::EnableLight() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT2);  // Suponiendo que es la luz 2

    glLightfv(GL_LIGHT2, GL_POSITION, position);
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direction); // Configura la dirección
}

void DirectionalLight::DisableLight() {
    glDisable(GL_LIGHT2);
}
