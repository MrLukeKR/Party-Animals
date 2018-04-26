#include "Scaffolding.h"

Scaffolding::Scaffolding()
{
}

Scaffolding::~Scaffolding()
{
}

void Scaffolding::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glColor4f(0.8f, 0.8f, 0.8f, 1);

	drawScaffolding();

	glPopAttrib();
	glPopMatrix();
}

void Scaffolding::drawScaffolding() {
	drawHalf();
	glRotatef(180, 0, 1, 0);
	drawHalf();
}

void Scaffolding::drawHalf() {
	glPushMatrix();
	gluCylinder(gluNewQuadric(), .5f, 0.5f, 35, 5, 5);
	glPushMatrix();
	glTranslatef(0, -3, 0);
	gluCylinder(gluNewQuadric(), .5f, 0.5f, 35, 5, 5);
	glPopMatrix();
	glTranslatef(0, 0, 35);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);

	gluCylinder(gluNewQuadric(), .5f, .5f, 20, 5, 5);
	glPopMatrix();
	glTranslatef(0, -20, 0);
	glPushMatrix();
	glRotatef(45, 1, 0, 0);
	gluCylinder(gluNewQuadric(), .5f, .5f, 5, 5, 5);
	glPopMatrix();
	glPushMatrix();
	glRotatef(120, 0, 1, 0);
	glRotatef(45, 1, 0, 0);
	gluCylinder(gluNewQuadric(), .5f, .5f, 5, 5, 5);
	glPopMatrix();
	glPushMatrix();
	glRotatef(-120, 0, 1, 0);
	glRotatef(45, 1, 0, 0);
	gluCylinder(gluNewQuadric(), .5f, .5f, 5, 5, 5);
	glPopMatrix();
	glPopMatrix();
}