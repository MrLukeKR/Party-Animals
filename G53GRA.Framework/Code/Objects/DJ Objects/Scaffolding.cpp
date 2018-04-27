#include "Scaffolding.h"

/*
Party Animals: Scaffolding
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Scaffolding::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
		
			drawScaffolding(); //Draw the scaffolding to hold the DJ equipment

		glPopAttrib();
	glPopMatrix();
}

/*
Draws the scaffolding to hold the DJ equipment
*/
void Scaffolding::drawScaffolding() {
	glColor4f(0.3f, 0.3f, 0.3f, 1); //Set the colour to opaque dark grey
	drawHalf(); //Draw half of the scaffolding
	glRotatef(180, 0, 1, 0); //Flip around
	drawHalf(); //Draw the other half of the scaffolding
}

/*
Draws half of the scaffolding for assured mirrored modelling
*/
void Scaffolding::drawHalf() {
	glPushMatrix();
		gluCylinder(gluNewQuadric(), .5f, 0.5f, 35, 5, 5); //Draw a pole
		glPushMatrix();
			glTranslatef(0, -3, 0); //Move down by 3
			gluCylinder(gluNewQuadric(), .5f, 0.5f, 35, 5, 5); //Draw another pole
		glPopMatrix();
		glTranslatef(0, 0, 35); //Move forward by 35
		glPushMatrix();
			glRotatef(90, 1, 0, 0); //Rotate 90 degrees counter clockwise along the x axis
			gluCylinder(gluNewQuadric(), .5f, .5f, 20, 5, 5); //Draw another pole
		glPopMatrix();
		glTranslatef(0, -20, 0); //Move down by 20
		for (int i = 0; i < 3; i++) { //Draws the feet of the scaffolding
			glRotatef(120, 0, 1, 0);  //Rotate 120 degrees counter clockwise around the y axis
			glPushMatrix();
				glRotatef(45, 1, 0, 0); //Rotate 45 degrees around the x axis
				gluCylinder(gluNewQuadric(), .5f, .5f, 5, 5, 5); //Draw another pole
			glPopMatrix();
		}
	glPopMatrix();
}