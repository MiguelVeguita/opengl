#include "Example6.h"
#include "Cubo.h"
#include "Triangulo.h"
#include "Esfera.h"
#include "Cuadrado.h"
#include <stdio.h>
#include "IncludeGL.h"
int quantity;
Example6::Example6() 
{

}

void Example6::init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);

    shape = new Cubo("Cubo", 1, 255, 1);          // Cambié "Cuadrado" por "Cubo"
    square = new Cuadrado("Cuadrado", 1, 255, 1);     // Cuadrado
    sphere = new Esfera("Esfera", 1, 150, 1);     // Esfera
    triangle = new Triangulo("Triangulo", 1, 255, 0.2, 1);

    // Crear las listas de display para cada figura
    ListCubo();
    ListEsfera();
    ListCuadrado();
}

void Example6::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::DrawGrids();

    for (int i = 0; i <= 3; i++)
    {
        glPushMatrix();
        glTranslatef(i * 2.0f, 0.0f, 0.0f);
        glCallList(cubolist);

        glTranslatef(i * -4.0f, 0.0f, 0.0f);
        glCallList(esferalist);

        glTranslatef(-2.0f, i * 1.5f, -5.0f);
        glCallList(cuadradolist);
        glPopMatrix();
    }
    glutSwapBuffers();
}

void Example6::ListCubo() {
    // Genera una lista de display para el cubo
    cubolist = glGenLists(1);
    glNewList(cubolist, GL_COMPILE);
    ((Cubo*)shape)->dibujar();  // Dibuja el cubo desde la clase `Cubo`
    glEndList();
}

void Example6::ListEsfera() {
    // Genera una lista de display para la esfera
    esferalist = glGenLists(1);
    glNewList(esferalist, GL_COMPILE);
    ((Esfera*)sphere)->dibujar();  // Dibuja la esfera desde la clase `Esfera`
    glEndList();
}

void Example6::ListCuadrado() {
    // Genera una lista de display para el cuadrado
    cuadradolist = glGenLists(1);
    glNewList(cuadradolist, GL_COMPILE);
    ((Cuadrado*)square)->dibujar();  // Dibuja el cuadrado desde la clase `Cubo`
    glEndList();
}

void Example6::KeyboardFunc(unsigned char key, int X, int Y) 
{
    // Implementa la funcionalidad del teclado según lo necesites
}

void Example6::Idle()
{
    // Implementa la funcionalidad de inactividad si es necesaria
}
