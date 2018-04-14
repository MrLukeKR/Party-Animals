#include "DJDecks.h"
#include "Objects\Box.h"

DJDecks::DJDecks()
{
	deskTex = Scene::GetTexture("./Textures/black-wood.bmp");
}


DJDecks::~DJDecks()
{

}

void DJDecks::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glTranslatef(0, -5, 0);
	drawPodium();
	drawTurntable();
	glPushMatrix();
	glTranslatef(0, 0, -1.75f);
	drawVinyl();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 1.75f);
	drawVinyl();
	glPopMatrix();
	glPopAttrib();
	glPopMatrix();
}

void DJDecks::drawVinyl() {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0, 4.5f, 0);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 1, 0.6f, 0.2f, 10, 10);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, .2f, 0);
	glBegin(GL_TRIANGLE_FAN);
	float r = 0.6f;
	float res = 20 ;
	glVertex3f(0, 0, 0);
	for (int i = res; i >= 0; i--)
		glVertex3f(r * cos(i * 2 * 3.14159265f / res), 0, r * sin(i * 2 * 3.14159265f / res));

	glEnd();

	glPopMatrix();
}

void DJDecks::drawTurntable() {
	glColor3f(0.3f, 0.3f, 0.3f);
	glPushMatrix();
	glTranslatef(0, 4, 0);
	Box::box(2, .5f, 3);
	glPopMatrix();
}

void DJDecks::drawPodium() {
	glPushMatrix();
	Box::box(3,4,7, deskTex);
	glPopMatrix();
}