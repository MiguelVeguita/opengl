#include "Example1.h"
#include "IncludeGL.h"
#include "Punto3D.h"
#include "Poligono.h"
#include <iostream>
#include <cmath> // Para usar std::cos y std::sin

Example1::Example1()
    : punto(4.0f, 4.0f, 4.0f), showMenu(false), figureToDraw(0) // Inicialización
{
}

void Example1::init()
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

void Example1::Render()
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

        // Dibuja la figura seleccionada
        switch (figureToDraw)
        {
        case 1:
            DrawAxeYX();
            break;
        case 2:
            DrawPoint();
            break;
        case 3:
            DrawLine();
            break;
        case 4:
            DrawCadena();
            break;
        case 5:
            DrawFigura();
            break;
        default:
            break;
        }
    }

    glFlush();
}

void Example1::DrawAxeYX()
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

void Example1::DrawPoint()
{
    // Definir el tamaño del punto
    glPointSize(10.0f);  // Tamaño del punto (opcional)

    // Obtener las coordenadas del punto
    float x, y, z;
    punto.getPosition(x, y, z);  // Obtener las coordenadas usando el método getPosition()

    // Dibujar el punto
    glBegin(GL_POINTS);
    glVertex3f(x, y, z);  // Coordenadas del punto
    glEnd();
}

void Example1::DrawLine()
{
    // Establecer el color rosa (1.0, 0.0, 1.0)
    glColor3f(1.0f, 0.0f, 1.0f);  // Rojo + Azul = Rosa

    // Dibujar la línea
    glBegin(GL_LINES);
    glVertex3f(-4.5f, 1.0f, 0.0f);  // Punto inicial de la línea (izquierda)
    glVertex3f(2.5f, 1.0f, 0.0f);   // Punto final de la línea (derecha)
    glEnd();
}

void Example1::DrawCadena()
{
    // Establecer el color (puede ser cualquier color, aquí un ejemplo con cian)
    glColor3f(0.0f, 1.0f, 1.0f);  // Cian (verde + azul)

    // Dibujar la cadena de líneas
    glBegin(GL_LINE_STRIP);
    glVertex3f(-0.5f, 0.0f, 0.0f);  // Primer punto
    glVertex3f(-0.3f, 0.3f, 0.0f);  // Segundo punto
    glVertex3f(0.0f, 0.1f, 0.0f);   // Tercer punto
    glVertex3f(0.3f, -0.2f, 0.0f);  // Cuarto punto
    glVertex3f(0.5f, 0.0f, 0.0f);   // Quinto punto
    glVertex3f(0.7f, -0.3f, 0.0f);   // Punto 6
    glVertex3f(1.0f, 0.2f, 0.0f);    // Punto 7
    glVertex3f(1.2f, -0.1f, 0.0f);   // Punto 8
    glVertex3f(1.5f, 0.4f, 0.0f);    // Punto 9
    glVertex3f(1.7f, 0.0f, 0.0f);    // Punto 10
    glEnd();
}

void Example1::DrawGrid()
{
    // Establecer el color de las líneas de la rejilla (gris claro)
    glColor3f(0.8f, 0.8f, 0.8f);  // Gris claro

    // Tamaño de la rejilla
    float gridSize = 10.0f;   // Tamaño total de la rejilla
    float spacing = 1.0f;    // Espaciado entre líneas

    // Dibujar líneas horizontales
    glBegin(GL_LINES);
    for (float i = -gridSize; i <= gridSize; i += spacing) {
        glVertex3f(-gridSize, 0.0f, i);  // Línea horizontal (XZ)
        glVertex3f(gridSize, 0.0f, i);   // Línea horizontal (XZ)
    }
    glEnd();

    // Dibujar líneas verticales
    glBegin(GL_LINES);
    for (float i = -gridSize; i <= gridSize; i += spacing) {
        glVertex3f(i, 0.0f, -gridSize);  // Línea vertical (XZ)
        glVertex3f(i, 0.0f, gridSize);   // Línea vertical (XZ)
    }
    glEnd();
}

void Example1::DrawAxes()
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

void Example1::DrawFigura()
{
    // Establecer el color de la figura (puede ser cualquier color, aquí un ejemplo con azul)
    glColor3f(0.0f, 0.0f, 1.0f);  // Azul

    // Dibujar la figura (puede ser cualquier figura o polígono definido aquí)
    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();
}

void Example1::KeyboardFunc(unsigned char key, int X, int Y)
{
    switch (key)
    {
    case '1':
        figureToDraw = 1;
        break;
    case '2':
        figureToDraw = 2;
        break;
    case '3':
        figureToDraw = 3;
        break;
    case '4':
        figureToDraw = 4;
        break;
    case '5':
        figureToDraw = 5;
        break;
    case 'm':
    case 'M':
        ToggleMenu();
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void Example1::ToggleMenu()
{
    showMenu = !showMenu;
}

void Example1::Idle()
{
    // Aquí puedes añadir cualquier lógica adicional para el estado Idle si es necesario
}
