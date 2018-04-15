#include "Sun.h"


Sun::Sun()
{
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

	glColor3f(color[0], color[1], color[2]);

	glutSolidSphere(scale[0],10,10);	

	glPopMatrix();
	glPopMatrix();
}

void Sun::Update(const double& deltaTime)
{
	if((int) orbitRotation == 0)
		glEnable(GL_LIGHT1);
	else if((int) orbitRotation == 180)
		glDisable(GL_LIGHT1);

	//color[0] = std::fmax(sin(orbitRotation * M_PI / 360), 0);
	color[1] = std::fmax(cos((orbitRotation - 90)* M_PI / 180 * 0.647),0);
	color[2] = std::fmax(sin(orbitRotation * M_PI / 180),0);
	 
	for (int i = 0; i < 4; i++) {
		light_ambient[i] = sin(orbitRotation * M_PI / 180) * 2.f * color[i];
	}

	//printf("Orbit: %f - Intensity: %f%%, Red: %f, Green: %f, Blue: %f\r\n",orbitRotation, (sin(orbitRotation * M_PI / 180 ) + 1) / 2 * 100, color[0],color[1],color[2]);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);

	orbitRotation += .1f;
	if (orbitRotation >= 360.f)
		orbitRotation = 0;
}