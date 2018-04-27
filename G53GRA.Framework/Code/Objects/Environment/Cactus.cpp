#include "Cactus.h"
#include "../Box.h"

#define MAX_BRANCHES 3

/*
Party Animals: Cactus
Author: Luke K. Rose
April 2018
*/

/*
Initialise the object by randomly placing the branches of the Cactus
*/
Cactus::Cactus() {
	armRotation = new float[MAX_BRANCHES];
	for (int i = 0; i < MAX_BRANCHES; i++)
		armRotation[i] = ((float)rand() / (float)RAND_MAX * 180.f) - 90.f;
}

/*
Draws the object
*/
void Cactus::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glPushMatrix();
				glTranslatef(0, height / 2.f, 0); //Move up half the height of the Cactus
				Box::box(1, height, 1, cactusTex); //Draw a 1 x height x 1 cube with the Cactus texture
			glPopMatrix();

			for (int i = 0; i < MAX_BRANCHES; i++) { //Draw the branches of the Cactus
				glTranslatef(0, height / MAX_BRANCHES, 0); //MMove up by the height divided by the number of branches
				glPushMatrix();
					glRotatef(armRotation[i], 1, 0, 1); //Rotate around the x and z axes according to the random angle from initialisation
					glTranslatef(0, height / 6.f, 0); //Move up by a sixth of the height  of the Cactus
					Box::box(0.75f,	 height / 3.f, 0.75f, cactusTex); //Draw a 0.75 x Cactus height divided by 3 x 0.75 cube with the Cactus texture
				glPopMatrix();
			}
		glPopAttrib();
	glPopMatrix();
}