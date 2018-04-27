#include "Confetti.h"
#include "../Objects/Box.h"

/*
Party Animals: Confetti
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Confetti::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glColor4f(r, g, b, 1); //Set the colour of the confetto
			Box::box(1, 1, 0.1f); //Draw a 1 x 1 x 0.1 cube
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Confetti::Update(const double& dT) {
	//The following random flutters the confetto and resets its colour and position when leaving the world
	for(int i = 0; i < 3; i++)
		rotation[i] += rand() % 30;
	
	pos[1]-=0.25f;
	if (pos[1] <= -10) {
		for(int i = 0; i < 3; i++)
			pos[i] = dropLoc[i] + ((rand() % 100) - 50);
	
		r = (rand() % 10) / 10.0f;
		g = (rand() % 10) / 10.0f;
		b = (rand() % 10) / 10.0f;
	}
}