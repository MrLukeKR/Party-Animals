#include "DJDecks.h"
#include "Objects\Box.h"

/*
Party Animals: DJ Decks
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void DJDecks::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);

			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glTranslatef(0, -5, 0); //Move down by 5
			drawPodium(); //Draw the DJ podium
			glPushMatrix();
				glTranslatef(0, 4, 0);
				drawTurntable(); //Draw the vinyl turntable
			glPopMatrix();
			for (int i = -1; i <= 1; i += 2) {
				glPushMatrix();
					glTranslatef(0, 0, i * 1.75f); //Move backward/forward by 1.75
					drawVinyl(); //Draw a vinyl record
				glPopMatrix();
			}
		glPopAttrib();
	glPopMatrix();
}

/*
Draw a vinyl music record
*/
void DJDecks::drawVinyl() {
	glColor4f(0, 0, 0, 1); //Set the colour to opaque black
	glPushMatrix();
		glTranslatef(0, 4.5f, 0); //Move up by 4.5
		glRotatef(-90, 1, 0, 0); //Rotate 90 degrees clockwise along the x axis
		gluCylinder(gluNewQuadric(), 1, 0.6f, 0.05f, 10, 10); //Draw the vinyl plate
		glTranslatef(0.05f, 0, 0.05f); //Move right by 0.05 and forward by 0.05
		glDisable(GL_LIGHTING);
			gluDisk(gluNewQuadric(), 0.1f, 1.5f, 10, 10); //Draw the vinyl record
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

/*
Draws the DJ's turntable
*/
void DJDecks::drawTurntable() {
	glColor4f(0.3f, 0.3f, 0.3f, 1.f); //Set the colour to opaque dark grey
	Box::box(2, .5f, 3); //Draw a 2 x 0.5 x 3 cube
}

/*
Draws the DJ's podium/desk
*/
void DJDecks::drawPodium() {
	Box::box(3,4,7, deskTex); //Draw a 3 x 4 x 7 cube with the wooden desk texture
}