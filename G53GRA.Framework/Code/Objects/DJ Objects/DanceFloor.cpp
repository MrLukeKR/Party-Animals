#include "DanceFloor.h"



DanceFloor::DanceFloor()
{
}


DanceFloor::~DanceFloor()
{
}

void DanceFloor::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glColor3f(1, 0.871f, 0.678f);

	for (int x = -10; x < 10; x++)
	{
		for (int y = -10; y < 10; y++)
		{
			float red = ((float)rand() / (RAND_MAX)),
				green = ((float)rand() / (RAND_MAX)),
				blue = ((float)rand() / (RAND_MAX));
			glColor3f(red,green,blue);
			glBegin(GL_QUADS);
			glNormal3f(0, 1, 0);
			glTexCoord2d(0, 0);
			glVertex3f(x, -0.1f, y);
			glTexCoord2d(1, 0);
			glVertex3f(x, -0.1f, y + 1);
			glTexCoord2d(1, 1);
			glVertex3f(x + 1, -0.1f, y + 1);
			glTexCoord2d(0, 1);
			glVertex3f(x + 1, -0.1f, y);
			glEnd();
		}
	}

	glPopAttrib();
	glPopMatrix();
}