#include "Cabana.h"

void Cabana::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, cabanaTex);

			glPushMatrix();
				glTranslatef(0, 40, 0);
				drawTop();
			glPopMatrix();
			for (int i = 0; i < 2; i ++) {
				glRotatef(45 * i, 0, 1, 0);
				for (int j = 0; j < 4; j++) {
					glPushMatrix();
						glTranslatef((100.f / 3.f) * (j < 2 ? -2.f : 2.f), 0, (100.f / 3.f) * (j == 1 || j == 2 ? -2.f : 2.f));
						drawPillar();
					glPopMatrix();
				}
			}
			glBindTexture(GL_TEXTURE_2D, NULL);
			glDisable(GL_TEXTURE_2D);
		glPopAttrib();
	glPopMatrix();
}

void Cabana::drawPillar() {
	glPushMatrix();
		glTranslatef(0, -10, 0);
		glRotatef(-90, 1, 0, 0);
		GLUquadric* pillar = gluNewQuadric();
		gluQuadricNormals(pillar, GLU_SMOOTH);
		gluQuadricTexture(pillar, GL_TRUE);
		gluCylinder(pillar, 1, 1, 50, 20, 20);
	glPopMatrix();
}

void Cabana::drawTop() {
	glPushMatrix();
		glRotatef(-90, 1, 0, 0);
		GLUquadric* hutTop = gluNewQuadric();
		gluQuadricNormals(hutTop, GLU_SMOOTH);
		gluQuadricTexture(hutTop, GL_TRUE);
		gluCylinder(hutTop, 100, 0, 20, 20, 20);
		glCullFace(GL_FRONT);
		gluCylinder(hutTop, 100, 0, 20, 20, 20);
		glCullFace(GL_BACK);
	glPopMatrix();
}