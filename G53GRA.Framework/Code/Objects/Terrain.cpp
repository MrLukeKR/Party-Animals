#include "Terrain.h"

Terrain::Terrain()
{
}


Terrain::~Terrain()
{
}

void Terrain::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glColor3f(1, 1, 1);

	glBegin(GL_QUADS);

	glVertex3f(-100,-0.1f,-100);
	glVertex3f(-100, -0.1f,100);
	glVertex3f(100, -0.1f,100);
	glVertex3f(100, -0.1f,-100);

	glEnd();

	glPopAttrib();
	glPopMatrix();
}
