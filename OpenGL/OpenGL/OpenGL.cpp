#include <Windows.h>
#include "IncludeGL.h"
#include "Example.h"
#include "Example7.h"


#include <iostream>
using namespace std;


Example* _Example;


void Render()
{
    ((Example7*)_Example)->Render();

}
void KeyboardFunc(unsigned char key, int X, int Y)
{
    ((Example7*)_Example)->KeyboardFunc(key, X, Y);
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
    ((Example7*)_Example)->Idle();
}

void init(void)
{

    _Example = new Example7();

    ((Example7*)_Example)->init();



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
