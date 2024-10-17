#include "Example.h"
#include <GL/glut.h>
#include <stdio.h>

Example::Example()
{
}

void Example::DrawAxis(float distance)
{
	 
}

void Example::DrawGrids()
{
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

