#include "Speaker.h"

Speaker::Speaker()
{
	texID = Scene::GetTexture("./Textures/speaker.bmp");
}


Speaker::~Speaker()
{
}

void Speaker::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	drawSpeaker();

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
	//glDisable(GL_LIGHTING);

	glBindTexture(GL_TEXTURE_2D, texID);

		glPushMatrix();

		glScalef(speakerPump, speakerPump, speakerPump);
	glScalef(1.5f,3,1.5f);

	//FRONT FACE
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2d(1, 1);
	glVertex3f(1, 1, 1); //RIGHT-TOP-FRONT
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, 1); //LEFT-TOP-FRONT
	glTexCoord2d(0, 0);
	glVertex3f(-1, -1, 1); //LEFT-BOTTOM-FRONT
	glTexCoord2d(1, 0);
	glVertex3f(1, -1, 1); //RIGHT-BOTTOM-FRONT
	glEnd();

	//LEFT FACE
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, 1); //LEFT-TOP-FRONT
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -1); //LEFT-TOP-BACK
	glTexCoord2d(0, 0);
	glVertex3f(-1, -1, -1); //LEFT-BOTTOM-BACK
	glTexCoord2d(1, 0);
	glVertex3f(-1, -1, 1); //LEFT-BOTTOM-FRONT
	glEnd();

	//BACK FACE
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -1); //LEFT-TOP-BACK	
	glTexCoord2d(0, 1);
	glVertex3f(1, 1, -1); //RIGHT-TOP-BACK
	glTexCoord2d(0, 0);
	glVertex3f(1, -1, -1); //RIGHT-BOTTOM-BACK
	glTexCoord2d(1, 0);
	glVertex3f(-1, -1, -1); //LEFT-BOTTOM-BACK
	glEnd();

	//RIGHT FACE
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1, 1, -1); //RIGHT-TOP-BACK
	glTexCoord2d(0, 1);
	glVertex3f(1, 1, 1); //RIGHT-TOP-FRONT
	glTexCoord2d(0, 0);
	glVertex3f(1, -1, 1); //RIGHT-BOTTOM-FRONT
	glTexCoord2d(1, 0);
	glVertex3f(1, -1, -1); //RIGHT-BOTTOM-BACK
	glEnd();

	//TOP FACE
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1, 1, -1); //RIGHT-TOP-BACK
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -1); //LEFT-TOP-BACK
	glTexCoord2d(0, 0);
	glVertex3f(-1, 1, 1); //LEFT-TOP-FRONT
	glTexCoord2d(1, 0);
	glVertex3f(1, 1, 1); //RIGHT-TOP-FRONT
	glEnd();

	//BOTTOM FACE
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2d(1, 1);
	glVertex3f(1, -1, 1); //RIGHT-BOTTOM-FRONT
	glTexCoord2d(0, 1);
	glVertex3f(-1, -1, 1); //LEFT-BOTTOM-FRONT
	glTexCoord2d(0, 0);
	glVertex3f(-1, -1, -1); //LEFT-BOTTOM-BACK
	glTexCoord2d(1, 0);
	glVertex3f(1, -1, -1); //RIGHT-BOTTOM-BACK
	glEnd();


		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, -3, 0);
		glRotatef(90, 1, 0,0);

		gluCylinder(gluNewQuadric(),.25f,.25f,3.5f,5,5);
		glPopMatrix();
		glTranslatef(0, -6, 0);
		glPushMatrix();
		glRotatef(45, 1, 0, 0);
		gluCylinder(gluNewQuadric(), .25f, .25f, 5, 5, 5);
		glPopMatrix();
		glPushMatrix();
		glRotatef(120, 0, 1, 0);
		glRotatef(45, 1, 0, 0);
		gluCylinder(gluNewQuadric(), .25f, .25f, 5, 5, 5);
		glPopMatrix();
		glPushMatrix();
		glRotatef(-120, 0, 1, 0);
		glRotatef(45, 1, 0, 0);
		gluCylinder(gluNewQuadric(), .25f, .25f, 5, 5, 5);
		glPopMatrix();
	glDisable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


}