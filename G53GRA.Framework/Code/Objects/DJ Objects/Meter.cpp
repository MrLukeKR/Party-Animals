#include "Meter.h"
#include "Objects\Box.h"

void Meter::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);

			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
		
			glDisable(GL_LIGHTING);
			glColor4f(1, 1, 1, 1);
	
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_COLOR_MATERIAL);
		
			glBindTexture(GL_TEXTURE_2D, meterTex);
		
			glBegin(GL_QUADS);
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

void Meter::Update(const double& deltaTime) {
	if ((time += deltaTime) >= .1f) {
		offset[0] += 0.25f;
		time = 0;
	}

	if (offset[0] >= 1)
	{
		offset[0] = 0;
		offset[1] += 0.25f;
	}

	if (offset[1] >= 1)
		offset[1] = 0;
}