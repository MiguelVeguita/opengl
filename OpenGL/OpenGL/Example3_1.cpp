#include "Example3_1.h"
#include "IncludeGL.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void Example3_1::init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Color de fondo gris oscuro
    glClearDepth(1.0);

    // Inicializar la cámara
    cameraPosX = 0.0f;
    cameraPosY = 5.0f;
    cameraPosZ = 10.0f; // Posición inicial de la cámara

    cameraYaw = 0.0f;   // Orientación inicial
    cameraPitch = 0.0f; // Orientación inicial

    glMatrixMode(GL_MODELVIEW);
}

void Example3_1::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    UpdateCamera(); // Actualiza la posición y orientación de la cámara

    // Dibuja la cuadrícula, ejes y figuras después de establecer la cámara
    DrawGrid();
    DrawAxes();
    RenderFigures();

    glFlush();
}

void Example3_1::UpdateCamera() {
    gluLookAt(cameraPosX, cameraPosY, cameraPosZ,
        cameraPosX + cosf(cameraYaw * M_PI / 180.0f) * cosf(cameraPitch * M_PI / 180.0f),
        cameraPosY + sinf(cameraPitch * M_PI / 180.0f),
        cameraPosZ + sinf(cameraYaw * M_PI / 180.0f) * cosf(cameraPitch * M_PI / 180.0f),
        0.0f, 1.0f, 0.0f); // Vector "up"
}

void Example3_1::DrawGrid() {
    const int gridSize = 10;
    const float step = 1.0f;

    glColor3f(0.5f, 0.5f, 0.5f);
    for (float i = -gridSize; i <= gridSize; i += step) {
        glBegin(GL_LINES);
        glVertex3f(-gridSize, 0.0f, i);
        glVertex3f(gridSize, 0.0f, i);
        glEnd();
    }

    for (float i = -gridSize; i <= gridSize; i += step) {
        glBegin(GL_LINES);
        glVertex3f(i, 0.0f, -gridSize);
        glVertex3f(i, 0.0f, gridSize);
        glEnd();
    }
}

void Example3_1::RenderFigures() {
    // Dibuja un cubo en el eje Z
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -15.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    figura.dibujarCubo(1.0f);
    glPopMatrix();

    // Dibuja una esfera verde
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    figura.dibujarEsfera(0.5f, 20, 20);
    glPopMatrix();

    // Dibuja un cilindro rojo
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    figura.dibujarCilindro(0.5f, 1.0f, 20, 20);
    glPopMatrix();

    // Dibuja un cono azul
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    figura.dibujarCono(0.5f, 1.0f, 20, 20);
    glPopMatrix();
}

void Example3_1::DrawAxes() {
    // Eje X (rojo)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(-5.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);
    glEnd();

    // Eje Y (verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, -5.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);
    glEnd();

    // Eje Z (azul)
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, -5.0f);
    glVertex3f(0.0f, 0.0f, 5.0f);
    glEnd();
}

void Example3_1::KeyboardFunc(unsigned char key, int X, int Y) {
    float cameraSpeed = 0.1f;

    switch (key) {
    case 'w': // Adelante
        cameraPosX += cameraSpeed * cosf(cameraYaw * M_PI / 180.0f);
        cameraPosZ += cameraSpeed * sinf(cameraYaw * M_PI / 180.0f);
        break;
    case 's': // Atrás
        cameraPosX -= cameraSpeed * cosf(cameraYaw * M_PI / 180.0f);
        cameraPosZ -= cameraSpeed * sinf(cameraYaw * M_PI / 180.0f);
        break;
    case 'a': // Izquierda
        cameraPosX -= cameraSpeed * sinf(cameraYaw * M_PI / 180.0f);
        cameraPosZ += cameraSpeed * cosf(cameraYaw * M_PI / 180.0f);
        break;
    case 'd': // Derecha
        cameraPosX += cameraSpeed * sinf(cameraYaw * M_PI / 180.0f);
        cameraPosZ -= cameraSpeed * cosf(cameraYaw * M_PI / 180.0f);
        break;
    case 27: // Esc para salir
        exit(0);
    }
}

void Example3_1::MouseMotionFunc(int x, int y) {
    static int lastX = 400; // Suponiendo que la ventana tiene 800 de ancho
    static int lastY = 300; // Suponiendo que la ventana tiene 600 de alto
    static bool firstMouse = true;

    if (firstMouse) {
        lastX = x;
        lastY = y;
        firstMouse = false;
    }

    int xOffset = x - lastX;
    int yOffset = lastY - y;  // Invertir el movimiento vertical
    lastX = x;
    lastY = y;

    float sensitivity = 0.1f;
    cameraYaw += xOffset * sensitivity;
    cameraPitch += yOffset * sensitivity;

    // Limitar el ángulo de inclinación para evitar volteretas
    if (cameraPitch > 89.0f)
        cameraPitch = 89.0f;
    if (cameraPitch < -89.0f)
        cameraPitch = -89.0f;
}

void Example3_1::Idle() {
    // Aquí podrías incluir lógica de actualización continua
}
