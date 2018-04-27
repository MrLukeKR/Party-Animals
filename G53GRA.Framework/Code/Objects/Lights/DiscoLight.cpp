#include "DiscoLight.h"
#include "Objects\Box.h"

/*
Party Animals: Disco Light
Author: Luke K. Rose
April 2018
*/

/*
Initialise the light source by enabling it and setting its direction and colour
*/
DiscoLight::DiscoLight(GLfloat dirX, GLfloat dirY, GLfloat dirZ, GLenum light, float colorSeed) : lightSource(light), light_direction{ dirX, dirY, dirZ }, value(colorSeed)
{
	glEnable(lightSource);
}

/*
Draws the object
*/
void DiscoLight::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
			glColor4f(light_ambient[0], light_ambient[1], light_ambient[2], 1); //Set the colour of the light
			Box::box(1, 1, 1); //Draw a 1 x 1 x 1 cube
		glPopAttrib();
	glPopMatrix();

	//Local lighting setup:
	glLightfv(lightSource, GL_AMBIENT, light_ambient);
	glLightfv(lightSource, GL_DIFFUSE, light_diffuse);
	glLightfv(lightSource, GL_SPECULAR, light_specular);
	glLightfv(lightSource, GL_SPOT_DIRECTION, light_direction);
	glLightfv(lightSource, GL_SPOT_CUTOFF, spot_cutoff);
	glLightfv(lightSource, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(lightSource, GL_POSITION, light_position);
}

/*
Updates animation angles and translation vectors for the object
*/
void DiscoLight::Update(const double& deltaTime) {
	light_position[0] = pos[0]; //Animate the light's position
	light_position[1] = pos[1];
	light_position[2] = pos[2];

	for (int i = 0; i < 3; i++) 
		light_ambient[i] = (float)(((int)(value += 0.075f) >> i) & 1); //Set the colour of the light

	if (value == 7) value = 1; //Reset the colour wheel back to the beginning
}