#include "Cactus.h"
#include "../Box.h"

#define MAX_BRANCHES 3

Cactus::Cactus() {
	armRotation = new float[MAX_BRANCHES];
	for (int i = 0; i < MAX_BRANCHES; i++)
		armRotation[i] = ((float)rand() / (float)RAND_MAX * 180.f) - 90.f;
}

void Cactus::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glTranslatef(0, height / 2.f, 0);
		
			Box::box(1, height, 1, cactusTex);
			for (int i = 0; i < MAX_BRANCHES; i++) {
				glTranslatef(0, height / MAX_BRANCHES, 0);
				glPushMatrix();
				glRotatef(armRotation[i], 1, 0, 1);
				glTranslatef(0, height / 2.f / 3.f, 0);
				Box::box(0.75f,	 height / 3.f, 0.75f, cactusTex);
				glPopMatrix();
			}
		glPopAttrib();
	glPopMatrix();
}