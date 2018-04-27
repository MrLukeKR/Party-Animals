#include "Laser.h"
#include "Objects\Box.h"

#define NUMBER_OF_LASERS 10

/*
Party Animals: Laser
Author: Luke K. Rose
April 2018
*/

Laser::Laser() {
	degree = new float[NUMBER_OF_LASERS];

	for (int i = 0; i < NUMBER_OF_LASERS; i++) 
		degree[i] = (float)rand();
}

Laser::~Laser() {
	delete[] degree;
}

/*
Draws the object
*/
void Laser::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
	
			drawUnit(); //Draws the hardware side of the laser unit
			glTranslatef(-2, 0, 0); //Move left by 2
			drawLasers(); //Draws the laser beams
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Laser::Update(const double& dT) {
	static double totalTime = 0;
	totalTime += dT;

	for (int i = 0; i < NUMBER_OF_LASERS; i++)
		degree[i] = degree[i] + ((float)rand() / (float)RAND_MAX); //Rotate the lasers randomly

	switch ((int) (totalTime) % 6) { //Select a colour for the lasers based on the current animation time
	case 0:
		red = 1;
		green = 0;
		blue = 0;
		break;
	case 1:
		red = 0;
		green = 1;
		blue = 0;
		break;
	case 2:
		red = 0;
		green = 1;
		blue = 1;
		break;
	case 3:
		red = 0;
		green = 1;
		blue = 1;
		break;
	case 4:
		red = 1;
		green = 0;
		blue = 1;
		break;
	case 5:
		red = 1;
		green = 1;
		blue = 0;
		break;
	}

}

/*
Draws the hardware part of the laser unit
*/
void Laser::drawUnit() {
		glColor4f(0, 0, 0, 1); //Set colour to opaque black
		Box::box(2, 1, 1); //Draw a 2 x 1 x 1 cube
}

/*
Draws the laser beams
*/
void Laser::drawLasers() {
	glDisable(GL_LIGHTING);
		glPushMatrix();
			for (int i = 0; i < NUMBER_OF_LASERS; i++) {
				glRotatef(degree[i], 45, 45, 0); //Rotate the laser by an animated amont * a factor of 45 along the x and y axes
				glPushMatrix();
					glColor4f(red, green, blue, 0.8f); //Set the colour and make it slightly translucent
					glBegin(GL_LINE_LOOP); //Draw the laser
						glVertex3f(0, 0, 0);
						glVertex3f(0, -100, 0);
					glEnd();
				glPopMatrix();
			}
		glPopMatrix();
	glEnable(GL_LIGHTING);
}