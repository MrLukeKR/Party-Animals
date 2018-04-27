#include "Meter.h"
#include "Objects\Box.h"

/*
Party Animals: Meter
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Meter::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);

			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
		
			glDisable(GL_LIGHTING);
				glColor4f(1, 1, 1, 1); //Set the colour to opaque white
				glEnable(GL_TEXTURE_2D);
					glEnable(GL_COLOR_MATERIAL);
						glBindTexture(GL_TEXTURE_2D, meterTex);
							glBegin(GL_QUADS); //Draw a plane and calculate the subsection of the spritesheet to use at this point
								glTexCoord2f(0 + offset[0], 0 + offset[1]);
									glVertex3f(0, 0, 0);
								glTexCoord2f(offset[0]+ 0.24f, 0 + offset[1]);
									glVertex3f(1, 0, 0);
								glTexCoord2f(offset[0] + 0.24f, offset[1] + 0.24f);
									glVertex3f(1, 1, 0);
								glTexCoord2f(0 + offset[0], offset[1] + 0.24f);
									glVertex3f(0, 1, 0);
							glEnd();
						glDisable(GL_COLOR_MATERIAL);
					glBindTexture(GL_TEXTURE_2D, NULL);
				glDisable(GL_TEXTURE_2D);
			glEnable(GL_LIGHTING);
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Meter::Update(const double& deltaTime) {
	if ((time += deltaTime) >= .1f) {
		offset[0] += 0.25f; //Increment the texture coordinate offset by 0.25 (The file has 4 x 4 images and has a total size of 1.0 x 1.0)
		time = 0;
	}

	if (offset[0] >= 1)
	{
		offset[0] = 0;
		offset[1] += 0.25f;
	}

	if (offset[1] >= 1) offset[1] = 0;
}