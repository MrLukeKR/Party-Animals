#include "Moon.h"

/*
Party Animals: Moon
Author: Luke K. Rose
April 2018
*/

/*
Draws the object
*/
void Moon::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glRotatef(orbitRotation, 0, 0, 1); //Rotate the moon about its orbit
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
	
			glColor4f(1.f,1.f,1.f, 1.f); //Set the colour to opaque white
			glutSolidSphere(scale[0], 10, 10); //Draw the moon
		glPopAttrib();
	glPopMatrix();
}

/*
Updates animation angles and translation vectors for the object
*/
void Moon::Update(const double& deltaTime)
{
	if((int) orbitRotation == 0) //Turn on the moon if it's above the world
		glEnable(GL_LIGHT2);
	else if((int)orbitRotation == 180) //Turn off the moon if it's below the world
		glDisable(GL_LIGHT2);

	for (int i = 0; i < 4; i++) //Set the brightness of the moon
		light_diffuse[i] = (float)sin(orbitRotation * M_PI / 180.f);

	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_diffuse);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);

	orbitRotation += .1f; //Update the orbit of the moon
	if (orbitRotation >= 360.f) //Reset the orbit of the moon if it exceeds the bounds
		orbitRotation = 0;
}