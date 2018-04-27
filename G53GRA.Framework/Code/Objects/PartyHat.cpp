#include "PartyHat.h"

/*
Party Animals: Party Hat
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void PartyHat::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glEnable(GL_TEXTURE_2D);
				glEnable(GL_COLOR_MATERIAL);
					glBindTexture(GL_TEXTURE_2D, partyHatTex);
						glColor4f(1, 1, 1, 1); //Set the colour to opaque white
						GLUquadric* hat = gluNewQuadric();
						gluQuadricNormals(hat, GLU_SMOOTH);
						gluQuadricTexture(hat, GL_TRUE);
						glRotatef(-90, 1, 0, 0); //Rotate 90 degrees clockwise along the x axis
						gluCylinder(hat, 0.5f, 0, 2, 20, 20); //Draw the outside of the cone (with texture)
						glCullFace(GL_FRONT);
						gluCylinder(hat, 0.5f, 0, 2, 20, 20); //Draw the inside of the cone (with texture)
						glCullFace(GL_BACK);
					glBindTexture(GL_TEXTURE_2D, NULL);
				glDisable(GL_COLOR_MATERIAL);
			glDisable(GL_TEXTURE_2D);
		glPopAttrib();
	glPopMatrix();
}