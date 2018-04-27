#include "Laser.h"
#include "Objects\Box.h"

#define NUMBER_OF_LASERS 10

Laser::Laser() {
	degree = new float[NUMBER_OF_LASERS];
	x = new float[NUMBER_OF_LASERS];
	y = new float[NUMBER_OF_LASERS];

	for (int i = 0; i < NUMBER_OF_LASERS; i++) {
		degree[i] = rand();
		x[i] = (rand() / RAND_MAX * 90.f) - 45.f;
		y[i] = (rand() / RAND_MAX * 90.f) - 45.f;
	}

}

Laser::~Laser() {
	delete[] degree;
	delete[] x;
	delete[] y;
}

void Laser::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
	
			drawUnit();
			glTranslatef(-2, 0, 0);
			drawLasers();
		glPopAttrib();
	glPopMatrix();
	
}

void Laser::Update(const double& dT) {
	static double totalTime = 0;
	totalTime += dT;

	for (int i = 0; i < NUMBER_OF_LASERS; i++)
		degree[i] = degree[i] + ((float)rand() / (float)RAND_MAX);

	switch ((int) (totalTime) % 6) {
	case 0:
		red = 1;
		green = 0;
		blue = 0;
		break;
	case 1:
		red = 0;
		green = 1;
		blue = 0;
		break;
	case 2:
		red = 0;
		green = 1;
		blue = 1;
		break;
	case 3:
		red = 0;
		green = 1;
		blue = 1;
		break;
	case 4:
		red = 1;
		green = 0;
		blue = 1;
		break;
	case 5:
		red = 1;
		green = 1;
		blue = 0;
		break;
	}

}

void Laser::drawUnit() {
	glPushMatrix();
		glColor4f(0, 0, 0, 1);
		Box::box(2, 1, 1);
	glPopMatrix();
}

void Laser::drawLasers() {
	glDisable(GL_LIGHTING);
	glPushMatrix();
	for (int i = 0; i < NUMBER_OF_LASERS; i++) {
		glRotatef(degree[i], x[i], y[i], 0);
		glPushMatrix();
			glColor4f(red, green, blue, 0.8f);
			glBegin(GL_LINE_LOOP);
				glVertex3f(0, 0, 0);
				glVertex3f(0, -100, 0);
			glEnd();
		glPopMatrix();
	}
	glPopMatrix();
	glEnable(GL_LIGHTING);
}