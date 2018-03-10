#include "Elephant.h"

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

void Elephant::Update(const double& dT) {

}

void Elephant::box(float x, float y, float z) {
	glScalef(x, y, z);
	//FRONT FACE
	glBegin(GL_QUADS);
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
	glBegin(GL_QUADS);
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
	glBegin(GL_QUADS);
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
	glBegin(GL_QUADS);
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
	glBegin(GL_QUADS);
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
	glBegin(GL_QUADS);
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