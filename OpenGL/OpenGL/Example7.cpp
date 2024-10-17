#include "Example7.h"
#include "Cubo.h"
#include "Piramide.h"
#include "Esfera.h"
#include "Cuadrado.h"
#include "IncludeGL.h"


// Definiciones de vértices e índices para el cubo
GLfloat verticesCubo[] = {
    // Cara trasera
    -0.5f, -0.5f, -0.5f,  // Vértice 0
     0.5f, -0.5f, -0.5f,  // Vértice 1
     0.5f,  0.5f, -0.5f,  // Vértice 2
    -0.5f,  0.5f, -0.5f,  // Vértice 3

    // Cara frontal
    -0.5f, -0.5f,  0.5f,  // Vértice 4
     0.5f, -0.5f,  0.5f,  // Vértice 5
     0.5f,  0.5f,  0.5f,  // Vértice 6
    -0.5f,  0.5f,  0.5f,  // Vértice 7

    // Cara izquierda
    -0.5f, -0.5f, -0.5f,  // Vértice 0
    -0.5f,  0.5f, -0.5f,  // Vértice 3
    -0.5f,  0.5f,  0.5f,  // Vértice 7
    -0.5f, -0.5f,  0.5f,  // Vértice 4

    // Cara derecha
     0.5f, -0.5f, -0.5f,  // Vértice 1
     0.5f,  0.5f, -0.5f,  // Vértice 2
     0.5f,  0.5f,  0.5f,  // Vértice 6
     0.5f, -0.5f,  0.5f,  // Vértice 5

     // Cara superior
     -0.5f,  0.5f, -0.5f,  // Vértice 3
      0.5f,  0.5f, -0.5f,  // Vértice 2
      0.5f,  0.5f,  0.5f,  // Vértice 6
     -0.5f,  0.5f,  0.5f,  // Vértice 7

     // Cara inferior
     -0.5f, -0.5f, -0.5f,  // Vértice 0
      0.5f, -0.5f, -0.5f,  // Vértice 1
      0.5f, -0.5f,  0.5f,  // Vértice 5
     -0.5f, -0.5f,  0.5f   // Vértice 4
};




GLushort indicesCubo[] = {
    // Cara trasera
    0, 1, 2, 2, 3, 0,
    // Cara frontal
    4, 5, 6, 6, 7, 4,
    // Cara izquierda
    0, 3, 7, 7, 4, 0,
    // Cara derecha
    1, 5, 6, 6, 2, 1,
    // Cara superior
    3, 2, 6, 6, 7, 3,
    // Cara inferior
    0, 1, 5, 5, 4, 0
};


// Definiciones de vértices e índices para el cuadrado (Quad)
GLfloat verticesQuad[] = {
    -0.5f, -0.5f, 0.0f,  // Vértice 0 (abajo-izquierda)
     0.5f, -0.5f, 0.0f,  // Vértice 1 (abajo-derecha)
     0.5f,  0.5f, 0.0f,  // Vértice 2 (arriba-derecha)
    -0.5f,  0.5f, 0.0f   // Vértice 3 (arriba-izquierda)
};


GLushort indicesQuad[] = {
    0, 1, 2, 0, 2, 3 // Dos triángulos que forman el cuadrado
};

// Definiciones de vértices e índices para la pirámide
GLfloat verticesPiramide[] = {
    // Base de la pirámide (cuadrada)
    -0.5f, -0.5f, -0.5f,  // Vértice 0 (abajo-izquierda)
     0.5f, -0.5f, -0.5f,  // Vértice 1 (abajo-derecha)
     0.5f, -0.5f,  0.5f,  // Vértice 2 (arriba-derecha)
    -0.5f, -0.5f,  0.5f,  // Vértice 3 (arriba-izquierda)
    // Vértice superior (ajustado para que esté más alto)
     0.0f,  1.0f,  0.0f   // Vértice 4 (punta más alta, ajustada)
};


GLushort indicesPiramide[] = {
    0, 1, 4, // Lado 1
    1, 2, 4, // Lado 2
    2, 3, 4, // Lado 3
    3, 0, 4, // Lado 4
    0, 1, 2, 3 // Base
};
//
//// Definiciones de vértices e índices para la esfera (simplificado)
//GLfloat verticesEsfera[] = {
//    // Vértices de una esfera simplificada
//    // Aquí puedes agregar el algoritmo para generar vértices de esfera o usar un conjunto predefinido
//};
//
//GLushort indicesEsfera[] = {
//    // Índices de la esfera simplificada
//};

Example7::Example7() {}

void Example7::init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_VERTEX_ARRAY); // Activar el uso de Vertex Arrays
}

void Example7::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::DrawGrids();  // Dibuja las grillas

   //dibujarfifuras();  // Llama a la función para dibujar todas las figuras
    dibujarPiramideInstanciado();

    glutSwapBuffers();
}

void Example7::dibujarfifuras() {
    // Vertex Array Simple
    dibujarCuboSimple();
    dibujarCuadradoSimple();
    dibujarPiramideSimple();

    // Vertex Array Indexado
    dibujarCuboIndexado();
    dibujarCuadradoIndexado();
    dibujarPiramideIndexado();

    // Vertex Array Instanciado
    dibujarCuboInstanciado();
    dibujarCuadradoInstanciado();
   dibujarPiramideInstanciado();
}

// Vertex Array Simple

void Example7::dibujarCuboSimple() {
    glVertexPointer(3, GL_FLOAT, 0, verticesCubo);
    glDrawArrays(GL_TRIANGLES, 0, 36); // Dibuja el cubo con 36 vértices
}

void Example7::dibujarCuadradoSimple() {
    glVertexPointer(3, GL_FLOAT, 0, verticesQuad);
    // Dibuja dos triángulos para formar un cuadrado
    glBegin(GL_TRIANGLES);
    // Primer triángulo
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    // Segundo triángulo
    glArrayElement(0);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
}

void Example7::dibujarPiramideSimple() {
    glVertexPointer(3, GL_FLOAT, 0, verticesPiramide);

    glBegin(GL_TRIANGLES);
    // Caras laterales (4 triángulos)
    // Triángulo 1
    glArrayElement(0);  // Vértice de la base
    glArrayElement(1);  // Vértice de la base
    glArrayElement(4);  // Vértice superior

    // Triángulo 2
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(4);

    // Triángulo 3
    glArrayElement(2);
    glArrayElement(3);
    glArrayElement(4);

    // Triángulo 4
    glArrayElement(3);
    glArrayElement(0);
    glArrayElement(4);

    glEnd();

    // Base de la pirámide (usamos GL_QUADS o GL_TRIANGLE_FAN)
    glBegin(GL_QUADS);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
}

// Vertex Array Indexado
void Example7::dibujarCuboIndexado() {
    glVertexPointer(3, GL_FLOAT, 0, verticesCubo);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indicesCubo); // Dibuja el cubo indexado con triángulos
}

void Example7::dibujarCuadradoIndexado() {
    glVertexPointer(3, GL_FLOAT, 0, verticesQuad);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indicesQuad); // Dibuja el cuadrado indexado
}

void Example7::dibujarPiramideIndexado() {
    glVertexPointer(3, GL_FLOAT, 0, verticesPiramide);
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, indicesPiramide); // Dibuja la pirámide indexada
}

// Vertex Array Instanciado
void Example7::dibujarCuboInstanciado() {
    glVertexPointer(3, GL_FLOAT, 0, verticesCubo);
    for (int i = 0; i < 5; ++i) {
        glPushMatrix();
        glTranslatef(i * 2.0f, 0.0f, 0.0f); // Desplazar los cubos
        glDrawArrays(GL_QUADS, 0, 24);
        glPopMatrix();
    }
}

void Example7::dibujarCuadradoInstanciado() {
    glVertexPointer(3, GL_FLOAT, 0, verticesQuad);
    for (int i = 0; i < 5; ++i) {
        glPushMatrix();
        glTranslatef(i * 1.0f, 0.0f, 0.0f); // Desplazar los cuadrados
        dibujarCuadradoIndexado();
        glPopMatrix();
    }
}

void Example7::dibujarPiramideInstanciado() {
    glVertexPointer(3, GL_FLOAT, 0, verticesPiramide);
    for (int i = 0; i < 5; ++i) {
        glPushMatrix();
        glTranslatef(i * 2.0f, 0.0f, 0.0f); // Desplazar las pirámides
        dibujarPiramideIndexado();
        glPopMatrix();
    }
}

void Example7::KeyboardFunc(unsigned char key, int X, int Y) {
    // Implementa el manejo del teclado si es necesario
}

void Example7::Idle() 
{
  
}








//
//
//Example7::Example7()
//{
//
//}
//
//void Example7::init() {
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glClearDepth(1.0);
//    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
//    glEnable(GL_DEPTH_TEST);
//    glMatrixMode(GL_MODELVIEW);
//
//    cubo = new Cubo("Cubo", 1, 255, 1);          // Cambié "Cuadrado" por "Cubo"
//    cuadrado = new Cuadrado("Cuadrado", 1, 255, 1);     // Cuadrado
//    esfera = new Esfera("Esfera", 1, 150, 1);     // Esfera
//    piramide = new Piramide("Piramide", 1, 255, 1, 1);
//
//    
//   
//}
//
//void Example7::Render()
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    Example::DrawGrids();
//    dibujarfifuras();
//    glutSwapBuffers();
//}
//void Example7::dibujarfifuras()
//{
//    // Dibujar la pirámide
//    glPushMatrix(); // Guardar la matriz actual
//    glTranslatef(0.0f, 0.0f, 0.0f); // Posición de la pirámide
//    ((Piramide*)piramide)->dibujar();
//    glPopMatrix(); // Restaurar la matriz
//
//    // Dibujar el cubo
//    glPushMatrix(); // Guardar la matriz actual
//    glTranslatef(2.0f, 0.0f, 0.0f); // Mover el cubo 2 unidades a la derecha
//    ((Cubo*)cubo)->dibujar();
//    glPopMatrix(); // Restaurar la matriz
//
//    // Dibujar el cuadrado
//    glPushMatrix(); // Guardar la matriz actual
//    glTranslatef(-2.0f, 0.0f, 0.0f); // Mover el cuadrado 2 unidades a la izquierda
//    ((Cuadrado*)cuadrado)->dibujar();
//    glPopMatrix(); // Restaurar la matriz
//
//    // Dibujar la esfera
//    glPushMatrix(); // Guardar la matriz actual
//    glTranslatef(0.0f, 0.0f, -2.0f); // Mover la esfera 2 unidades hacia atrás
//    ((Esfera*)esfera)->dibujar();
//    glPopMatrix(); // Restaurar la matriz
//
//
//}
//
