#include "PartyHat.h"

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
			glColor4f(1, 1, 1, 1);
			GLUquadric* hat = gluNewQuadric();
			gluQuadricNormals(hat, GLU_SMOOTH);
			gluQuadricTexture(hat, GL_TRUE);
			glRotatef(-90, 1, 0, 0);
			gluCylinder(hat, 0.5f, 0, 2, 20, 20);
			glCullFace(GL_FRONT);
			gluCylinder(hat, 0.5f, 0, 2, 20, 20);
			glCullFace(GL_BACK);
			glBindTexture(GL_TEXTURE_2D, NULL);
			glDisable(GL_COLOR_MATERIAL);
			glDisable(GL_TEXTURE_2D);

		glPopAttrib();
	glPopMatrix();
}