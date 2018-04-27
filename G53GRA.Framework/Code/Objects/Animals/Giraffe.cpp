#include "Giraffe.h"
#include "Objects\Box.h"
#include "Objects\PartyHat.h"

/* 
Party Animals: Giraffe
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Giraffe::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glScalef(5, 5, 5); //Set the size of all objects to 5x their programmed size
			drawGiraffe(); //Draws the Giraffe object
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Giraffe::Update(const double& dT) {
	offset += reverseOffset ? -1 : 1; //Increment/Decrement the animation offset by 1

	if (offset >= 15) //Reverse the animation if it exceeds the bounds
		reverseOffset = true;
	else if (offset <= -15)
		reverseOffset = false;

	neckAngle = -15.f + abs(offset); //Update the angle of the neck of the giraffe
	headAngle = -90.f + abs(offset); //Update the angle of the head of the giraffe
}

/*
Draws the Giraffe object
*/
void Giraffe::drawGiraffe() {
	drawBody(); //Draws the main body of the Giraffe
	glPushMatrix();
		glTranslatef(-1.15f, -0.25f, .0f); //Move left by 1.15 and down by 0.25
		drawTail(); //Draws the Giraffe's tail
	glPopMatrix();
	for (int i = -1; i <= 1; i += 2)
		for (int j = -1; j <= 1; j += 2) { //Draws 4 legs in each corner of the Giraffe's body
			glPushMatrix();
				glTranslatef(i * 0.9f, -1, j * .4f); //Move left/right by 0.9, down by 1 and forward/backward by 0.4
				drawLeg(); //Draws the Giraffe's leg
			glPopMatrix();
		}
	glPushMatrix();
		glRotatef(neckAngle, 0, 0, 1); //Rotate the Giraffe's neck by the animated angle along the z axis
		glRotatef(offset, 1, 0, 0); //Rotate the Giraffe's neck by the animated offset along the x axis 
		glTranslatef(.65f, 2.225f, 0.f); //Move right by 0.65 and up by 2.22
		drawNeck(); //Draw the Giraffe's neck
		glTranslatef(.25f, neckHeight, 0.f); //Move right by 0.25 and up by the height of the Giraffe's neck
		drawHead(); //Draw the Giraffe's head
	glPopMatrix();
}

/*
Draws the Giraffe's tail
*/
void Giraffe::drawTail() {
	glPushMatrix();
		glRotatef(-10, 0, 0, 1); //Rotate by 10 degrees clockwise along the z axis
		glColor4f(1, 1, 1, 1); //Set the colour to opaque white
		Box::box(0.05f, 0.5f, 0.05f, giraffeTex); //Draw a 0.05 x 0.5 x 0.05 cube with the Giraffe texture
	glPopMatrix();
}

/*
Draws the Giraffe's eyes
*/
void Giraffe::drawEyes() {
	glColor4f(0, 0, 0, 1); //Set the colour to opaque black
	for (int i = -1; i <= 1; i += 2) { //Draws 2 eyes that mirror each other
		glPushMatrix();
			glTranslatef(0, 0, i * 0.35f); //Move forward/backward by 0.35
			Box::box(0.1f, 0.1f, 0.1f); //Draw a 0.1 x 0.1 x 0.1 cube
		glPopMatrix();
	}
}

/*
Draws the Giraffe's ears
*/
void Giraffe::drawEars() {
	glColor4f(1, 1, 1, 1); //Set the colour to opaque white
	for (int i = -1; i <= 1; i += 2) { //Draws 2 ears that mirror each other
		glPushMatrix();
			glTranslatef(-0.5f, -0.25f, i * 0.15f); //Move left by 0.5, down by 0.25 and backward/forward by 0.15
			Box::box(0.2f, 0.1f, 0.1f, giraffeTex); //Draw a 0.2 x 0.1 x 0.1 cube with the Giraffe texture
		glPopMatrix();
	}
}

/*
Draws the Giraffe's tongue
*/
void Giraffe::drawTongue() {
	glColor4f(1, 0, 0, 1); //Set the colour to opaque red
	glPushMatrix();
		glTranslatef(0.25f, 0.5f, 0); //Move right by 0.25  and up by 0.5
		Box::box(0.1f, .05f, 0.1f); //Draw a 0.1 x 0.05 x 0.1 cube
	glPopMatrix();
}

/*
Draws the Giraffe's head
*/
void Giraffe::drawHead() {
	glPushMatrix();
		glTranslatef(0.f, 0.3f, 0.f); //Move up by 0.3
		glPushMatrix();
			PartyHat* hat = new PartyHat(); //Create a party hat
			hat->size(0.5f, 0.5f, 0.5f); //Halve the size of the party hat
			hat->Display(); //Draw the party hat
		glPopMatrix();
		glRotatef(headAngle, 0, 0, 1.f); //Rotate the Giraffe's head along the z axis by the animated head angle
		Box::box(0.3f, 0.5f, 0.3f, giraffeTex); //Draw a 0.3 x 0.5 x 0.3 cube with the Giraffe texture
		drawEyes(); //Draw the Giraffe's eyes
		drawTongue(); //Draw the Giraffe's tongue
		drawEars(); //Draw the Giraffe's ears
	glPopMatrix();
}

/*
Draws the main body of the Giraffe
*/
void Giraffe::drawBody() {
	glColor4f(1.f, 1.f, 1.f, 1.f); //Set the colour to opaque white
	Box::box(1.11f, .5f, .65f, giraffeTex); //Draw a 1.11 x 0.5 x 0.65 cube with the Giraffe texture
}

/*
Draws the neck of the Giraffe
*/
void Giraffe::drawNeck() {
	glColor4f(1.f, 1.f, 1.f, 1.f); //Set the colour to opaque white
	Box::box(0.2f, neckHeight, 0.2f, giraffeTex); //Draw a 0.2 x Heigh of the Giraffe's neck x 0.2 cube with the Giraffe Textuer
}

/*
Draws the Giraffe's leg
*/
void Giraffe::drawLeg() {
	glColor4f(1.f, 1.f, 1.f, 1.f); //Set the colour to opaque white
	Box::box(0.2f, 1, 0.2f, giraffeTex); //Draw a 0.2 x 1 x 0.2 cube with the Giraffe texture
}