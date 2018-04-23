#include "Screen.h"
#include "Objects\Box.h"
#include <time.h>
#define BEDHEAD_X sin(x * y / b) * y + cos(a * x - y)
#define BEDHEAD_Y x + sin(y) / b
#define BEDHEAD_MAX 1
#define BEDHEAD_MIN -1

#define HOPALONG_X y - 1 - sqrt(abs(b*x-1-c))* ((0 < (x-1)) - ((x-1) < 0))
#define HOPALONG_Y a - x - 1
#define HOPALONG_MAX 10
#define HOPALONG_MIN 0

Screen::Screen(bool invert) : invert(invert) {
	srand(time(NULL));
	x = 1.f; y = 1.f; 
	a = (float) rand() / (float) RAND_MAX - 1;
	b = (float) rand() / (float) RAND_MAX - 1;
	c = (float) rand() / (float) RAND_MAX - 1;
}

void Screen::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);
	
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_LIGHTING);
	
	
	if (invert) glRotatef(180, 0, 1, 0);
	glBegin(GL_POINTS);
	
	
	for (int i = 0; i < 10000; i++) {
		double dX = BEDHEAD_X;
		double dY = BEDHEAD_Y;

		x = dX;
		y = dY;

		if (x < 5.f && y < 7.5f && x > -5.f && y > -7.5f) {
			glColor3f(red, green, blue);
			glVertex3f(invert ? 0.1f : -0.1f, x, y);
		}
	}
		
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);

	glColor3f(0, 0, 0);
	Box::box(0.1f, 5, 7.5f);

	glPopAttrib();
	glPopMatrix();
}

void Screen::Update(const double& deltaTime) {
	col = (col - 256) % (TOTAL_COLOURS);
	red = ((col >> 16) & 0xFF) / 256.0f;
	green = ((col >> 8) & 0xFF) / 256.0f;
	blue = (col & 0xFF) / 256.0f;
	a += reverseA ? -0.001f : 0.001f;
	b += reverseB ? -0.001f : 0.001f;
	c += reverseC ? -0.001f : 0.001f;

	if (a >= BEDHEAD_MAX) reverseA = true;
	else if (a <= BEDHEAD_MIN) reverseA = false;
	if (b >= BEDHEAD_MAX) reverseB = true;
	else if (b <= BEDHEAD_MIN) reverseB = false;
	if (c >= BEDHEAD_MAX) reverseC = true;
	else if (c <= BEDHEAD_MIN) reverseC = false;
	attractorRotation += 1;
}