#include "Monkey.h"
#include "Objects\Box.h"
#include "Objects\PartyHat.h"

void Monkey::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	drawBody();
	glPushMatrix();
		glTranslatef(0, 3, headShift);
		drawHead();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, 1.5f, 2);
		drawLeftArm();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-1, 0, -1.5f);
		drawRightArm();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(2, -1, 0);
		drawTail();
	glPopMatrix();
	glTranslatef(0, -2, 0);
	drawStool();
	glPopAttrib();
	glPopMatrix();
}

void Monkey::drawHead() {
	glPushMatrix();
		glPushMatrix();
			glColor3f(0.545f, 0.271f, 0.075f);
			Box::box(2, 2, 2);
			glTranslatef(-2, 0, 0);
			glColor3f(0.961f, 0.871f, 0.702f);
			Box::box(.2f, 1.5f, 1.5f);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 1, 2.5f);
			drawEar();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 1, -2.5f);
			drawEar();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2,0.5f,-1);
			drawEye();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2, 0.5f, 1);
			drawEye();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-2.15f, -1, 0);
			drawMouth();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			PartyHat* hat = new PartyHat();
			hat->Display();
		glPopMatrix();
		glTranslatef(-2, 0.5f, 0);
		drawSunglasses();
	glPopMatrix();
}

void Monkey::drawTail() {
	glPushMatrix();
		glRotatef(30,0,0,1);
		glRotatef(headShift * 4, 0, 1, 0);
		Box::box(2, 0.1f, 0.1f);
	glPopMatrix();
}

void Monkey::drawMouth() {
	glPushMatrix();
		glColor4f(0, 0, 0, 1);
		Box::box(.1f, .3f, .525f);
	glPopMatrix();
	glTranslatef(-0.1f, 0, 0);
	glPushMatrix();
		glTranslatef(0, 0.25f, 0);
		glColor4f(1, 1, 1, 1);
		Box::box(.1f, .1f, .5f);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, -0.25f, 0);
		glColor4f(1, 1, 1, 1);
		Box::box(.1f, .1f, .5f);
	glPopMatrix();
	glColor4f(1, 0, 0, 1);
	glTranslatef(0, -0.1f, 0);
	Box::box(.1f, .05f, .15f);
}

void Monkey::drawEar() {
	glPushMatrix();
	glColor3f(0.545f, 0.271f, 0.075f);
	Box::box(0.1f, 2, 2);
	glColor3f(0.961f, 0.871f, 0.702f);
	glTranslatef(-1,0,0);
	Box::box(0.1f, 1, 1);
	glPopMatrix();
}

void Monkey::drawStool() {
	glDisable(GL_LIGHTING);
	glColor4f(0, 0, 1, 1);
	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		GLUquadric* quad = gluNewQuadric();
		gluCylinder(quad, 2, 2, 0.2f, 10, 10);
		glTranslatef(0, -0.1f, 0);
		for (int i = -1; i <= 1; i += 2) {
			glPushMatrix();
				glRotatef(i * 180, 1, 0, 0);
				glTranslatef(0, i * 0.1f, 0);
				gluDisk(quad, 0, 2, 10, 10);
			glPopMatrix();
		}
		glTranslatef(0, -0.1f, 0);
		glRotatef(-90, 1, 0, 0);
		glRotatef(-30, 0, 1, 0);
		for (int i = 0; i < 3; i++) {
			glRotatef(120, 0, 1, 0);
			glPushMatrix();
				glRotatef(70, 1, 0, 0);
				gluCylinder(quad, 0.3f, 0.25f, 8, 5, 5);
			glPopMatrix();
		}
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void Monkey::drawBody() {
	glPushMatrix();
	glColor3f(0.545f, 0.271f, 0.075f);
	Box::box(1, 2, 1.5f);
	glTranslatef(-1, 0, 0);
	glColor3f(0.961f, 0.871f, 0.702f);
	Box::box(.1f, 1.5f, 1);
	glPopMatrix();
}

void Monkey::drawSunglasses() {
	glPushMatrix();
	glColor4f(0.f, 0.f, 0.f, .25f);
	Box::box(.85f, .85f, 1.8f);
	glPopMatrix();
}

void Monkey::drawEye() {
	glPushMatrix();
	glColor4f(0.f, 0.f, 0.f, 1.f);
	Box::box(.325f, .325f, .325f);
	glPopMatrix();
}

void Monkey::drawRightArm() {
	glPushMatrix();
	glRotatef(shoulderRotation, 0, 1, 0);
	glRotatef(70, -1, 0, 0);
	glColor3f(0.545f, 0.271f, 0.075f);
	Box::box(0.2f, 1, 0.2f);
	glTranslatef(0, -2.15f, .5f);
	glRotatef(-20, 1, 0, 0);
	glRotatef(elbowRotation, 0, 1, 0);
	Box::box(0.2f, 1.5f, 0.2f);
	glPopMatrix();
}

void Monkey::drawLeftArm() {
	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glRotatef(-40, 1, 0, 0);
	glColor3f(0.545f, 0.271f, 0.075f);
	Box::box(0.2f, 1.5f, 0.2f);
	glPopMatrix();
}

void Monkey::Update(const double& dT) {
	currentAnimationTime = fmod(currentAnimationTime + dT, animationTime);

	if (reverseShift) headShift -= 0.4f;
	else headShift += 0.2f;

	if (headShift >= 1)
		reverseShift = true;
	else if (headShift <= -1)
		reverseShift = false;

	float animationStage = 6.f * currentAnimationTime / animationTime;

	if (animationStage < 1.f || animationStage > 6.f)
	{
		elbowRotation = 0;
		shoulderRotation = -80;
	}
	else if (animationStage < 2.f || animationStage > 5.f)
	{
		elbowRotation = -10;
		shoulderRotation = -90;
	}
	else if (animationStage < 3.f || animationStage > 4.f)
	{
		elbowRotation = -20;
		shoulderRotation = -100;
	}
}