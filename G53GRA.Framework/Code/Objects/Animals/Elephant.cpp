#include "Elephant.h"

#define DEBUG 0

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
	box(7, 5, 5);
	glPopMatrix();
}

void Elephant::drawLeg() {
	glPushMatrix();
	box(1, 3, 1);
	glPopMatrix();
}

void Elephant::drawEyes() {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(3,1,1.5f);
	box(0.5f, 0.5f, 0.5f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3, 1, -1.5f);
	box(0.5f, 0.5f, 0.5f);
	glPopMatrix();
	glPopMatrix();
}

void Elephant::drawHead() {
	glPushMatrix();
	box(3, 3, 3);
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
}

void Elephant::drawTrunk() {
	glColor3f(0.3f, 0.3f, 0.3f);
	glPushMatrix();
	glTranslatef(4.15f, -4.5f, 0);
	glRotatef(-65, 0, 0, 1);
	box(4, 0.75f, 0.75f);
	glPopMatrix();
}

void Elephant::drawTusks() {
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
	glTranslatef(0, -1.5f, 2);
	glRotatef(-45, 0, 0, 1);
	glRotatef(-25, 0, 1, 0);
	box(2, 0.5f, 0.5f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -1.5f, -2);
	glRotatef(-45, 0, 0, 1);
	glRotatef(25, 0, 1, 0);
	box(2, 0.5f, 0.5f);
	glPopMatrix();
	glPopMatrix();
}

void Elephant::drawEars() {
	glPushMatrix();

	glPopMatrix();
}

void Elephant::Update(const double& dT) {

}

void Elephant::box(float x, float y, float z) {
	glScalef(x, y, z);
	//FRONT FACE
	glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2d(1, 1);
	glVertex3f(1, 1, 1); //RIGHT-TOP-FRONT
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, 1); //LEFT-TOP-FRONT
	glTexCoord2d(0, 0);
	glVertex3f(-1, -1, 1); //LEFT-BOTTOM-FRONT
	glTexCoord2d(1, 0);
	glVertex3f(1, -1, 1); //RIGHT-BOTTOM-FRONT
	glEnd();

	//LEFT FACE
	glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, 1); //LEFT-TOP-FRONT
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -1); //LEFT-TOP-BACK
	glTexCoord2d(0, 0);
	glVertex3f(-1, -1, -1); //LEFT-BOTTOM-BACK
	glTexCoord2d(1, 0);
	glVertex3f(-1, -1, 1); //LEFT-BOTTOM-FRONT
	glEnd();

	//BACK FACE
	glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -1); //LEFT-TOP-BACK	
	glTexCoord2d(0, 1);
	glVertex3f(1, 1, -1); //RIGHT-TOP-BACK
	glTexCoord2d(0, 0);
	glVertex3f(1, -1, -1); //RIGHT-BOTTOM-BACK
	glTexCoord2d(1, 0);
	glVertex3f(-1, -1, -1); //LEFT-BOTTOM-BACK
	glEnd();

	//RIGHT FACE
	glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1, 1, -1); //RIGHT-TOP-BACK
	glTexCoord2d(0, 1);
	glVertex3f(1, 1, 1); //RIGHT-TOP-FRONT
	glTexCoord2d(0, 0);
	glVertex3f(1, -1, 1); //RIGHT-BOTTOM-FRONT
	glTexCoord2d(1, 0);
	glVertex3f(1, -1, -1); //RIGHT-BOTTOM-BACK
	glEnd();

	//TOP FACE
	glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1, 1, -1); //RIGHT-TOP-BACK
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -1); //LEFT-TOP-BACK
	glTexCoord2d(0, 0);
	glVertex3f(-1, 1, 1); //LEFT-TOP-FRONT
	glTexCoord2d(1, 0);
	glVertex3f(1, 1, 1); //RIGHT-TOP-FRONT
	glEnd();

	//BOTTOM FACE
	glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1, -1, 1); //RIGHT-BOTTOM-FRONT
	glTexCoord2d(0, 1);
	glVertex3f(-1, -1, 1); //LEFT-BOTTOM-FRONT
	glTexCoord2d(0, 0);
	glVertex3f(-1, -1, -1); //LEFT-BOTTOM-BACK
	glTexCoord2d(1, 0);
	glVertex3f(1, -1, -1); //RIGHT-BOTTOM-BACK
	glEnd();
}