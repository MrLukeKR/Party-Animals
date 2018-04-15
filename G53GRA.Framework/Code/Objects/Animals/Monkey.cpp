#include "Monkey.h"
#include "Objects\Box.h"

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
	glTranslatef(0, 3, 0);
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
	glTranslatef(-2, 0.5f, 0);
	drawSunglasses();
	glPopMatrix();
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
	glColor4f(0.f, 1.f, 1.f, .25f);
	Box::box(.85f, .85f, 1.8f);
	glPopMatrix();
}

void Monkey::drawEye() {
	glPushMatrix();
	glColor4f(0.f, 0.f, 0.f, 1.f);
	Box::box(.75f, .75f, .75f);
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