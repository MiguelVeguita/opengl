#include "Light.h"
#include <GL/glut.h>  // Incluye las funciones OpenGL

Light::Light() {
    // Inicializamos la luz con valores por defecto
    position[0] = position[1] = position[2] = 0.0f;
    position[3] = 1.0f; // Por defecto, es una luz puntual (w = 1.0)

    // Inicializamos los colores con valores por defecto
    ambient[0] = ambient[1] = ambient[2] = 0.2f; ambient[3] = 1.0f;
    diffuse[0] = diffuse[1] = diffuse[2] = 0.8f; diffuse[3] = 1.0f;
    specular[0] = specular[1] = specular[2] = 1.0f; specular[3] = 1.0f;
}

void Light::SetPosition(float x, float y, float z) {
    position[0] = x;
    position[1] = y;
    position[2] = z;
}

void Light::SetAmbient(float r, float g, float b, float a) {
    ambient[0] = r; ambient[1] = g; ambient[2] = b; ambient[3] = a;
}

void Light::SetDiffuse(float r, float g, float b, float a) {
    diffuse[0] = r; diffuse[1] = g; diffuse[2] = b; diffuse[3] = a;
}

void Light::SetSpecular(float r, float g, float b, float a) {
    specular[0] = r; specular[1] = g; specular[2] = b; specular[3] = a;
}
