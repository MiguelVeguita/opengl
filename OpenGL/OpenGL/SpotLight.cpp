#include "SpotLight.h"
#include <GL/glut.h>

SpotLight::SpotLight() {
    position[0] = position[1] = position[2] = 0.0f; // Inicializa la posición
    position[3] = 1.0f; // Luz puntual
    spotDirection[0] = 0.0f; // Inicializa dirección del foco
    spotDirection[1] = -1.0f; // Por defecto, hacia abajo
    spotDirection[2] = 0.0f;
}

void SpotLight::SetSpotDirection(float x, float y, float z) {
    spotDirection[0] = x;
    spotDirection[1] = y;
    spotDirection[2] = z;
}

void SpotLight::EnableLight() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);  // Suponiendo que es la luz 1

    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0f); // Ángulo del foco
}

void SpotLight::DisableLight() {
    glDisable(GL_LIGHT1);
}
