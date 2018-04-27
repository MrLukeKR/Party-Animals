#include "Snake.h"
#include "Objects\PartyHat.h"
#include "Objects\Box.h"

/*
This is used to calculate the spiral action of the Snake's animation
*/
#define CALC_X cos((x + offset) / 10.0f) 
#define CALC_Y sin((x + offset) / 10.0f)
#define CALC_Z (x / frequency)
#define SCALE .25f


/* 
Party Animals: Snake
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Snake::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glPushMatrix();
				glTranslatef(0, 0, 36.75f); //Move forward by 36.75
				float x = cos(offset / 10.f), //Calculate the angle of the head
					  y = sin(offset / 10.f),
					  angle = atan2(y, x) * 180.f / 3.14159265f - 180;
				glRotatef(angle, 0, 0, 1); //Rotate the head by this value to align it with the body
				drawHead(); //Draw the Snake's head
			glPopMatrix();

			glPushMatrix();
				glEnable(GL_TEXTURE_2D);
					glColor4f(1, 1, 1, 1); //Set the colour to opaque white
					glEnable(GL_COLOR_MATERIAL);
						glBindTexture(GL_TEXTURE_2D, snakeTex);

							for (int x = 0; x < 360; x++) {
								glBegin(GL_QUADS); //Draw the top of the cube
									glTexCoord2d(1, 1);
										glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //RIGHT, TOP, FRONT
									glTexCoord2d(1, 0);
										glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //RIGHT, TOP, BACK
									glTexCoord2d(0, 0);
										glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //LEFT, TOP, BACK
									glTexCoord2d(0, 1);
										glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //LEFT, TOP, FRONT
								glEnd();

		
								glBegin(GL_QUADS);//Draw the bottom of the cube
									glTexCoord2d(1, 1);
										glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //RIGHT, BOTTOM, FRONT
									glTexCoord2d(0, 1);
										glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //LEFT, BOTTOM, FRONT		
									glTexCoord2d(0, 0);
										glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //LEFT, BOTTOM, BACK
									glTexCoord2d(0, 1);
										glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //RIGHT, BOTTOM, BACK
								glEnd();

								glBegin(GL_QUADS); //Draw the right of the cube
									glTexCoord2d(1, 1);
										glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //RIGHT, TOP, BACK
									glTexCoord2d(0, 1);
										glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //RIGHT, TOP, FRONT
									glTexCoord2d(0, 0);
										glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //RIGHT, BOTTOM, FRONT
									glTexCoord2d(1, 0);
										glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //RIGHT, BOTTOM, BACK
								glEnd();

		
								glBegin(GL_QUADS); //Draw the left of the cube
									glTexCoord2d(1, 1);
										glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //LEFT, TOP, FRONT
									glTexCoord2d(0, 1);
										glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //LEFT, TOP, BACK
									glTexCoord2d(0, 0);
										glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //LEFT, BOTTOM, BACK
									glTexCoord2d(1, 0);
										glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //LEFT, BOTTOM, FRONT
								glEnd();

								glBegin(GL_QUADS); //Draw the front of the cube
									glTexCoord2d(1, 1);
										glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //RIGHT, TOP, FRONT
									glTexCoord2d(0, 1);
										glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //LEFT, TOP, FRONT
									glTexCoord2d(0, 0);
										glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //LEFT, BOTTOM, FRONT
									glTexCoord2d(1, 0);
										glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //RIGHT, BOTTOM, FRONT
								glEnd();

		
								glBegin(GL_QUADS); //Draw the back of the cube
									glTexCoord2d(1, 1);
										glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //LEFT, TOP, BACK
									glTexCoord2d(0, 1);
										glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //LEFT, BOTTOM, BACK
									glTexCoord2d(0, 0);
										glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //LEFT, BOTTOM, BACK
									glTexCoord2d(1, 0);
										glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //LEFT, TOP, BACK
								glEnd();
							}
						glDisable(GL_COLOR_MATERIAL);
					glBindTexture(GL_TEXTURE_2D, NULL);
				glDisable(GL_TEXTURE_2D);
			glPopMatrix();
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Snake::Update(const double& dT) { offset++; }

/*
Draw the Snake's eye
*/
void Snake::drawEye() {
		glColor4f(0.f, 0.f, 0.f, 1.f); //Set the colour to opaque black
		Box::box(.2f, .2f, .2f); //Draw a 0.2 x 0.2 x 0.2 cube
}

/*
Draw the Snake's head
*/
void Snake::drawHead() {
	glPushMatrix();
		glTranslatef(0, 0.75f, 0); //Move up by 0.75
		Box::box(0.5f, 0.5f, 0.75f, snakeTex); //Draw a 0.5 x 0.5 x 0.75 cube with the Snake texture
		PartyHat* hat = new PartyHat(); //Create a new party hat
		hat->size(0.5f, 0.5f, 0.5f); //Halve the size of the party hat
		hat->position(0, 0.5, 0); //Move the party hat up by 0.5
		hat->Display(); //Draw the party hat
		for (int i = -1; i <= 1; i += 2) { //Draw 2 eyes that mirror each other
			glPushMatrix();
				glTranslatef(i * 0.6f, 0, 0); //Move left/right by 0.6
				drawEye(); //Draw the Snake's eye
			glPopMatrix();
		}
		glTranslatef(0, 0, abs(sin(offset / 4.f))); //Animate the Snake's tongue
		drawTongue(); //Draw the Snake's tongue
	glPopMatrix();
}

/*
Draws the Snake's tongue
*/
void Snake::drawTongue() {
		glColor4f(1, 0, 0, 1); //Set the colour to opaque red
		Box::box(0.05f, 0.05f, 0.5f); //Draw a 0.05 x 0.05 x 0.5 cube
		for (float i = -1; i <= 1; i += 2) { //Draw the fork of the tongue
			glPushMatrix();
				glTranslatef(i * 0.1f, 0, 0.5f); //Move left/right by 0.1 and forward by 0.5
				glRotatef(i * 30, 0, 1, 0); //Rotate 30 degrees (counter) clockwise along the y axis
				Box::box(0.05f, 0.05f, 0.1f); //Draw a 0.05 x 0.05 x 0.1 cube
			glPopMatrix();
		}
}