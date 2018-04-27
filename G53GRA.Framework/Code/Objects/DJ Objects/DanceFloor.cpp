#include "DanceFloor.h"

/* 
Party Animals: Dance Floor
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void DanceFloor::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);

			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			for (float x = -10; x < 10; x++) //Draw a 20 x 20 multicoloured dance floor
				for (float y = -10; y < 10; y++)
				{
					int loc = (int)(abs(x) + abs(y) + animTime / 50) % 7; //Determine which colour to use on this square
		
					glColor4f(red[loc],green[loc],blue[loc], 1.f); // Set the colour of this square
				
					glBegin(GL_QUADS); //Draw the square
						glVertex3f(x, -0.1f, y);
						glVertex3f(x, -0.1f, y + 1);
						glVertex3f(x + 1, -0.1f, y + 1);
						glVertex3f(x + 1, -0.1f, y);
					glEnd();
				}
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void DanceFloor::Update(double const& dT) {
	if (animTime++ > 1000)  //Increment the animation time
		animTime = 0; //Reset the animation time if it exceeds the bounds
}