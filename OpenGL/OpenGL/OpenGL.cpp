#include <Windows.h>
#include "IncludeGL.h"
#include "Example.h"
#include "Example5.h"
#include "PointLight.h"   // Asegúrate de incluir las cabeceras de luz
#include "SpotLight.h"
#include "DirectionalLight.h"

#include <iostream>
using namespace std;


Example* _Example;
PointLight pointLight;
SpotLight spotLight;
DirectionalLight dirLight;

void Render()
{
    ((Example5*)_Example)->Render();

}
void KeyboardFunc(unsigned char key, int X, int Y)
{
    ((Example5*)_Example)->KeyboardFunc(key, X, Y);
    glutPostRedisplay();
}


void reSize(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 10000.0f);
}

void Idle()
{
    ((Example5*)_Example)->Idle();
}

void init(void)
{

    _Example = new Example5();

    ((Example5*)_Example)->init();



}

int main(int argc, char** argv)
{
    GLuint width = 550;
    GLuint height = 550;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");

    init();

    glutDisplayFunc(Render);
    glutIdleFunc(Idle);
    glutKeyboardFunc(KeyboardFunc);
    glutReshapeFunc(reSize);
    glutMainLoop();

    return 0;
}
