#include "Moon.h"

Moon::Moon()
{
}

Moon::~Moon()
{
}

void Moon::Display() {
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
	glColor3f(1.f,1.f,1.f);

	glutSolidSphere(scale[0],10,10);	

	glPopMatrix();
	glPopMatrix();
}

void Moon::Update(const double& deltaTime)
{
	if((int) orbitRotation == 0)
		glEnable(GL_LIGHT2);
	else if((int)orbitRotation == 180)
		glDisable(GL_LIGHT2);

	for (int i = 0; i < 4; i++) {
		//light_ambient[i] = sin(orbitRotation * M_PI / 180) / 100.f;
		light_diffuse[i] = sin(orbitRotation * M_PI / 180);
	}

	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_diffuse);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);

	//printf("%f - %f\r\n",orbitRotation, sin(orbitRotation * M_PI / 180 ));

	orbitRotation += .1f;
	if (orbitRotation >= 360.f)
		orbitRotation = 0;
}