#include "Lion.h"
#include "../Box.h"
#include "Objects\PartyHat.h"

void Lion::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);
			glTranslatef(moonwalkX, 0, 0);
			glRotatef(moonwalkRotation, 0,1, 0);
			drawBody();
			glPushMatrix();
			glTranslatef(-5, 0, 0);
			glRotatef(wiggle, 1, 0, 0);
			drawTail();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0, -2.5f, 0);
				glPushMatrix();
					glTranslatef(4.5f, 0, 1);
					glTranslatef(legAngle / 30.f,0,0);
					glRotatef(legAngle, 0, 0, 1);
					drawLeg();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(4.5f, 0, -1);
					glTranslatef(-legAngle / 30.f, 0, 0);
					glRotatef(-legAngle, 0, 0, 1);
					drawLeg();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-4.5f, 0, 1);
					glTranslatef(-legAngle / 30.f, 0, 0);
					glRotatef(-legAngle, 0, 0, 1);
					drawLeg();
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-4.5f, 0, -1);
					glTranslatef(legAngle / 30.f, 0, 0);
					glRotatef(legAngle, 0, 0, 1);
					drawLeg();
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(5, 1, 0);
				drawHead();
			glPopMatrix();
		glPopAttrib();
	glPopMatrix();
}

void Lion::drawBody() {
	glPushMatrix();
		Box::box(5, 1.25f, 1.5f, lionTex);
	glPopMatrix();
}

void Lion::drawLeg() {
	glColor4f(1, 1, 1, 1);
	glPushMatrix();
		Box::box(.5f, 1.75f, .5f, lionTex);
	glPopMatrix();
}

void Lion::drawHead() {
	glPushMatrix();
		glColor4f(0.4f, 0, 0, 1);
		Box::box(2, 2, 2, lionTex);
		glTranslatef(1, 0, 0);
		glColor4f(1, 1, 1, 1);
		Box::box(1.25f, 1.25f, 1.25f, lionTex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 2, 0);
	PartyHat* hat = new PartyHat();
	hat->Display();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(2.25f, 0.25f, 0);
		for (int i = -1; i <= 1; i += 2) {
			glPushMatrix();
				glTranslatef(0,0,i * 0.5f);
				drawEye();
			glPopMatrix();
		}
	glPopMatrix();
	glPushMatrix();
		glTranslatef(2.25f, -0.75f, 0);
		drawMouth();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.75f, 1, 0);
	for (int i = -1; i <= 1; i += 2) {
		glPushMatrix();
		glTranslatef(0, 0, i *2);
		glRotatef((-35 + wiggle) * i, 1, 0, 0);
		drawEar();
		glPopMatrix();
	}
	glPopMatrix();
}

void Lion::drawTail() {
	glPushMatrix();
	glRotatef(-10, 0, 0, 1);
	glTranslatef(0, -0.5f, 0);
	Box::box(.1f, 1, .1f, lionTex);
	glTranslatef(0, -1.25f, 0);
	glColor4f(.8f, 0, 0, 1);
	Box::box(.25f, .25f, .25f, lionTex);
	glPopMatrix();
}

void Lion::drawEar() {
	glPushMatrix();
	glColor4f(1, 1, 1, 1);
	Box::box(0.25f,.5f,.5f,lionTex);
	glTranslatef(0.25f, 0, 0);
	glColor4f(.8f, 0, 0, 1);
	Box::box(0.15f, 0.4f, 0.4f, lionTex);
	glPopMatrix();
}

void Lion::drawEye() {
	glPushMatrix();
	glColor4f(0, 0, 0, 1);
	Box::box(0.2f, 0.2f, 0.2f);
	glPopMatrix();
}

void Lion::drawMouth() {
	glPushMatrix();
	glColor4f(0, 0, 0, 1);
	Box::box(0.1f, 0.25f, 0.4f);
	glPushMatrix();
	glTranslatef(0.11f, 0, 0);
	for (int i = -1; i <= 1; i += 2) {
		glPushMatrix();
			glTranslatef(0, 0, i * 0.25f);
			glDisable(GL_LIGHTING);
			glColor4f(1, 1, 1, 1);
			glBegin(GL_TRIANGLES);
				glVertex3f(0,0.25f,.1f);
				glVertex3f(0, -.25f, 0);
				glVertex3f(0, 0.25f, -.1f);
			glEnd();
			glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glPopMatrix();
	glTranslatef(0.05f, -.1f, 0);
	glColor4f(1, 0, 0, 1);
	Box::box(0.1f, 0.1f, 0.1f);
	glPopMatrix();
}

void Lion::Update(double const& dT) {
	legAngle += reverseLeg ? -4 : 4;
	if (legAngle >= 30)
		reverseLeg = true;
	else if (legAngle <= -30)
		reverseLeg = false;

	wiggle += reverseWiggle ? -3 : 3;
	if (wiggle >= 15)
		reverseWiggle = true;
	else if (wiggle <= -15)
		reverseWiggle = false;

	if (!enableSpin) {
	moonwalkX += reverseMoonWalk ? .5f : -.5f;
	if (moonwalkX <= -MOONWALK_RANGE) {
		reverseMoonWalk = true;
		enableSpin = true;
	}
	else if (moonwalkX >= MOONWALK_RANGE) {
		reverseMoonWalk = false;
		enableSpin = true;
	}
}
else {
		moonwalkRotation += 30;
		if (moonwalkRotation >= 360 + ((moonwalkX >= 0) ? 360 : 180)) {
			enableSpin = false;
			if(moonwalkX < 0)
				moonwalkRotation = 180;
			else
				moonwalkRotation = 0;
		}
	}
}