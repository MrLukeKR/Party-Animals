#include "Rock.h"

/*
Party Animals: Rock
Author: Luke K. Rose
April 2018
*/

Rock::Rock(const char* textureFile) : texID(Scene::GetTexture(textureFile)) {
	for(int i = 0; i < 2; i++)
		rotation[i] += (float)rand() / (float) RAND_MAX * 360.f;
	pos[1] -= rockSize / 2;
}

/*
Draws the object
*/
void Rock::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glColor4f(1, 1, 1, 1); //Set the colour to opaque white
		
			glEnable(GL_TEXTURE_2D);
				glEnable(GL_COLOR_MATERIAL);
					glBindTexture(GL_TEXTURE_2D, texID);
						GLUquadric* quadric = gluNewQuadric();
						gluQuadricNormals(quadric, GLU_SMOOTH);
						gluQuadricTexture(quadric, GL_TRUE);
						gluSphere(quadric, rockSize, 4, 4); //Draw a jagged sphere using the Rock texture
					glBindTexture(GL_TEXTURE_2D, NULL);
				glDisable(GL_COLOR_MATERIAL);
			glDisable(GL_TEXTURE_2D);
		glPopAttrib();
	glPopMatrix();
}