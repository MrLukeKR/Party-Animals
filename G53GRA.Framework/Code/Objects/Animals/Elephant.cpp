#include "Elephant.h"
#include "Objects\Box.h"
#include "Objects\PartyHat.h"

void Elephant::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
	
			glColor4f(0.3f, 0.3f, 0.3f, 1);
	
			drawBody();
	
			glPushMatrix();
				glTranslatef(-6, -7, 4);
				drawLeg();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(6, -7, 4);
				drawLeg();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(6, -7, -4);
				drawLeg();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-6, -7, -4);
				drawLeg();
			glPopMatrix();
				glTranslatef(9, 5, 0);
				drawHead();
		glPopAttrib();
	glPopMatrix();
}

void Elephant::drawBody() {
	Box::box(7, 5, 5, elephantTex);
}

void Elephant::drawLeg() {
	Box::box(1, 3, 1, elephantTex);
}

void Elephant::drawEyes() {
	glColor3f(0, 0, 0);
	glPushMatrix();
		glPushMatrix();
			glTranslatef(3,1,1.5f);
			Box::box(0.5f, 0.5f, 0.5f, elephantTex);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(3, 1, -1.5f);
			Box::box(0.5f, 0.5f, 0.5f, elephantTex);
		glPopMatrix();
	glPopMatrix();
}

void Elephant::drawHead() {
	glPushMatrix();
		Box::box(3, 3, 3, elephantTex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(4, 0, 0);
		glPushMatrix();
			drawTusks();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, -4.5f, 0);
			glRotatef(-65, 0, 0, 1);
			drawTrunk();
		glPopMatrix();
		glTranslatef(-4, 0, 0);
		glPushMatrix();
			drawEyes();
		glPopMatrix();
		glPushMatrix();
			drawEars();
		glPopMatrix();
		glTranslatef(0, 3, 0);
		glScalef(2, 2, 2);
		PartyHat* hat = new PartyHat();
		hat->Display();
	glPopMatrix();
}

void Elephant::drawTrunk() {
	glColor3f(0.3f, 0.3f, 0.3f);
	glPushMatrix();
	glTranslatef(0, animationAngle / 15.f, 0);
	glRotatef(animationAngle, 0, 0, 1);
		Box::box(4, 0.75f, 0.75f, elephantTex);
	glPopMatrix();
}

void Elephant::drawTusks() {
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
		glTranslatef(0, -1.5f, 2);
		glRotatef(-45, 0, 0, 1);
		glRotatef(-25, 0, 1, 0);
		Box::box(2, 0.5f, 0.5f);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, -1.5f, -2);
		glRotatef(-45, 0, 0, 1);
		glRotatef(25, 0, 1, 0);
		Box::box(2, 0.5f, 0.5f);
	glPopMatrix();
}

void Elephant::drawEars() {
	glColor3f(0.3f, 0.3f, 0.3f);
	glPushMatrix();
		glTranslatef(0,3,3);
		glRotatef(-45 - animationAngle,0,1,0);
		Box::box(0.1f, 2, 2, elephantTex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, 3, -3);
		glRotatef(45 + animationAngle, 0, 1, 0);
		Box::box(0.1f, 2, 2, elephantTex);
	glPopMatrix();
}

void Elephant::Update(const double& dT) {
	animationAngle += reverseAnimation ? -5 : 5;

	if (animationAngle >= 45)
		reverseAnimation = true;
	else if (animationAngle <= -45)
		reverseAnimation = false;
} 