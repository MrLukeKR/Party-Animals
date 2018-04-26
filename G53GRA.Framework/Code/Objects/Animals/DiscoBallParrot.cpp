#include "DiscoBallParrot.h"
#include "Objects\Box.h"
#include "Objects\PartyHat.h"

#define NUMBER_OF_RAYS 50
#define ALTITUDE_RANGE 2
#define ALTITUDE_CHANGE_FREQUENCY 0.1f
#define FEATHER_SEGMENT_LENGTH 0.75f

DiscoBallParrot::DiscoBallParrot() {
	degree = new float[NUMBER_OF_RAYS];
	x = new float[NUMBER_OF_RAYS];
	y = new float[NUMBER_OF_RAYS];
	z = new float[NUMBER_OF_RAYS];

		for (int i = 0; i < NUMBER_OF_RAYS; i++) {
			degree[i] = rand();
			x[i] = rand();
			y[i] = rand();
			z[i] = rand();
		}

	discoBallTex = Scene::GetTexture("./Textures/discoball.bmp");
}

void DiscoBallParrot::Display() {
	glPushMatrix();
			glPushAttrib(GL_ALL_ATTRIB_BITS);
				glTranslatef(pos[0], pos[1] + altitudeChange, pos[2]);
				glScalef(scale[0], scale[1], scale[2]);
				glRotatef(rotation[0], 1.f, 0.f, 0.f);
				glRotatef(rotation[1], 0.f, 1.f, 0.f);
				glRotatef(rotation[2], 0.f, 0.f, 1.f);
				
				glPushMatrix();
					glTranslatef(0, 5, 0);
					glRotatef(-10, 0, 0, 1);
					drawParrot();
				glPopMatrix();
				glTranslatef(-.5f, 0, 0);
				drawString();
				glTranslatef(0, -5, 0);
					drawDiscoBall();
			glPopAttrib();
	glPopMatrix();
}

void DiscoBallParrot::drawString() {
	glPushMatrix();
		glColor4f(1, 1, 1, 1);
		glBegin(GL_LINE_LOOP);
			glVertex3f(0, 2, 0);
			glVertex3f(0, -2, 0);
		glEnd();
	glPopMatrix();
}

void DiscoBallParrot::drawBody() {
	glPushMatrix();
	glColor4f(1, 0, 0, 1);
	Box::box(1, 2, 1);
	glPopMatrix();
}

void DiscoBallParrot::drawParrot() {
	glPushMatrix();
		drawBody();
		glPushMatrix();
			glTranslatef(0, -3, 0);
			drawFeet();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1, -1.5f, 0);
			glRotatef(-30, 0,0,1);
			drawTailFeathers();
		glPopMatrix();
		glPushMatrix();
			glRotatef(90, 0, 1, 0);
			glTranslatef(-1,0,0);
			drawWing(false);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-90, 0, 1, 0);
			glTranslatef(-1, 0, 0);
			drawWing(true);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(1, 2.5f, 0);
			drawHead();
		glPopMatrix();
	glPopMatrix();
}

void DiscoBallParrot::drawFeet() {
	glColor4f(0.3f, 0.3f, 0.3f, 1);
	glPushMatrix();
		glPushMatrix();
			glTranslatef(0, 0, 0.5f);
			glRotatef(10, 1, 0, 0);
			Box::box(0.1f, 1, 0.1f);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 0, -0.5f);
			glRotatef(-10, 1, 0, 0);
			Box::box(0.1f, 1, 0.1f);
		glPopMatrix();
	glPopMatrix();
}

void DiscoBallParrot::drawHead() {
	glPushMatrix();
		glColor4f(1, 0, 0, 1);
		Box::box(0.75f, 0.75f, 0.75f);
		glTranslatef(0.3f, 0, 0);
		glColor4f(1, 1, 1, 1);
		Box::box(0.5f, 0.5f, 0.8f);
		glPushMatrix();
			glTranslatef(0, 0, 1);
			glColor4f(0, 0, 0, 1);
			Box::box(0.1f, 0.1f, 0.1f);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, -1);
		glColor4f(0, 0, 0, 1);
		Box::box(0.1f, 0.1f, 0.1f);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(.5f, 0, 0);
			drawBeak();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 1, 0);
			glPushMatrix();
				glTranslatef(0, -0.5f, 0.5f);
				glRotatef(30, 1, 0, 0);
				PartyHat* hat = new PartyHat();
				hat->Display();
			glPopMatrix();
			glScalef(0.5f, 0.5f, 0.5f);
			glRotatef(90, 0, 1, 0);
			glRotatef(180, 1, 0, 0);
			glPushMatrix();
				drawFeather();
			glPopMatrix();
			glRotatef(-30, 1, 0, 0);
			glScalef(0.8f, 0.8f, 0.8f);
			glPushMatrix();
				drawFeather();
			glPopMatrix();
			glRotatef(-30, 1, 0, 0);
			glScalef(0.8f, 0.8f, 0.8f);
			glPushMatrix();
				drawFeather();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void DiscoBallParrot::drawBeak() {
	glPushMatrix();
	glColor4f(0, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0.5f, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.5f, 0, -0.25f);
	glVertex3f(0.75f, -0.5f, 0);
	glVertex3f(1, 0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.5f, 0, 0.25f);
	glVertex3f(1, 0, 0);
	glVertex3f(0.75f, -0.5f, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0.5f, 0);
	glVertex3f(0, 0, -0.5f);
	glVertex3f(1, 0, 0);
	glEnd();

	glPopMatrix();
}

void DiscoBallParrot::drawWing(bool invert) {
	glRotatef(invert ? -wingAngle / 4.0f : wingAngle / 4.0f, 1, 0, 0);
	glRotatef(wingAngle, 0, 0, 1);
	glPushMatrix();
		glRotatef(-90, 0, 0, 1);
		glPushMatrix();
			drawFeather();
		glPopMatrix();
		glPushMatrix();
			invert ? glRotatef(-10, 1, 0, 0) : glRotatef(10, 1, 0, 0);
			glRotatef(10, 0, 0, 1);
			glScalef(0.8f, 0.8f, 0.8f);
			drawFeather();
		glPopMatrix();
		glPushMatrix();
			invert ? glRotatef(-20, 1, 0, 0) : glRotatef(20, 1, 0, 0);
			glRotatef(20, 0, 0, 1);
			glScalef(0.5f, 0.5f, 0.5f);
			drawFeather();
		glPopMatrix();
	glPopMatrix();
}

void DiscoBallParrot::drawTailFeathers() {
	glRotatef(wingAngle / 8.0f, 0, 0, 1);
	glPushMatrix();
		glPushMatrix();
			drawFeather();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 0, -0.65f);
			glRotatef(5, 1, 0, 0);
			drawFeather();
		glPopMatrix();
		glTranslatef(0, 0, 0.65f);
		glRotatef(-5, 1, 0, 0);
		drawFeather();
	glPopMatrix();
}

void DiscoBallParrot::drawFeather() {
	glColor4f(1, 0, 0, 1);
	Box::box(.1f, FEATHER_SEGMENT_LENGTH, 1.0f / 3.0f);
	glColor4f(0, 1, 0, 1);
	glTranslatef(0, -FEATHER_SEGMENT_LENGTH * 2, 0);
	Box::box(.1f, FEATHER_SEGMENT_LENGTH, 1.0f / 3.0f);
	glColor4f(0, 0, 1, 1);
	glTranslatef(0, -FEATHER_SEGMENT_LENGTH * 2, 0);
	Box::box(.1f, FEATHER_SEGMENT_LENGTH, 1.0f / 3.0f);
	glColor4f(1, 1, 0, 1);
	glTranslatef(0, -FEATHER_SEGMENT_LENGTH * 2, 0);
	Box::box(.1f, FEATHER_SEGMENT_LENGTH, 1.0f / 3.0f);
}

void DiscoBallParrot::Update(const double& dT) {
	currentAnimationTime += dT;
	discoBallRotation += .25f;

	wingAngle += reverseFlap ? -10 : 10;

	if (wingAngle >= 70)
		reverseFlap = true;
	else if (wingAngle <= -70)
		reverseFlap = false;

	if (altitudeChange >= ALTITUDE_RANGE)
		reverseAltitude = true;
	else if (altitudeChange <= -ALTITUDE_RANGE)
		reverseAltitude = false;

	altitudeChange += reverseAltitude ? -ALTITUDE_CHANGE_FREQUENCY : ALTITUDE_CHANGE_FREQUENCY;

	for (int i = 0; i < NUMBER_OF_RAYS; i++) 
		degree[i] = degree[i] + ((float) rand() / (float) RAND_MAX * 0.01f);
}

void DiscoBallParrot::drawDiscoBall() {
	glColor4f(0.8f, 0.8f, 0.8f, 1);
	glPushMatrix();
	glRotatef(discoBallRotation, 0, 1, 0);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, discoBallTex);
	GLUquadric* quadric = gluNewQuadric();
	gluQuadricNormals(quadric, GLU_SMOOTH);
	gluQuadricTexture(quadric, GL_TRUE);
	gluSphere(quadric,3, 8, 8);
	glDisable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);

	drawRays();
	glPopMatrix();
}

void DiscoBallParrot::drawRays() {
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		glColor4f(1, 1, 1, 0.1f);
		for (int i = 0; i < NUMBER_OF_RAYS; i++) {
			glRotatef(degree[i], x[i], y[i], z[i]);
			glPushMatrix();
				glBegin(GL_TRIANGLES);
					glVertex3f(0, 0, 0);
					glVertex3f(0, 100, 10);
					glVertex3f(0, 100 * 2, 5);
				glEnd();
			glPopMatrix();
			glPushMatrix();
				glBegin(GL_TRIANGLES);
					glVertex3f(0, 0, 0);
					glVertex3f(0, 100 * 2, 5);
					glVertex3f(0, 100 * 2, 10);
				glEnd();
			glPopMatrix();
		}
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}