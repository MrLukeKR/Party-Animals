#include "Speaker.h"
#include "Objects\Box.h"

void Speaker::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			drawSpeaker();
			glTranslatef(0, -3, 0);
			drawStand();
		glPopAttrib();
	glPopMatrix();
}

void Speaker::Update(const double& time) {
	currentAnimationTime = fmod(currentAnimationTime + time, animationTime);

	float animationStage = 6.f * currentAnimationTime / animationTime;

	speakerPump = 1 + animationStage * 0.05f;
}

void Speaker::drawSpeaker() {
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_COLOR_MATERIAL);
		glBindTexture(GL_TEXTURE_2D, texID);

		glScalef(speakerPump, speakerPump, speakerPump);
		Box::box(1.5f, 3, 1.5f, texID);

		glDisable(GL_COLOR_MATERIAL);
		glBindTexture(GL_TEXTURE_2D, NULL);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Speaker::drawStand() {
	glDisable(GL_LIGHTING);
	glColor4f(0.2f, 0.2f, 0.2f, 1);
	glPushMatrix();
		glRotatef(90, 1, 0, 0);
		gluCylinder(gluNewQuadric(), .25f, .25f, 3.5f, 5, 5);
	glPopMatrix();
	glTranslatef(0, -3, 0);
	for (int i = 0; i < 3; i++) {
		glRotatef(120, 0, 1, 0);
		glPushMatrix();
			glRotatef(45, 1, 0, 0);
			gluCylinder(gluNewQuadric(), .25f, .25f, 5, 5, 5);
		glPopMatrix();
	}
	glEnable(GL_LIGHTING);
}