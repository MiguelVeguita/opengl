#include "Example3.h"
#include "IncludeGL.h"
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Example3::Example3() {
    camera = new Camera;
}

void Example3::init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    camera->Init();
camera->SetPosition(Vector3(5, 5, 5));  // Posición inicial de la cámara
    glMatrixMode(GL_MODELVIEW);
}

void Example3::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->Update();
    DrawGrid();
    DrawAxes();
    RenderFigures();
    glFlush();
}

void Example3::DrawGrid() {
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

void Example3::RenderFigures() {
    // Dibuja un cubo en el eje Z
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -8.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    figura.dibujarCubo(1.0f);
    glPopMatrix();

    // Dibuja una esfera verde
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    figura.dibujarEsfera(0.5f, 20, 20);
    glPopMatrix();

    // Dibuja un cilindro rojo
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -3.0f);
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

void Example3::DrawAxes() {
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

void Example3::KeyboardFunc(unsigned char key, int X, int Y) {
    float cameraSpeed = 0.1f;
    float frontX = cosf(camera->GetYaw() * M_PI / 180.0f) * cosf(camera->GetPitch() * M_PI / 180.0f);
    float frontZ = sinf(camera->GetYaw() * M_PI / 180.0f) * cosf(camera->GetPitch() * M_PI / 180.0f);

    switch (key) {
    case 'w': // Adelante
        camera->SetPosition(camera->GetPosition() + Vector3(frontX * cameraSpeed, 0.0f, frontZ * cameraSpeed));
        break;
    case 's': // Atrás
        camera->SetPosition(camera->GetPosition() - Vector3(frontX * cameraSpeed, 0.0f, frontZ * cameraSpeed));
        break;
    case 'a': // Izquierda
        camera->SetPosition(camera->GetPosition() - Vector3(
            cosf((camera->GetYaw() - 90) * M_PI / 180.0f) * cameraSpeed, 0.0f,
            sinf((camera->GetYaw() - 90) * M_PI / 180.0f) * cameraSpeed));
        break;
    case 'd': // Derecha
        camera->SetPosition(camera->GetPosition() + Vector3(
            cosf((camera->GetYaw() - 90) * M_PI / 180.0f) * cameraSpeed, 0.0f,
            sinf((camera->GetYaw() - 90) * M_PI / 180.0f) * cameraSpeed));
        break;
    case 27: // Esc para salir
        exit(0);
    }
}

void Example3::MouseMotionFunc(int x, int y) {
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

    float sensitivity = 0.1f; // Sensibilidad del mouse
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    camera->SetYaw(camera->GetYaw() + xOffset);
    camera->SetPitch(camera->GetPitch() + yOffset);

    // Limitar el ángulo de la cámara
    if (camera->GetPitch() > 89.0f) camera->SetPitch(89.0f);
    if (camera->GetPitch() < -89.0f) camera->SetPitch(-89.0f);

    camera->UpdateDirection(); // Asegúrate de que la dirección se actualice aquí
}


void Example3::Idle() {
    // Lógica opcional en Idle
}
