#include "Example4.h"
#include "IncludeGL.h"
#include <iostream>

Example4::Example4() {
    pointLight = new PointLight();
    pointLight->SetPosition(2.0f, 2.0f, 0.0f);
    pointLight->SetAmbient(0.2f, 0.2f, 0.2f, 1.0f);
    pointLight->SetDiffuse(0.8f, 0.8f, 0.8f, 1.0f);
    pointLight->SetSpecular(1.0f, 1.0f, 1.0f, 1.0f);
    directionalLight = new DirectionalLight();
    directionalLight->SetPosition(0.0f, 10.0f, 0.0f); // Ajustar la posición
    directionalLight->SetDirection(0.0f, -1.0f, 0.0f); // Direcciona hacia abajo
    directionalLight->SetAmbient(0.2f, 0.2f, 0.2f, 1.0f);
    directionalLight->SetDiffuse(0.8f, 0.8f, 0.8f, 1.0f);
    directionalLight->SetSpecular(1.0f, 1.0f, 1.0f, 1.0f);

    spotLight = new SpotLight();
    spotLight->SetPosition(-2.0f, 2.0f, 0.0f);
    spotLight->SetSpotDirection(0.0f, -1.0f, 0.0f);

    currentLight = pointLight; // Luz inicial
}

Example4::~Example4() {
    delete pointLight;
    delete directionalLight;
    delete spotLight;
}

void Example4::init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}

void Example4::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawAxis(50);
    DrawGrid();

    // Configurar la luz actual
    if (currentLight)
    {
        currentLight->EnableLight();
    }

    ConfigurarMaterial();


    // Dibujar esferas
    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glShadeModel(GL_FLAT);
    glutSolidSphere(1.0f, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 0.0f);
    glShadeModel(GL_SMOOTH);
    glutSolidSphere(1.0f, 50, 50);
    glPopMatrix();

    glFlush();
}

void Example4::KeyboardFunc(unsigned char key, int X, int Y) {
    // Desactivar la luz actual si existe
    if (currentLight) {
        currentLight->DisableLight();
    }

    // Cambiar la luz según la tecla presionada
    switch (key) {
    case '1':
        currentLight = pointLight;
        break;
    case '2':
        currentLight = directionalLight;
        break;
    case '3':
        currentLight = spotLight;
        break;
    default:
        currentLight = nullptr;  // No hay luz activa si se presiona otra tecla
        break;
    }

    // Activar la nueva luz
    if (currentLight) {
        currentLight->EnableLight();
    }

    glutPostRedisplay();  // Redibujar la escena
}

void Example4::Idle() {
    // Puedes agregar lógica aquí si necesitas
}

void Example4::DrawGrid() {
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

void Example4::ConfigurarMaterial() {
    // Definir propiedades del material
    GLfloat mat_ambiente[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat mat_difuso[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    GLfloat mat_especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat brillo[] = { 50.0f };  // Brillo (especular)

    // Configurar el material
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_difuso);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_especular);
    glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}
