#include "Giraffe.h"



Giraffe::Giraffe()
{
	giraffeTex = Scene::GetTexture("./Textures/giraffe.bmp");
	neckAngle = -15.f;
	headAngle = -90.f;
}


Giraffe::~Giraffe()
{
}

void Giraffe::drawGiraffe() {
	glPushMatrix();
	drawBody();
	glPushMatrix();
	glTranslatef(-1.5f, 0, .0f);
	drawTail();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.9f, 0, .4f);
	drawLeg();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.9f, 0, .4f);
	drawLeg();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.9f, 0, -.4f);
	drawLeg();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.9f, 0, -.4f);
	drawLeg();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.65f, 0.f, 0.f);
	glRotatef(neckAngle, 0.f, 0, 1.f);
	glRotatef(neckSpinAngle, 1.f, 0, 0.f);
	drawNeck();
	glTranslatef(0.f, neckHeight, 0.f);
	glPushMatrix();

	glRotatef(headAngle, 0, 0, 1.f);
	drawHead();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Giraffe::drawTail() {
	glPushMatrix();
	glTranslatef(0.35f, -0.25f, 0.f);
	glRotatef(-10, 0, 0, 1);
	glColor3f(1.f, 1.f, 0.f);
	box(0.05f, 0.5f, 0.05f, giraffeTex);
	glPopMatrix();
}

void Giraffe::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glScalef(5, 5, 5);
	drawGiraffe();

	glPopAttrib();
	glPopMatrix();
}

void Giraffe::Update(const double& dT) {
	currentAnimationTime = fmod(currentAnimationTime + dT, animationTime);

	float animationStage = 14.f * currentAnimationTime / animationTime;

	if (animationStage < 1.f || animationStage > 14.f)
	{
		neckAngle = -15.f;
		headAngle = -90.f;
		neckSpinAngle = -15.f;
	}
	else if(animationStage < 2.f || animationStage > 13.f)
	{
		neckAngle = -20.f;
		headAngle = -85.f;
		neckSpinAngle = -10.f;
	}
	else if (animationStage < 3.f || animationStage > 12.f)
	{
		neckAngle = -25.f;
		headAngle = -80.f;
		neckSpinAngle = -5.f;

	}
	else if (animationStage < 4.f || animationStage > 11.f)
	{
		neckAngle = -30.f;
		headAngle = -75.f;
		neckSpinAngle = 0.f;
	}
	else if (animationStage < 5.f || animationStage > 10.f)
	{
		neckAngle = -25.f;
		headAngle = -80.f;
		neckSpinAngle = 5.f;
	}
	else if (animationStage < 6.f || animationStage > 9.f) {
		neckAngle = -20.f;
		headAngle = -85.f;
		neckSpinAngle = 10.f;
	}
	else if (animationStage < 7.f || animationStage > 8.f) {
		neckAngle = -15.f;
		headAngle = -90.f;
		neckSpinAngle = 15.f;
	}
}

void Giraffe::drawHead() {
	glTranslatef(0.f, 0.3f, 0.f);
	box(0.3f, 0.5f, 0.3f, giraffeTex);
}

void Giraffe::drawBody() {
	//Giraffe's Main Body
	glColor3f(1.f, 1.f, 0.f);
	box(1.11f, .5f, .65f, giraffeTex);
}

void Giraffe::drawNeck() {
	glTranslatef(0.f, 2.225f, 0.f);
	glColor3f(1.f, 1.f, 0.f);
	box(0.2f, neckHeight, 0.2f, giraffeTex);
}

void Giraffe::drawLeg() {
	glTranslatef(0.f, -1.f, 0.f);
	glColor3f(1.f, 1.f, 0.f);
	box(0.2f, 1, 0.2f, giraffeTex);
}

void Giraffe::box(float sx, float sy, float sz, GLuint texID)
{
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	//glDisable(GL_LIGHTING);

	glBindTexture(GL_TEXTURE_2D, texID);

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
			glVertex3f(-1,1,-1); //LEFT-TOP-BACK
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

	glDisable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);
														//glutSolidCube(1.f);
	glPopMatrix();
}