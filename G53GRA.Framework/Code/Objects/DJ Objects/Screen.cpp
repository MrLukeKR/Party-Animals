#include "Screen.h"
#include "Objects\Box.h"
#include <time.h>

/*
"Bedhead" Strange Attractor
*/
#define BEDHEAD_X sin(x * y / b) * y + cos(a * x - y)
#define BEDHEAD_Y x + sin(y) / b
#define BEDHEAD_MAX 1
#define BEDHEAD_MIN -1

/*
"Hopalong" Strange Attractor
*/
#define HOPALONG_X y - 1 - sqrt(abs(b*x-1-c))* ((0 < (x-1)) - ((x-1) < 0))
#define HOPALONG_Y a - x - 1
#define HOPALONG_MAX 10
#define HOPALONG_MIN 0

/*
Party Animals: Screen
Author: Luke K. Rose
April 2018
*/

/*
Initialises the object by assigning the coefficients random values
*/
Screen::Screen(bool invert) : invert(invert) {
	srand((unsigned int) time(NULL)); //Initialise the Strange Attractor randomly using the current time
	x = 1.f; y = 1.f; 
	a = (float) rand() / (float) RAND_MAX - 1;
	b = (float) rand() / (float) RAND_MAX - 1;
}

/*
Draws the object
*/
void Screen::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
	
			glPushMatrix();
				glDisable(GL_LIGHTING);
	
					glColor4f(0, 0, 0, 1); //Set the colour to opaque black
					Box::box(0.1f, 5, 7.5f); //Draw a 0.1 x 5 x 7.5 cube
	
					if (invert) glRotatef(180, 0, 1, 0); //If the screen is to be mirrored, flip it by 180 degrees along the y axis
					glBegin(GL_POINTS);
						for (float i = 0; i < 25000; i++) { //Draw 25,000 points on the screen
							if (x < 5.f && y < 7.5f && x > -5.f && y > -7.5f) {
								glColor4f(red, green, blue, .25f); //Set the colour to the currently determined mix and make it 25% visible (to build up more dense areas and hide sparse areas)
								glVertex3f(invert ? 0.2f : -0.2f, x, y); //Draw the point
							}
						
							float dX = BEDHEAD_X, dY = BEDHEAD_Y; //x and y cannot be directly set as they rely on each other's value for their own

							x = dX; //NOW we can set the x and y values back
							y = dY;
						}
					glEnd();
				glEnable(GL_LIGHTING);
			glPopMatrix();
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Screen::Update(const double& deltaTime) {
	col = (col - 256) % (TOTAL_COLOURS); //Cycle through the colours
	red = ((col >> 16) & 0xFF) / 256.0f; //Bitshift to get the red value from the total colour
	green = ((col >> 8) & 0xFF) / 256.0f; //Bitshift to get the green value from the total colour
	blue = (col & 0xFF) / 256.0f; //Bitshift to get the blue value from the total colour
	a += reverseA ? -0.01f : 0.01f; //Increment the coefficients by 0.01
	b += reverseB ? -0.01f : 0.01f;

	if (a >= BEDHEAD_MAX) reverseA = true; //Reverse the coefficients if they exceed the bounds
	else if (a <= BEDHEAD_MIN) reverseA = false;
	if (b >= BEDHEAD_MAX) reverseB = true;
	else if (b <= BEDHEAD_MIN) reverseB = false;
}