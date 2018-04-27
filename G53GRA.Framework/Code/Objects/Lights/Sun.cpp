#include "Sun.h"

/*
Party Animals: Sun
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Sun::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glRotatef(orbitRotation, 0, 0, 1); //Rotate the sun about its orbit
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);

			glColor3f(color[0], color[1], color[2]); //Set the colour of the sun depending on its position
			glutSolidSphere(scale[0], 10, 10); //Draw the sun
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Sun::Update(const double& deltaTime)
{
	if((int) orbitRotation == 0) //Turn the sun on if it's above the world
		glEnable(GL_LIGHT1);
	else if((int) orbitRotation == 180) //Turn the sun off if it's below the world
		glDisable(GL_LIGHT1);

	color[1] = (float)std::fmax(cos((orbitRotation - 90.f)* M_PI / 180.f * 0.647f),0.f); //Determine the greenness of the sun based on its position
	color[2] = (float)std::fmax(sin(orbitRotation * M_PI / 180.f),0.f); //Determine the blueness of the sun based on its position
	 
	for (int i = 0; i < 4; i++) 
		light_ambient[i] = (float)sin(orbitRotation * M_PI / 180.f) * 2.f * color[i]; //Set the colour of the sun

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);

	orbitRotation += .1f; //Update the orbit
	if (orbitRotation >= 360.f) //Reset the orbit if it exceeds the bounds
		orbitRotation = 0;
}