#include "DiscoBallParrot.h"
#include "Objects\Box.h"
#include "Objects\PartyHat.h"

/* 
Party Animals: Disco Ball Parrot
Author: Luke K. Rose
April 2018
*/

/*
Initialises the object by creating a series of arrays to hold angles to rotate the light rays by
*/
DiscoBallParrot::DiscoBallParrot() {
		for (int i = 0; i < NUMBER_OF_RAYS; i++) { //Initialise all of these arrays with random values
			degree[i] = (float)rand();
			x[i] = (float)rand();
			y[i] = (float)rand();
			z[i] = (float)rand();
		}
}

/*
Clear the memory used for angle arrays
*/
DiscoBallParrot::~DiscoBallParrot() { 
	delete[] degree;
	delete[] x;
	delete[] y;
	delete[] z;
}

/*
Draws the object
*/
void DiscoBallParrot::Display() {
	glPushMatrix();
			glPushAttrib(GL_ALL_ATTRIB_BITS);
				glTranslatef(pos[0], pos[1] + altitudeChange, pos[2]); //Translate the object, altering the y value to account for floating up and down
				glScalef(scale[0], scale[1], scale[2]); //Scale the object
				glRotatef(rotation[0], 1.f, 0.f, 0.f); //Rotate the object along the x axis
				glRotatef(rotation[1], 0.f, 1.f, 0.f); //Rotate the object along the y axis
				glRotatef(rotation[2], 0.f, 0.f, 1.f); //Rotate the object along the z axis
				
				glPushMatrix();
					glTranslatef(0.f, 5.f, 0.f); //Move up by 5
					glRotatef(-10.f, 0.f, 0.f, 1.f); //Rotate 10 degrees clockwise along the z axis
					drawParrot(); //Draw the Parrot part of this object
				glPopMatrix();
				glTranslatef(-.5f, 0.f, 0.f); //Move left by 0.5
				drawString(); //Draw the String that connects the Parrot to the Mirrorball
				glTranslatef(0, -5.f, 0.f); //Move down by 5
				drawDiscoBall(); //Draw the Mirrorball part of this object
			glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void DiscoBallParrot::Update(const double& dT) {
	discoBallRotation += .25f; //Increases the Mirror Ball's rotation angle by 0.25
	wingAngle += reverseFlap ? -10 : 10; //Increases or decreases the Parrot's wing angle by 10 depending on the current floating direction
	altitudeChange += reverseAltitude ? -ALTITUDE_CHANGE_FREQUENCY : ALTITUDE_CHANGE_FREQUENCY; //Increases or decreases the Parrot's altitude by a given amount

	if (wingAngle >= 70) //Reverses the flapping direction when passing past a threshold
		reverseFlap = true;
	else if (wingAngle <= -70)
		reverseFlap = false;

	if (altitudeChange >= ALTITUDE_RANGE) //Reverses the floating direction if passing past a threshold
		reverseAltitude = true;
	else if (altitudeChange <= -ALTITUDE_RANGE)
		reverseAltitude = false;

	for (int i = 0; i < NUMBER_OF_RAYS; i++) //Increases the degree of each light ray
		degree[i] += ((float) rand() / (float) RAND_MAX * 0.01f);
}

/*
Draws a string for the Parrot to carry the Mirrorball
*/
void DiscoBallParrot::drawString() {
	glPushMatrix();
		glColor4f(1.f, 1.f, 1.f, 1.f); //Change colour to opaque white
		glBegin(GL_LINE_LOOP);
			glVertex3f(0.f, 2.f, 0.f); //Start the line at 2 along the y axis
			glVertex3f(0.f, -2.f, 0.f); //End the line at -2 along the y axis
		glEnd();
	glPopMatrix();
}

/*
Draws the Parrot part of the object
*/
void DiscoBallParrot::drawParrot() {
	glPushMatrix();
		drawBody(); //Draws the main cube of the Parrot's body
		glPushMatrix();
			glTranslatef(0.f, -3.f, 0.f); //Move down by 3
			drawFeet(); //Draws the Parrot's feet
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-.5f, -1.5f, 0.f); //Move down by 1.5 and left by 0.75
			glRotatef(-30, 0.f, 0.f, 1.f); //Rotate 30 degrees clockwise along the z axis
			drawTailFeathers(); //Draws the Tail Feathers of the parrot
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.f, 0.f, -1.f); //Move backward by 1
			glRotatef(-90.f, 0.f, 1.f, 0.f); //Rotate 90 degrees counter-clockwise along the y axis
			drawWing(true); //Draw a wing but don't mirror it
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.f, 0.f, 1.f); //Move forward by 1
			glRotatef(90.f, 0.f, 1.f, 0.f); //Rotate 90 degrees clockwise along the y axis
			drawWing(false); //Draw a wing and mirror it
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1.f, 2.5f, 0.f); //Move right by 1 and down by 2.5
			drawHead(); //Draws the head of the Parrot
		glPopMatrix();
	glPopMatrix();
}

/*
Draws the main cube of the Parrot's body
*/
void DiscoBallParrot::drawBody() {
	glPushMatrix();
		glColor4f(1.f, 0.f, 0.f, 1.f); //Change colour to opaque red
		Box::box(1.f, 2.f, 1.f); //Draw 1 x 2 x 1 cube without texture
	glPopMatrix();
}

/*
Draws the feet of the Parrot
*/
void DiscoBallParrot::drawFeet() {
	glPushMatrix();
	for (int i = -1; i <= 1; i += 2) { //Draws two feet opposite to each other
		glColor4f(0.3f, 0.3f, 0.3f, 1.f); //Change colour to opaque grey
		glPushMatrix();
			glTranslatef(0.f, 0.f, 0.5f * i); //Move forward/backward by 0.5
			glRotatef(10.f * i, 1.f, 0.f, 0.f); //Rotate by 10 degrees (counter) clockwise along the x axis
			Box::box(0.1f, 1.f, 0.1f); //Draw 0.1 x 1 x 0.1 cube
		glPopMatrix();
	}
	glPopMatrix();
}

/*
Draws the head of the Parrot
*/
void DiscoBallParrot::drawHead() {
	glPushMatrix();
		glColor4f(1.f, 0.f, 0.f, 1.f); //Change colour to opaque red
		Box::box(0.75f, 0.75f, 0.75f); //Draw 0.75 x 0.75 x 0.75 cube
		glTranslatef(0.3f, 0.f, 0.f); //Move right by 0.3
		glColor4f(1.f, 1.f, 1.f, 1.f); //Change colour to opaque white
		Box::box(0.5f, 0.5f, 0.8f); //Draw 0.5 x 0.5 x 0.8 cube
		glColor4f(0.f, 0.f, 0.f, 1.f); //Change colour to opaque black
		for (float i = -1; i <= 1; i += 2) { //Draws two eyes for the Parrot
			glPushMatrix();
				glTranslatef(0.f, 0.f, i); //Move forward/backward by 1
				Box::box(0.1f, 0.1f, 0.1f); //Draw 0.1 x 0.1 x 0.1
			glPopMatrix();
		}
		glTranslatef(.5f, 0.f, 0.f); //Move right by 0.5
		drawBeak(); //Draws the Parrot's beak
		glTranslatef(-.5f, 1.f, 0.f); //Move up by 1 and left by 0.5
		glPushMatrix();
			PartyHat* hat = new PartyHat(); //Create a new party hat
			hat->orientation(30, 0, 0); //Rotate the party hat by 30 degrees
			hat->position(0, -.5f, .5f); //Move the party hat down by 0.5 and forward by 0.5
			hat->Display(); //Draw the party hat
		glPopMatrix();
		glScalef(0.5f, 0.5f, 0.5f); //Half the size of the following
		glRotatef(90.f, 0.f, 1.f, 0.f); //Rotate 90 degrees counter clockwise along the y axis
		glRotatef(180.f, 1.f, 0.f, 0.f); //Flip along the x axis
		for (int i = 0; i < 3; i++) { //Draws 3 feathers on the Parrot's head
			drawFeather(); //Draws a feather
			glRotatef(-30.f, 1.f, 0.f, 0.f); //Rotate 30 degrees clockwise along the x axis
			glScalef(0.8f, 0.8f, 0.8f); //Set the scale to 0.8x the current size
		}
	glPopMatrix();
}

/*
Draws the beak of the Parrot
*/
void DiscoBallParrot::drawBeak() {
	glPushMatrix();
		glColor4f(0.f, 0.f, 0.f, 1.f); //Set colour to opaque black
		glBegin(GL_TRIANGLES);	
			glVertex3f(0.f, 0.5f, 0.f); //Set vertex at 0.5 up
			glVertex3f(1.f, 0.f, 0.f); //Set vertex at 1 right
			glVertex3f(0.f, 0.f, 0.5f); //Set vertex at 0.5 forward
		glEnd();
		glBegin(GL_TRIANGLES);
			glVertex3f(0.5f, 0.f, -0.25f); //Set vertex at 0.5 right, 0.2f backward
			glVertex3f(0.75f, -0.5f, 0.f); //Set vertex at 0.75 right, 0.5 down
			glVertex3f(1.f, 0.f, 0.f); //Set vertex at 1 right
		glEnd();
		glBegin(GL_TRIANGLES);
			glVertex3f(0.5f, 0.f, 0.25f); //Set vertex at 0.5 right, 0.25 forward
			glVertex3f(1.f, 0.f, 0.f); //Set vertex at 1 right
			glVertex3f(0.75f, -0.5f, 0.f); //Set vertex at 0.75 right, 0.5 down
		glEnd();
		glBegin(GL_TRIANGLES);
			glVertex3f(0.f, 0.5f, 0.f); //Set vertex at 0.5 up
			glVertex3f(0.f, 0.f, -0.5f); //Set vertex at 0.5 backward
			glVertex3f(1.f, 0.f, 0.f); //Set vertex at 1 right
		glEnd();
	glPopMatrix();
}

/*
Draws the wing of the Parrot
*/
void DiscoBallParrot::drawWing(bool invert) {
	glRotatef(wingAngle, (invert ? -1.f : 1.f) / 4.f, 0.f, 1.f); //Rotate the Parrot's wing by the animation angle along the x axis by a factor of 0.25 and z axis by a factor of 1
	glPushMatrix();
		glRotatef(-90.f, 0.f, 0.f, 1.f); //Rotate 90 degrees
		for (int i = 0; i < 3; i++) { //Draw 3 feathers
			drawFeather(); //Draws a feather
			glRotatef(invert ? -10.f : 10.f, 1.f, 0.f, invert ? -1.f : 1.f); //Rotate 10 degrees (counter) clockwise along the x axis and counter clockwise along the z axis
			glScalef(0.75f, 0.75f, 0.75f); //Set the scale to 0.75x the current size
		}
	glPopMatrix();
}

/*
Draws the Tail Feathers of the Parrot*/
void DiscoBallParrot::drawTailFeathers() {
	glPushMatrix();
		glRotatef(wingAngle / 8.0f, 0.f, 0.f, 1.f); //Rotate the angle of the tail feathers along the z axis based on the current animation angle. Divide by 8 to lessen the magnitude of the angle.
		for (float i = -1; i <= 1; i ++) { //Draws 3 feathers, 1 in the middle and 2 mirroring each other
			glPushMatrix();
				glTranslatef(0.f, 0.f, 0.65f * i); //Move 0.65 forward/backward
				glRotatef(-5.f * i, 1.f, 0.f, 0.f); //rotate 5 degrees (counter) clockwise along the x axis
				drawFeather(); //Draws a feather
			glPopMatrix();
		}
	glPopMatrix();
}

/*
Draws a single feather
*/
void DiscoBallParrot::drawFeather() {
	glPushMatrix();
		for (int i = 0; i < 4; i++) {
			glColor4f((float)(i == 0 || i == 3), (float)(i == 1 || i == 3), (float)(i == 2), 1.f); //Change color based on the current position of i (C++ assigns true booleans a value of 1 and false booleans a value of 0)
			glTranslatef(0, -FEATHER_SEGMENT_LENGTH * 2, 0.f); //Move 2 * the length of feeather colours down
			Box::box(.1f, FEATHER_SEGMENT_LENGTH, 1.0f / 3.0f); //Draw a 0.1 x Feather Length x 0.33333r cube
		}
	glPopMatrix();
}

/*
Draws the Mirror Ball for the Parrot to hold
*/
void DiscoBallParrot::drawDiscoBall() {
	glPushMatrix();
		glColor4f(0.8f, 0.8f, 0.8f, 1.f); //Change colour to opaque light grey
		glRotatef(discoBallRotation, 0.f, 1.f, 0.f); //Rotate the Mirror Ball along the y axis according to the current animation rotation

		glEnable(GL_TEXTURE_2D);
			glEnable(GL_COLOR_MATERIAL);
				glBindTexture(GL_TEXTURE_2D, discoBallTex);
					GLUquadric* quadric = gluNewQuadric();
					gluQuadricNormals(quadric, GLU_SMOOTH); //Generate normals for the sphere
					gluQuadricTexture(quadric, GL_TRUE); //Generate texture coordinates for the sphere
					gluSphere(quadric,3, 8, 8); //Draw a sphere
				glBindTexture(GL_TEXTURE_2D, NULL);
			glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_TEXTURE_2D);
		drawRays(); //Draws volumetric light rays eminating from the Mirror Ball
	glPopMatrix();
}

/*
Draws false volumetric "God-Rays", eminating from the Mirror Ball
*/
void DiscoBallParrot::drawRays() {
	glPushMatrix();
		glDisable(GL_LIGHTING);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glColor4f(1.f, 1.f, 1.f, 0.1f); //Change colour to barely visible white
				for (int i = 0; i < NUMBER_OF_RAYS; i++) //Draws a set number of light rays
					for (int j = 0; j <= 1; j++) { //Draws 2 sides of a ray (because of backface culling)
						glRotatef(degree[i], x[i], y[i], z[i]); //Rotate the ray by its initially set random amount
						glBegin(GL_TRIANGLES);
							glVertex3f(0.f, 0.f, 0.f); //Draw a vertex at the origin
							glVertex3f(0.f, 200.f, 10.f - j * 5.f); //Draw a vertex at 200 along the y axis and 5 or 10 along the x axis
							glVertex3f(0.f, 200.f,  5.f + j * 5.f); //Draw a vertex at 200 along the y axis and 5 or 10 along the x axis
						glEnd();
					}
			glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}