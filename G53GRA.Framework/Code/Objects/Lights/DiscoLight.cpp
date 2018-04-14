#include "DiscoLight.h"
#include "Objects\Box.h"

DiscoLight::DiscoLight(GLfloat dirX, GLfloat dirY, GLfloat dirZ, GLenum light, float colorSeed) : lightSource(light), light_direction{ dirX, dirY, dirZ }, value(colorSeed)
{
	glEnable(lightSource);
}


DiscoLight::~DiscoLight()
{
}

void DiscoLight::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);
	glColor3f(light_ambient[0], light_ambient[1], light_ambient[2]);
	Box::box(1,1,1);

	glPopAttrib();
	glPopMatrix();

	glLightfv(lightSource, GL_AMBIENT, light_ambient);
	glLightfv(lightSource, GL_DIFFUSE, light_diffuse);
	glLightfv(lightSource, GL_SPECULAR, light_specular);
	glLightfv(lightSource, GL_SPOT_DIRECTION, light_direction);
	glLightfv(lightSource, GL_SPOT_CUTOFF, spot_cutoff);
	glLightfv(lightSource, GL_SPOT_EXPONENT, spot_exponent);
	glLightfv(lightSource, GL_POSITION, light_position);
}

void DiscoLight::Update(const double& deltaTime) {
	light_position[0] = pos[0];
	light_position[1] = pos[1];
	light_position[2] = pos[2];

	static bool ambShift = true;

	for (int i = 0; i < 3; i++) {
		light_ambient[i] = ((int)value >> i) & 1;
	}

	value += 0.075f;
	if (value == 7)
		value = 1;
}