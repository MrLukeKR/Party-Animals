#include "Sun.h"

Sun::Sun()
{
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glEnable(GL_LIGHT1);
}

Sun::~Sun()
{
}

void Sun::Display() {
	glPushMatrix();

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);

	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);

	glPushMatrix();
	glTranslatef(-pos[0], -pos[1], -pos[2]);
	glRotatef(orbitRotation, 0, 0, 1);
	glTranslatef(pos[0], pos[1], pos[2]);

	glColor3f(0.95f,0.95f,0.5f);

	glutSolidSphere(scale[0],10,10);	

	glPopMatrix();
	glPopMatrix();
}

void Sun::Update(const double& deltaTime)
{
	orbitRotation += .1f;
	if (orbitRotation >= 360.f)
		orbitRotation = 0;
}