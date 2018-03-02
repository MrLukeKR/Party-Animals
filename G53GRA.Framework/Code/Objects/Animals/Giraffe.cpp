#include "Giraffe.h"



Giraffe::Giraffe()
{
}


Giraffe::~Giraffe()
{
}

void Giraffe::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	drawBody();
	glPushMatrix();
		glTranslatef(0.4f, 0,.9f);
		drawLeg();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.4f, 0, .9f);
		drawLeg();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.4f, 0, -.9f);
		drawLeg();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.4f, 0, -.9f);
		drawLeg();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,0,.75f);
		glRotatef(neckAngle, 0.f, 1, 0.f);
		drawNeck();
		glPushMatrix();
		glRotatef(headAngle, 0, 1, 0.f);
			drawHead();
		glPopMatrix();
	glPopMatrix();
	glPopAttrib();
	glPopMatrix();
}

void Giraffe::drawHead() {
	glTranslatef(0.2f, neckHeight / 2 + headHeight / 2, 0);
	box(1, headHeight, 0.5f);

}

void Giraffe::drawBody() {
	//Giraffe's Main Body

	glColor3f(1.f, 1.f, 0.f);
	box(1, 1, 2);
}

void Giraffe::drawNeck() {
	glTranslatef(0.f, 1.5f, 0.f);
	glColor3f(1.f, 1.f, 0.f);
	box(0.5f, neckHeight, 0.5f);
}

void Giraffe::drawLeg() {
	glTranslatef(0.f, -1.f, 0.f);
	glColor3f(1.f, 1.f, 0.f);
	box(0.2f, 1, 0.2f);
}

void Giraffe::box(float sx, float sy, float sz)
{
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	glutSolidCube(1.f);
	glPopMatrix();
}