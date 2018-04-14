#include "Smoke.h"

int Smoke::fireIndex = 0;

void Smoke::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glColor4f(intensity, intensity, intensity, opacity);
	glutSolidSphere(10, 20, 20);

	glPopAttrib();
	glPopMatrix();
}

void Smoke::Update(const double& dT) {
	for (int i = 0; i < 3; i++) scale[i] += .1f;
	pos[0] -= 5;
	pos[1] += (rand() % 2) - 1;
	pos[2] += (rand() % 2) - 1;
	speed *= deceleration;
	opacity = pos[0] / 100.0f;
	intensity /= deceleration;
	if (pos[0] <= 0 && Smoke::fireIndex++ == index) {
		memcpy(pos, emissionLoc, sizeof(pos));
		speed = initSpeed;
		for (int i = 0; i < 3; i++) scale[i] = .1f;
		intensity = (rand() % 3) / 10.0f;
	}

	if (fireIndex >= instances)
		fireIndex = 0;
}