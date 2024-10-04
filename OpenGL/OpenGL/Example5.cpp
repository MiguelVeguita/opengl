#include "Example5.h"
//#include "Color.h"
#include "Cubo.h"
#include <stdio.h>
#include "BMPTextureLoader.h"

Example5::Example5()
{
}
void Example5::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	shape = new Cubo("Cuadrado", 1, 255, 2);
	_TextureLoader = new BMPTextureLoader();
	texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./textures/wallBMP.bmp");
}
void Example5::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Example::DrawGrids();
	DrawShape();
	glFlush();
}
void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
	switch (key)
	{
	case 'A':
		pos.x += 0.5;
		break;
	case 'D':
		pos.x -= 0.5;
		break;
	case 'W':
		pos.z += 0.5;
		break;
	case 'S':
		pos.z -= 0.5;
		break;
	case 'Q':
		pos.y += 0.5;
		break;
	case 'E':
		pos.y -= 0.5;
		break;
	default:
		break;
	}
}
void Example5::Idle()
{
}
void Example5::DrawShape()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	((Cubo*)shape)->dibujar();
	glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers(); //Se hace el cambio de buffer
}