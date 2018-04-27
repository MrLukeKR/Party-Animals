#include "Elephant.h"
#include "Objects\Box.h"
#include "Objects\PartyHat.h"

/* Party Animals: Elephant
   Author: Luke K. Rose
   April 2018
*/

/*
Draws the object
*/
void Elephant::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
	
			drawBody(); //Draws the Elephant's body
	
			for(int i = -1; i <= 1; i += 2)
				for (int j = -1; j <= 1; j += 2) { //Draws 4 legs in each corner of the Elephant's body
					glPushMatrix();
						glTranslatef(i * 6, -7, j * 4);
						drawLeg(); //Draws a leg
					glPopMatrix();
				}
				glTranslatef(9, 5, 0); //Move east by 9 and up by 5
				drawHead(); //Draws the Elephant's head
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Elephant::Update(const double& dT) {
	animationAngle += reverseAnimation ? -5 : 5; //Increments/Decrements the animation angle by 5 degrees

	if (animationAngle >= 45) //Flips the animation when passing past certain bounds
		reverseAnimation = true;
	else if (animationAngle <= -45)
		reverseAnimation = false;
}

/*
Draws the Elephant's body
*/
void Elephant::drawBody() { 
	glColor4f(1, 1, 1, 1); //Set colour to opaque white
	Box::box(7, 5, 5, elephantTex); //Draws a 7 x 5 x 5 cube using the Elephant texture
}

/*
Draws the Elephant's leg
*/
void Elephant::drawLeg()  { 
	glColor4f(1, 1, 1, 1); //Set colour to opaque white
	Box::box(1, 3, 1, elephantTex);  //Draws a 1 x 3 x 1 cube using the Elephant texture
}

/*
Draws the Elephant's eyes
*/
void Elephant::drawEyes() {
	glColor4f(0, 0, 0, 1); //Sets the colour to opaque black
	for (int i = -1; i <= 1; i += 2) { //Draws 2 eyes that mirror each other
		glPushMatrix();
			glTranslatef(3, 1, i * 1.5f); //Moves east by 3, up by 1 and forward/backward by 1.5
			Box::box(0.5f, 0.5f, 0.5f); //Draws a 0.5 x 0.5 x 0.5 cube
		glPopMatrix();
	}
}

/*
Draws the Elephant's head
*/
void Elephant::drawHead() {
	glPushMatrix();
		Box::box(3, 3, 3, elephantTex); //Draws a 3 x 3 x 3 cube with the Elephant texture
		glTranslatef(4, 0, 0); //Moves east by 4
		drawTusks(); //Draws the Elephant's tusks
		glPushMatrix();
			glTranslatef(0, -4.5f, 0); //Moves down by 4.5
			glRotatef(-65, 0, 0, 1); //Rotates clockwise by 65 degrees along the z axis
			drawTrunk(); //Draws the Elephant's trunk
		glPopMatrix();
		glTranslatef(-4, 0, 0); //Moves west by 4
		drawEyes(); //Draws the Elephant's eyes
		glTranslatef(0, 3, 0); //Moves up by 3
		drawEars(); //Draws the Elephant's ears
		PartyHat* hat = new PartyHat(); //Creates a new party hat
		hat->size(2, 2, 2); //Doubles the size of the party hat
		hat->Display(); //Draws the party hat
	glPopMatrix();
}

/*
Draws the Elephant's trunk
*/
void Elephant::drawTrunk() {
	glColor4f(1, 1, 1, 1); //Sets colour to opaque white
	glPushMatrix();
		glTranslatef(0, animationAngle / 15.f, 0); //Moves up/down by the animation angle divided by 15
		glRotatef(animationAngle, 0, 0, 1); //Rotates around the z axis according to the current animation rotation
		Box::box(4, 0.75f, 0.75f, elephantTex); //Draws a 4 x 0.75 x 0.75 cube using the Elephant texture
	glPopMatrix();
}

/*
Draws the Elephant's tusks
*/
void Elephant::drawTusks() {
	glColor4f(0.9f, 0.9f, 0.9f, 1); //Sets colour to opaque slightly off-white
	for (int i = -1; i <= 1; i += 2) { //Draws 2 tusks that mirror each other
		glPushMatrix();
			glTranslatef(0, -1.5f, i * 2); //Moves 1.5 down and 2 forward/backward
			glRotatef(-25, 0, i, 1); //Rotates by 25 degrees (counter) clockwise along the y axis and clockwise around the z axis 
			Box::box(2, 0.5f, 0.5f); //Draws a 2 x 0.5 x 0.5 cube
		glPopMatrix();
	}
}

/*
Draws the Elephant's ears
*/
void Elephant::drawEars() {
	glColor4f(1, 1, 1, 1); //Set colour to opaque white
	for (int i = -1; i <= 1; i += 2) { //Draws 2 ears that mirror each other
		glPushMatrix();
			glTranslatef(0, 0, i * 3); //Move 3 forward/backward
			glRotatef(-45 - animationAngle, 0, 1, 0); //Rotates the ears along the y axis according to the current animation angle
			Box::box(0.1f, 2, 2, elephantTex); //Draws a 0.1 x 2 x 2 cube using the Elephant texture
		glPopMatrix();
	}
}