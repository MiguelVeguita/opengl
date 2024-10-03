#include "Example2.h"
#include "IncludeGL.h"
#include "Punto3D.h"
#include "Poligono.h"
#include <iostream>
#include <cmath> // Para usar std::cos y std::sin

// Example2.cpp
Example2::Example2()
    : punto(4.0f, 4.0f, 4.0f), showMenu(false), figureToDraw(0),
    translationX(0.0f), translationY(0.0f), translationZ(0.0f),
    rotationAngleX(0.0f), rotationAngleY(0.0f), rotationAngleZ(0.0f)
{
}



void Example2::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);

    punto.setPosition(4.0f, 4.0f, 4.0f);

    poligono.addVertex(Punto3D(1.0f, 1.0f, 0.0f));
    poligono.addVertex(Punto3D(-1.0f, 1.0f, 0.0f));
    poligono.addVertex(Punto3D(-1.0f, -1.0f, 0.0f));
    poligono.addVertex(Punto3D(1.0f, -1.0f, 0.0f));
}

void Example2::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (showMenu)
    {
        // Dibuja el menú aquí
        glColor3f(1.0f, 1.0f, 1.0f); // Blanco para el texto del menú
        glRasterPos2f(-0.9f, 0.9f);
        const char* menuText = "1: Draw Axes\n2: Draw Point\n3: Draw Line\n4: Draw Chain\n5: Draw Figure\nM: Toggle Menu";
        for (const char* c = menuText; *c; ++c)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
        }
    }
    else
    {
        DrawGrid();

        // Aplicar las transformaciones globales antes de dibujar la figura
        glPushMatrix();
        glTranslatef(translationX, translationY, translationZ);
        glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f); // Rotación alrededor del eje X
        glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f); // Rotación alrededor del eje Y
        glRotatef(rotationAngleZ, 0.0f, 0.0f, 1.0f); // Rotación alrededor del eje Z

        // Dibuja la figura seleccionada
        switch (figureToDraw)
        {
        case 1:
            DrawTransformedAxes();
            break;
        case 2:
            DrawTransformedPoint();
            break;
        case 3:
            DrawTransformedLine();
            break;
        default:
            break;
        }

        glPopMatrix();
    }

    glFlush();
}

void Example2::DrawGrid()
{
    const int gridSize = 10; // Tamaño de la rejilla
    const float step = 1.0f; // Espaciado entre líneas de la rejilla

    glColor3f(0.5f, 0.5f, 0.5f); // Color gris para la rejilla

    // Dibujar líneas paralelas al eje Z en el plano Z-X
    for (float i = -gridSize; i <= gridSize; i += step)
    {
        glBegin(GL_LINES);
        glVertex3f(-gridSize, 0.0f, i);  // Línea en el plano Z-X
        glVertex3f(gridSize, 0.0f, i);
        glEnd();
    }

    // Dibujar líneas paralelas al eje X en el plano Z-X
    for (float i = -gridSize; i <= gridSize; i += step)
    {
        glBegin(GL_LINES);
        glVertex3f(i, 0.0f, -gridSize);  // Línea en el plano Z-X
        glVertex3f(i, 0.0f, gridSize);
        glEnd();
    }
}


void Example2::DrawTransformedPoint()
{
    // Aplicar transformaciones
    glPushMatrix();  // Guardar el estado actual de la matriz

    glTranslatef(2.0f, 2.0f, 0.0f); // Trasladar el punto en el espacio
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // Rotar el punto 45 grados en el eje Z
    glScalef(1.5f, 1.5f, 1.0f); // Escalar el punto

    glPointSize(20.0f);  // Definir el tamaño del punto
    glBegin(GL_POINTS);
    glVertex3f(0.0f, 0.0f, 0.0f);  // Dibujar un punto en el origen (tras las transformaciones)
    glEnd();

    glPopMatrix();  // Restaurar el estado de la matriz
}

void Example2::DrawTransformedLine()
{
    // Aplicar transformaciones
    glPushMatrix();  // Guardar el estado actual de la matriz

    glTranslatef(-1.0f, 3.0f, 0.0f); // Trasladar la línea en el espacio
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f); // Rotar 30 grados en el eje Z
    glScalef(2.0f, 1.0f, 1.0f); // Escalar la línea

    glColor3f(0.0f, 1.0f, 0.0f);  // Color verde
    glBegin(GL_LINES);
    glVertex3f(-1.0f, 0.0f, 0.0f);  // Punto inicial de la línea
    glVertex3f(1.0f, 0.0f, 0.0f);   // Punto final de la línea
    glEnd();

    glPopMatrix();  // Restaurar el estado de la matriz
}


void Example2::DrawTransformedAxes()
{
    // Aplicar transformaciones
    glPushMatrix();  // Guardar el estado actual de la matriz

    glTranslatef(0.0f, 0.0f, 0.0f); // Trasladar los ejes (opcional)
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f); // Rotar 90 grados en el eje Z
    glScalef(1.0f, 1.0f, 1.0f); // Escalar los ejes

    // Eje X (rojo)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(-3.0f, 0.0f, 0.0f);  // Punto izquierdo del eje X
    glVertex3f(3.0f, 0.0f, 0.0f);   // Punto derecho del eje X
    glEnd();

    // Eje Y (verde)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, -3.0f, 0.0f);  // Punto inferior del eje Y
    glVertex3f(0.0f, 3.0f, 0.0f);   // Punto superior del eje Y
    glEnd();

    glPopMatrix();  // Restaurar el estado de la matriz
}






void Example2::DrawAxeYX()
{
    // Dibujar el eje X (horizontal) en rojo
    glColor3f(3.0f, 0.0f, 0.0f);  // Rojo para el eje X
    glBegin(GL_LINES);
    glVertex3f(-3.0f, 0.0f, 0.0f);  // Punto izquierdo del eje X
    glVertex3f(3.0f, 0.0f, 0.0f);   // Punto derecho del eje X
    glEnd();

    // Dibujar el eje Y (vertical) en verde
    glColor3f(0.0f, 3.0f, 0.0f);  // Verde para el eje Y
    glBegin(GL_LINES);
    glVertex3f(0.0f, -3.0f, 0.0f);  // Punto inferior del eje Y
    glVertex3f(0.0f, 3.0f, 0.0f);   // Punto superior del eje Y
    glEnd();
}






void Example2::DrawAxes()
{
    // Dibujar el eje X (horizontal) en rojo
    glColor3f(3.0f, 0.0f, 0.0f);  // Rojo para el eje X
    glBegin(GL_LINES);
    glVertex3f(-3.0f, 0.0f, 0.0f);  // Punto izquierdo del eje X
    glVertex3f(3.0f, 0.0f, 0.0f);   // Punto derecho del eje X
    glEnd();

    // Dibujar el eje Y (vertical) en verde
    glColor3f(0.0f, 3.0f, 0.0f);  // Verde para el eje Y
    glBegin(GL_LINES);
    glVertex3f(0.0f, -3.0f, 0.0f);  // Punto inferior del eje Y
    glVertex3f(0.0f, 3.0f, 0.0f);   // Punto superior del eje Y
    glEnd();
}



void Example2::KeyboardFunc(unsigned char key, int X, int Y)
{
    const float increment = 1.0f; // Cantidad de movimiento/rotación

    switch (key)
    {
    case 'w': // Mover hacia adelante
        translationZ -= increment;
        break;
    case 's': // Mover hacia atrás
        translationZ += increment;
        break;
    case 'a': // Mover a la izquierda
        translationX -= increment;
        break;
    case 'd': // Mover a la derecha
        translationX += increment;
        break;
    case 'q': // Mover hacia arriba
        translationY += increment;
        break;
    case 'e': // Mover hacia abajo
        translationY -= increment;
        break;
    case 'x': // Rotar alrededor del eje X
        rotationAngleX += increment;
        break;
    case 'y': // Rotar alrededor del eje Y
        rotationAngleY += increment;
        break;
    case 'z': // Rotar alrededor del eje Z
        rotationAngleZ += increment;
        break;
    case '1':
        figureToDraw = 1;  // Ejes de coordenadas
        break;
    case '2':
        figureToDraw = 2;  // Punto
        break;
    case '3':
        figureToDraw = 3;  // Línea
        break;
    case 'm': // Alternar el menú
        ToggleMenu();
        break;
    }
    glutPostRedisplay();
}


void Example2::ToggleMenu()
{
    showMenu = !showMenu;
}

void Example2::Idle()
{
    // Aquí puedes añadir cualquier lógica adicional para el estado Idle si es necesario
}
