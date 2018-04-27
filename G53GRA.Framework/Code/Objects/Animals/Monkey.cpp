#include "Monkey.h"
#include "Objects\Box.h"
#include "Objects\PartyHat.h"

/* 
Party Animals: Monkey
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Monkey::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			drawBody(); //Draws the main body of the Monkey
			glPushMatrix();
				glTranslatef(0, 3, headShift); //Move up by 3 and left/right by the animated shift amount
				drawHead(); //Draws the head of the Monkey
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0, 1.5f, 2); //Move up by 1.5 and right by 2
				drawLeftArm(); //Draw the Monkey's left arm (Left and Right arms are unique with the Monkey, so can't use the usual -1/+1 trick)
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-1, 0, -1.5f); //Move left by 1 and backward by 1.5
				drawRightArm(); //Draw the Monkey's right arm
			glPopMatrix();
			glPushMatrix();
				glTranslatef(2, -1, 0); //Move right by 2 and down by 1
				drawTail(); //Draw the Monkey's tail
			glPopMatrix();
			glTranslatef(0, -2, 0); //Move down by 2
			drawStool(); //Draw a bar stool
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Monkey::Update(const double& dT) {
	if (reverseShift) //Increment/Decrement the shift of the Monkey's head
		headShift -= 0.4f; //Return the Monkey's head to its original position with more force than the other way
	else 
		headShift += 0.2f;

	if (headShift >= 1) //Reverse the head shift animation if it exceeds the bounds
		reverseShift = true;
	else if (headShift <= -1)
		reverseShift = false;

	offset += reverseOffset ? -2.5f : 2.5f; //Increment/Decrement the animation offset by 2.5

	if (offset >= 0) //Reverse the animation offset if it exceeds the bounds
		reverseOffset = true;
	else if (offset <= -20)
		reverseOffset = false;

	elbowRotation = offset; //Set the elbow's rotation to the animation offset
	shoulderRotation = -80 + offset; //Calculate the shoulder's rotation based on the animation offset
}

/*
Draws the Monkey's head
*/
void Monkey::drawHead() {
	glPushMatrix();
		glColor4f(0.545f, 0.271f, 0.075f, 1.f); //Set the colour to an opaque light brown
		Box::box(2, 2, 2); //Draw a 2 x 2 x 2 cube
		glTranslatef(-2, 0, 0); //Move left by 2
		glColor4f(0.961f, 0.871f, 0.702f, 1.f); //Set the colour to an opaque light beige
		Box::box(.2f, 1.5f, 1.5f); //Draw a 0.2 x 1.5 x 1.5 cube
	glPopMatrix();
	for (float i = -1; i <= 1; i += 2) { //Draw 2 ears and 2 eyes
		glPushMatrix();
			glTranslatef(0, 1, i * 2.5f); //Move up by 1 and forward/backward by 2.5
			drawEar(); //Draw the Monkey's ear
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2.f, 0.5f, i * 1.f); //Move left by 2, up by 0.5 and forward/backward by 1
			drawEye(); //Draw the Monkey's eye
		glPopMatrix();
	}
	glPushMatrix();
		glTranslatef(-2.15f, -1, 0); //Move left by 2.15 and down by 1
		drawMouth(); //Draw the Monkey's mouth
	glPopMatrix();
	PartyHat* hat = new PartyHat(); //Create a new party hat
	hat->position(0, 2, 0); //Move the party hat up by 2
	hat->Display(); //Draw the party hat
	glTranslatef(-2, 0.5f, 0); //Move left by 2 and up by 0.5
	drawSunglasses(); //Draw some sunglasses on the Monkey
}

/*
Draw the Monkey's tail
*/
void Monkey::drawTail() {
	glPushMatrix();
		glRotatef(30,0,0,1); //Rotate 39 degrees counter clockwise along the z axis
		glRotatef(headShift * 4, 0, 1, 0); //Rotate along the y axis using an existing animation variable multiplied by 4 to wiggle the tail
		Box::box(2, 0.1f, 0.1f); //Draw a 2 x 0.1 x 0.1 cube
	glPopMatrix();
}

/*
Draw the Monkey's mouth
*/
void Monkey::drawMouth() {
	glColor4f(0, 0, 0, 1); //Set the colour to opaque black
	Box::box(.1f, .3f, .525f); //Draw a 0.1 x 0.3 x 0.525 cube
	for (int i = -1; i <= 1; i += 2) { //Draw 2 sets of teeth
		glPushMatrix();
			glTranslatef(-0.01f, i * 0.25f, 0); //Move left by 0.01 and up/down by 0.25
			glColor4f(1, 1, 1, 1); //Set the colour to opaque white
			Box::box(.1f, .1f, .5f); //Draw a 0.1 x 0.1 x 0.5 cube
		glPopMatrix();
	}
	glColor4f(1, 0, 0, 1); //Set the colour to opaque red
	glTranslatef(-0.1f, -0.1f, 0); //Move left by 0.1 and down by 0.1
	Box::box(.1f, .05f, .15f); //Draw a 0.1 x 0.05 x 0.15 cube
}

/*
Draw the Monkey's ear
*/
void Monkey::drawEar() {
	glPushMatrix();
		glColor3f(0.545f, 0.271f, 0.075f); //Set the colour to an opaque light brown
		Box::box(0.1f, 2, 2); //Draw a 0.1 x 2 x 2 cube
		glColor3f(0.961f, 0.871f, 0.702f); //Set the colour to an opaque light beige
		glTranslatef(-1,0,0); //Move left by 1
		Box::box(0.1f, 1, 1); //Draw a 0.1 x 1 x1 cube
	glPopMatrix();
}

/*
Draw a bar stool for the Monkey to sit on
*/
void Monkey::drawStool() {
	glDisable(GL_LIGHTING);
		glColor4f(0, 0, 1, 1); //Set the colour to opaque blue
		glPushMatrix();
			glRotatef(90, 1, 0, 0); //Rotate 90 degrees counter clockwise along the x axis
			GLUquadric* quad = gluNewQuadric(); 
			gluCylinder(quad, 2, 2, 0.2f, 10, 10); //Draw the outside of the seat
			glTranslatef(0, -0.1f, 0); //Move down by 0.1
			for (float i = -1; i <= 1; i += 2) { //Draw the top and bottom of the seat
				glPushMatrix();
					glRotatef(i * 180, 1, 0, 0); //Flip the circle
					glTranslatef(0, i * 0.1f, 0); //Move up/down by 0.1
					gluDisk(quad, 0, 2, 10, 10); //Draw a circle
				glPopMatrix();
			}
			glTranslatef(0, -0.1f, 0); //Move down by 0.1
			glRotatef(-90, 1, 0, 0); //Rotate 90 degrees clockwise along the x axis
			glRotatef(-30, 0, 1, 0); //Rotate 39 degrees clockwise along the y axis
			for (float i = 0; i < 3; i++) { //Draw 3 chair legs
				glRotatef(120, 0, 1, 0); //Rotate 120 degrees along the y axis
				glPushMatrix();
					glRotatef(70, 1, 0, 0); //Rotate 70 degrees along the x axis
					gluCylinder(quad, 0.3f, 0.25f, 8, 5, 5); //Draw a chair leg
				glPopMatrix();
			}
		glPopMatrix();
	glEnable(GL_LIGHTING);
}

/*
Draw the main body of the Monkey
*/
void Monkey::drawBody() {
	glPushMatrix();
		glColor3f(0.545f, 0.271f, 0.075f); //Set the colur to an opaque light brown
		Box::box(1, 2, 1.5f); //Draw a 1 x 2 x 1.5 cube
		glTranslatef(-1, 0, 0); //Move left by 1
		glColor3f(0.961f, 0.871f, 0.702f); //Set the colour to an opaque light beige
		Box::box(.1f, 1.5f, 1); //Draw a 0.1 x 1.5 x 1 cube
	glPopMatrix();
}

/*
Draws sunglasses
*/
void Monkey::drawSunglasses() {
	glColor4f(0.f, 0.f, 0.f, .25f); //Set the colour to translucent black
	Box::box(.85f, .85f, 1.8f); //Draw a 0.85 x 0.85 x 1.8 cube
}

/*
Draws the Monkey's eye
*/
void Monkey::drawEye() {
	glColor4f(0.f, 0.f, 0.f, 1.f); //Set the colour to opaque black
	Box::box(.325f, .325f, .325f); //Draw a 0.325 x 0.325 x 0.325 cube
}

/*
Draws the Monkey's right arm
*/
void Monkey::drawRightArm() {
	glPushMatrix();
		glRotatef(shoulderRotation, 0, 1, 0); //Rotates the arm by the animated amount along the y axis
		glRotatef(-70, 1, 0, 0); //Rotates the arm by 70 degrees clockwise along the x axis
		glColor3f(0.545f, 0.271f, 0.075f); //Set the colour to an opaque light brown
		Box::box(0.2f, 1, 0.2f); //Draw a 0.2 x 1 x 0.2 cube
		glTranslatef(0, -2.15f, .5f); //Move down by 2.15 and forward by 0.5
		glRotatef(-20, 1, 0, 0); //Rotate by 20 degrees clockwise along the x axis
		glRotatef(elbowRotation, 0, 1, 0); //Rotate the elbox by the animated amount alongth the y axis
		Box::box(0.2f, 1.5f, 0.2f); //Draw a 0.2 x 1.5 x 0.2 cube
	glPopMatrix();
}

/*
Draws the Monkey's left arm
*/
void Monkey::drawLeftArm() {
	glPushMatrix();
		glRotatef(180, 0, 0, 1); //Flip the arm
		glRotatef(-40, 1, 0, 0); //Rotate the arm 40 degrees clockwise along the x axis
		glColor3f(0.545f, 0.271f, 0.075f); //Set the colour to an opaque light brown
		Box::box(0.2f, 1.5f, 0.2f); //Draw a 0.2 x 1.5 x 0.2 cube
	glPopMatrix();
}