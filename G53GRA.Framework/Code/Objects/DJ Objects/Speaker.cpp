#include "Speaker.h"
#include "Objects\Box.h"

/*
Party Animals: Speaker
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Speaker::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			drawSpeaker(); //Draw the speaker
			glTranslatef(0, -3, 0); //Move down by 3
			drawStand(); //Draw the speaker's stand
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Speaker::Update(const double& time) {
	currentAnimationTime = (float)fmod(currentAnimationTime + time, animationTime);

	float animationStage = 6.f * currentAnimationTime / animationTime;

	speakerPump = 1 + animationStage * 0.05f; //Set the speaker "pump" the speaker to give the illusion of bass
}

/*
Draws the main speaker unit
*/
void Speaker::drawSpeaker() {
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			glEnable(GL_COLOR_MATERIAL);
				glBindTexture(GL_TEXTURE_2D, texID);
					glScalef(speakerPump, speakerPump, speakerPump); //Pump the speakers!
					Box::box(1.5f, 3, 1.5f, texID); //Draw a 1.5 x 3 x 1.5 cube with the Speaker texture
				glBindTexture(GL_TEXTURE_2D, NULL);
			glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

/*
Draws a stand for the speaker to go on
*/
void Speaker::drawStand() {
	glDisable(GL_LIGHTING);
		glColor4f(0.2f, 0.2f, 0.2f, 1); //Set the colour to opaque dark grey
		glPushMatrix();
			glRotatef(90, 1, 0, 0); //Rotate by 90 degrees counter clockwise along the x axis
			gluCylinder(gluNewQuadric(), .25f, .25f, 3.5f, 5, 5); //Draw a pole
		glPopMatrix();
		glTranslatef(0, -3, 0); //Move down by 3
		for (int i = 0; i < 3; i++) { //Draw the feet of the stand
			glRotatef(120, 0, 1, 0); //Rotate 120 degrees counter clockwise along the y axis
			glPushMatrix();
				glRotatef(45, 1, 0, 0); //Rotate 45 degrees counter clockwise along the x axis
				gluCylinder(gluNewQuadric(), .25f, .25f, 5, 5, 5); //Draw a foot pole
			glPopMatrix();
		}
	glEnable(GL_LIGHTING);
}