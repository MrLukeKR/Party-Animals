#include "Elephant.h"
#include "Objects\Box.h"

Elephant::Elephant()
{
}

Elephant::~Elephant()
{
}

void Elephant::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glColor3f(0.3f, 0.3f, 0.3f);

	drawBody();

	glPushMatrix();
	glTranslatef(-6, -7, 4);
	drawLeg();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(6, -7, 4);
	drawLeg();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(6, -7, -4);
	drawLeg();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-6, -7, -4);
	drawLeg();
	glPopMatrix();
	glTranslatef(9, 5, 0);
	drawHead();
	glPopAttrib();
	glPopMatrix();
}

void Elephant::drawBody() {
	glPushMatrix();
	Box::box(7, 5, 5);
	glPopMatrix();
}

void Elephant::drawLeg() {
	glPushMatrix();
	Box::box(1, 3, 1);
	glPopMatrix();
}

void Elephant::drawEyes() {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(3,1,1.5f);
	Box::box(0.5f, 0.5f, 0.5f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3, 1, -1.5f);
	Box::box(0.5f, 0.5f, 0.5f);
	glPopMatrix();
	glPopMatrix();
}

void Elephant::drawHead() {
	glPushMatrix();
	Box::box(3, 3, 3);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4, 0, 0);
	glPushMatrix();
	drawTusks();
	glPopMatrix();
	glPushMatrix();
	drawTrunk();
	glPopMatrix();
	glPushMatrix();
	drawEyes();
	glPopMatrix();
	glPushMatrix();
	drawEars();
	glPopMatrix();
}

void Elephant::drawTrunk() {
	glColor3f(0.3f, 0.3f, 0.3f);
	glPushMatrix();
	glTranslatef(4.15f, -4.5f, 0);
	glRotatef(-65, 0, 0, 1);
	Box::box(4, 0.75f, 0.75f);
	glPopMatrix();
}

void Elephant::drawTusks() {
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
	glTranslatef(0, -1.5f, 2);
	glRotatef(-45, 0, 0, 1);
	glRotatef(-25, 0, 1, 0);
	Box::box(2, 0.5f, 0.5f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -1.5f, -2);
	glRotatef(-45, 0, 0, 1);
	glRotatef(25, 0, 1, 0);
	Box::box(2, 0.5f, 0.5f);
	glPopMatrix();
	glPopMatrix();
}

void Elephant::drawEars() {
	glColor3f(0.3f, 0.3f, 0.3f);
	glPushMatrix();
	glTranslatef(0,3,3);
	glRotatef(-80,0,1,0);
	Box::box(0.1f, 2, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 3, -3);
	glRotatef(80, 0, 1, 0);
	Box::box(0.1f, 2, 2);
	glPopMatrix();
}

void Elephant::Update(const double& dT) {

} 