#include "Terrain.h"

Terrain::Terrain()
{
	sandTex = Scene::GetTexture("./Textures/sand.bmp");;
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

	glColor3f(1, 0.871f, 0.678f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	//glDisable(GL_LIGHTING);

	glBindTexture(GL_TEXTURE_2D, sandTex);
	
	for (int x = -250; x < 250; x++)
	{
		for (int y = -250; y < 250; y++)
		{
			glBegin(GL_QUADS);
			glNormal3f(0,1,0);
			glTexCoord2d(0,0);
			glVertex3f(x, -0.1f, y);
			glTexCoord2d(1, 0);
			glVertex3f(x, -0.1f, y+1);
			glTexCoord2d(1, 1);
			glVertex3f(x+1, -0.1f, y+1);
			glTexCoord2d(0, 1);
			glVertex3f(x+1, -0.1f, y);
			glEnd();
		}
	}

	glDisable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopMatrix();
}
