#include "Cabana.h"

/*
Party Animals: Cabana (At the Copa~)
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
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
						glTranslatef(0, 40, 0); //Move up by 40
						drawTop(); //Draw the roof of the Cabana
					glPopMatrix();
					for (float i = 0; i < 2; i ++) { //Draw 2 sets of pillars to hold the roof up
						glRotatef(45 * i, 0, 1, 0); //Rotate 45 degrees counter clockwise along the y axis
						for (float j = 0; j < 4; j++) { //Draw 4 pillars
							glPushMatrix();
								glTranslatef((100.f / 3.f) * (j < 2 ? -2.f : 2.f), 0, (100.f / 3.f) * (j == 1 || j == 2 ? -2.f : 2.f)); //Determine where to place the pillar
								drawPillar();
							glPopMatrix();
						}
					}
				glBindTexture(GL_TEXTURE_2D, NULL);
			glDisable(GL_TEXTURE_2D);
		glPopAttrib();
	glPopMatrix();
}

/*
Draws a pillar
*/
void Cabana::drawPillar() {
	glPushMatrix();
		glTranslatef(0, -10, 0); //Move down by 10
		glRotatef(-90, 1, 0, 0); //Rotate 90 degrees clockwise along the x axis
		GLUquadric* pillar = gluNewQuadric();
		gluQuadricNormals(pillar, GLU_SMOOTH);
		gluQuadricTexture(pillar, GL_TRUE);
		gluCylinder(pillar, 1, 1, 50, 20, 20); //Draw the pillar with the Cabana texture
	glPopMatrix();
}

/*
Draws the roof of the Cabana
*/
void Cabana::drawTop() {
	glPushMatrix();
		glRotatef(-90, 1, 0, 0); //Rotate by 90 degrees clockwise along the x axis
		GLUquadric* hutTop = gluNewQuadric();
		gluQuadricNormals(hutTop, GLU_SMOOTH);
		gluQuadricTexture(hutTop, GL_TRUE);
		gluCylinder(hutTop, 100, 0, 20, 20, 20); //Draw the top-down view of the roof
		glCullFace(GL_FRONT);
		gluCylinder(hutTop, 100, 0, 20, 20, 20); //Draw the bootom-up view of the roof
		glCullFace(GL_BACK);
	glPopMatrix();
}