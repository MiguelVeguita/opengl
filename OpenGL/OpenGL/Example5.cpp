#include "Example5.h"
#include "BMPTextureLoader.h" // Asegúrate de incluir tu cargador de texturas

Example5::Example5()
    : shape(new FiguraGeometrica()), // Inicializa FiguraGeometrica
    _TextureLoader(new BMPTextureLoader()), // Inicializa el cargador de texturas
    texture(0) // Inicializa texture
{
}

void Example5::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);

    // Habilitar texturas
    glEnable(GL_TEXTURE_2D);

    // Establecer el modo de mezcla de texturas a REPLACE para evitar que se oscurezcan
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    // Cargar la textura usando el método correcto
    texture = _TextureLoader->LoadBMP("textures/wallBMP.bmp");
    if (texture == (GLuint)-1)
    {
        printf("Error loading texture\n");
    }
}


void Example5::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::DrawGrids();

    dibujarFiguras(); // Llama a la función para dibujar las figuras

    glFlush();
}

void Example5::dibujarFiguras()
{
    glEnable(GL_TEXTURE_2D); // Habilitar texturas

    glPushMatrix();
    glTranslatef(-1.5f, 0.0f, 0.0f); // Mover a la izquierda
    glBindTexture(GL_TEXTURE_2D, texture); // Aplicar textura al cuadrado
    shape->dibujarCuadrado(0.5f); // Tamaño del cuadrado
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, 0.0f, 0.0f); // Mover a la derecha
    glBindTexture(GL_TEXTURE_2D, texture); // Aplicar textura al triángulo
    shape->dibujarTriangulo(0.5f); // Tamaño del triángulo
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.5f, 0.0f); // Mover hacia abajo
    glBindTexture(GL_TEXTURE_2D, texture); // Aplicar textura al cubo
    shape->dibujarCubo(0.5f); // Tamaño del cubo
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f); // Mover hacia arriba
    glBindTexture(GL_TEXTURE_2D, texture); // Aplicar textura a la esfera
    shape->dibujarEsfera(0.5f, 20, 20); // Radio y divisiones
    glPopMatrix();

    glDisable(GL_TEXTURE_2D); // Deshabilitar texturas al finalizar
}



void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
    // Manejo de eventos del teclado si es necesario
}

void Example5::Idle()
{
    // Manejo del estado de inactividad si es necesario
}

Example5::~Example5() {
    delete shape; // Limpiar memoria de FiguraGeometrica
    delete _TextureLoader; // Limpiar memoria de TextureLoader
}
