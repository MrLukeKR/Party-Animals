#include "Lion.h"
#include "../Box.h"
#include "Objects\PartyHat.h"

/* 
Party Animals: Lion
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Lion::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
			
			glTranslatef(moonwalkX, 0, 0); //Move the Lion left/right based on the animated moonwalk amount
			glRotatef(moonwalkRotation, 0,1, 0); //Rotate the Lion along the y axis by the animated moonwalk rotation
			drawBody(); //Draw the main body of the Lion
			glPushMatrix();
				glTranslatef(-5, 0, 0); //Move left by 5
				glRotatef(wiggle, 1, 0, 0); //"Wiggle" the tail by rotating along the x axis by the wiggle amount
				drawTail(); //Draw the Lion's tail
			glPopMatrix();
			for(int i = -1; i <= 1; i+=2)
				for (int j = -1; j <= 1; j += 2) { //Draws 4 moonwalking legs
					glPushMatrix();
						glTranslatef(i * 4.5f + (i * j * legAngle / 30.f), -2.5f, j); //Move left/right by 4.5 + the leg angle divided by 30, down by 2.5 and forward/backward by 1
						glRotatef(i * j * legAngle, 0, 0, 1); //Rotate the leg around the z axis
						drawLeg(); //Draw the Lion's leg
					glPopMatrix();
				}				
				glTranslatef(5, 1, 0); //Move right by 5 and up by 1
				drawHead();
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Lion::Update(double const& dT) {
	legAngle += reverseLeg ? -4 : 4; //Increment/Decrement the angle of the leg by 4
	if (legAngle >= 30) //Reverse the leg animation if it exceeds the bounds
		reverseLeg = true;
	else if (legAngle <= -30)
		reverseLeg = false;

	wiggle += reverseWiggle ? -3 : 3; //Increment/Decrement the wiggle angle by 3
	if (wiggle >= 15) //Reverse the wiggle animation if it exceeds the bounds
		reverseWiggle = true;
	else if (wiggle <= -15)
		reverseWiggle = false;

	if (!enableSpin) { //If not spinning...
		moonwalkX += reverseMoonWalk ? .5f : -.5f; //Increase/Decrease the moonwalking position
		if (moonwalkX <= -MOONWALK_RANGE) //Reverse the moonwalk if it exceeds the bounds
			reverseMoonWalk = true;
		else if (moonwalkX >= MOONWALK_RANGE) 
			reverseMoonWalk = false;
		enableSpin = moonwalkX <= -MOONWALK_RANGE || moonwalkX >= MOONWALK_RANGE; //Start spinning
	}
	else {
		moonwalkRotation += 30; //Increment the rotation of the moonwalk spin by 30 degrees
		if (moonwalkRotation >= 360 + ((moonwalkX >= 0) ? 360 : 180)) { //Spin a full circle depending on where the Lion is facing
			enableSpin = false; //Stop spinning
			if (moonwalkX < 0) //Face the Lion in the right direction
				moonwalkRotation = 180; 
			else
				moonwalkRotation = 0;
		}
	}
}

/*
Draws the main body of the Lion
*/
void Lion::drawBody() {
	Box::box(5, 1.25f, 1.5f, lionTex); //Draw a 5 x 1.25 x 1.5 cube with the Lion texture
}


/*
Draw the Lion's leg
*/
void Lion::drawLeg() {
	glColor4f(1, 1, 1, 1); //Set the colour to opaque white
	Box::box(.5f, 1.75f, .5f, lionTex); //Draw a 0.5 x 1.75 x 0.5 cube with the Lion texture
}

/*
Draw the Lion's head
*/
void Lion::drawHead() {
	glPushMatrix();
		glColor4f(0.4f, 0, 0, 1); //Set the colour to opaque light red
		Box::box(2, 2, 2, lionTex); //Draw a  2 x 2 x 2 cube with the Lion texture
		glTranslatef(1, 0, 0); //Move right by 1
		glColor4f(1, 1, 1, 1); //Set the colour to opaque white
		Box::box(1.25f, 1.25f, 1.25f, lionTex); //Draw a 1.25 x 1.25 x 1.25 cube with the Lion texture
	glPopMatrix();
	PartyHat* hat = new PartyHat(); //Create a new party hat
	hat->position(0, 2, 0); //Move the party hat up by 2
	hat->Display(); //Draw the party hat
	glPushMatrix();
		for (int i = -1; i <= 1; i += 2) { //Draw 2 eyes that mirror each other
			glPushMatrix();
				glTranslatef(2.25f,0.25f,i * 0.5f); //Move right by 2.25, up by 0.25 and forward/backward by 0.5
				drawEye(); //Draw the Lion's eye
			glPopMatrix();
		}
	glPopMatrix();
	for (float i = -1; i <= 1; i += 2) { //Draws 2 ears that mirror each other
		glPushMatrix();
			glTranslatef(0.75f, 1.f, i * 2.f); //Moves right by 0.75, up by 1 and forward/backward by 2
			glRotatef((-35.f + wiggle) * i, 1.f, 0.f, 0.f); //Rotates the ears by a "wiggle" angle along the x axis
			drawEar(); //Draws the Lion's ear
		glPopMatrix();
	}
	glTranslatef(2.25f, -0.75f, 0); //Moves right by 2.25 and down by 0.75
	drawMouth(); //Draws the Lion's mouths
}

/*
Draw the Lion's tail
*/
void Lion::drawTail() {
	glPushMatrix();
		glRotatef(-10, 0, 0, 1); //Rotate 10 degrees clockwise along the z axis
		glTranslatef(0, -0.5f, 0); //Move down by 0.5
		Box::box(.1f, 1, .1f, lionTex); //Draw  a 0.1 x 1 x 0.1 cube with the Lion texture
		glTranslatef(0, -1.25f, 0); //Move down by 1.25
		glColor4f(.8f, 0, 0, 1); //Set the colour to opaque red
		Box::box(.25f, .25f, .25f, lionTex); //Draw a 0.25 x 0.25 x 0.25 cube with the Lion texture
	glPopMatrix();
}

/*
Draws the Lion's ear
*/
void Lion::drawEar() {
	glColor4f(1, 1, 1, 1); //Set the colour to opaque white
	Box::box(0.25f,.5f,.5f,lionTex); //Draw a 0.25 x 0.5 x 0.5 cube with the Lion texture
	glTranslatef(0.25f, 0, 0); //Move right by 0.25
	glColor4f(.8f, 0, 0, 1); //Set the colour to opaque red
	Box::box(0.15f, 0.4f, 0.4f, lionTex); //Draw a 0.15 x 0.4 x 0.4 cube with the Lion texture
}

/*
Draw the Lion's eye
*/
void Lion::drawEye() {
	glColor4f(0, 0, 0, 1); //Set the colour to opqaue black
	Box::box(0.2f, 0.2f, 0.2f); //Draw a 0.2 x 0.2 x 0.2 cube
}

/*
Draw the Lion's mouth
*/
void Lion::drawMouth() {
	glColor4f(0, 0, 0, 1); //Set the colour to opaque black
	Box::box(0.1f, 0.25f, 0.4f); //Draw a 0.1 x 0.25 x 0.4 cube
	for (int i = -1; i <= 1; i += 2) { //Draw 2 teeth that mirror each other
		glPushMatrix();
			glTranslatef(0.11f, 0, i * 0.25f); //Move right by 0.11 and forward/backward by 0.25
			glDisable(GL_LIGHTING);
				glColor4f(1, 1, 1, 1); //Set the colour to opaque white
				glBegin(GL_TRIANGLES); //Draw the teeth
					glVertex3f(0,0.25f,.1f);
					glVertex3f(0, -.25f, 0);
					glVertex3f(0, 0.25f, -.1f);
				glEnd();
			glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glTranslatef(0.05f, -.1f, 0); //Move right by 0.05 and down by 0.1
	glColor4f(1, 0, 0, 1); //Set the colour to opaque red
	Box::box(0.1f, 0.1f, 0.1f); //Draw a 0.1 x 0.1 x 0.1 cube
}