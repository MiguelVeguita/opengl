#include "PointLight.h"
#include <GL/glut.h>  // Asegúrate de incluir las funciones de OpenGL

PointLight::PointLight() : Light() {
    // Puedes personalizar la luz puntual si lo deseas
}

void PointLight::EnableLight() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); // Usa el índice de luz correspondiente

    // Configura las propiedades de la luz
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

void PointLight::DisableLight() {
    glDisable(GL_LIGHT0); // Deshabilita la luz puntual
}
