#include "Terrain.h"

/*
Party Animals: Terrain
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Terrain::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glColor4f(1, 1, 1, 1);  //Sets the colour to opaque white
			glEnable(GL_TEXTURE_2D);
				glEnable(GL_COLOR_MATERIAL);
					glBindTexture(GL_TEXTURE_2D, sandTex);
						for (float x = -250; x < 250; x++) //Draw a 500 x 500 floor with the Desert texture
							for (float y = -250; y < 250; y++)
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
					glBindTexture(GL_TEXTURE_2D, NULL);
				glDisable(GL_COLOR_MATERIAL);
			glDisable(GL_TEXTURE_2D);
		glPopAttrib();
	glPopMatrix();
}
