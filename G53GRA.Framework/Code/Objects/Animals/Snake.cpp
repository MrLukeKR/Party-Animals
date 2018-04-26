#include "Snake.h"
#include "Objects\PartyHat.h"
#include "Objects\Box.h"

#define CALC_X cos((x + offset) / 10.0f)
#define CALC_Y sin((x + offset) / 10.0f)
#define CALC_Z (x / frequency)
#define SCALE .25f

Snake::Snake() {
	snakeTex = Scene::GetTexture("./Textures/snake.bmp");
}

void Snake::drawEye() {
	glPushMatrix();
		glColor4f(0.f, 0.f, 0.f, 1.f);
		Box::box(.2f, .2f, .2f);
	glPopMatrix();
}

void Snake::drawHead() {
	glPushMatrix();
	glTranslatef(0, 0.75f, 0);
		Box::box(0.5f, 0.5f, 0.75f, snakeTex);
		glPushMatrix();
			glTranslatef(0, 0.5f, 0);
			PartyHat* hat = new PartyHat();
			hat->size(0.5f, 0.5f, 0.5f);
			hat->Display();
		glPopMatrix();
		for (int i = -1; i <= 1; i += 2) {
			glPushMatrix();
				glTranslatef(i * 0.6f, 0, 0);
				drawEye();
			glPopMatrix();
		}
		glTranslatef(0, 0, abs(sin(offset / 4.f)));
		drawTongue();
	glPopMatrix();
}

void Snake::drawTongue() {
	glPushMatrix();
		glColor4f(1, 0, 0, 1);
		Box::box(0.05f, 0.05f, 0.5f);
		glTranslatef(0, 0, 0.5f);
		for (int i = -1; i <= 1; i += 2) {
			glPushMatrix();
				glTranslatef(i * 0.1f, 0, 0);
				glRotatef(i * 30, 0, 1, 0);
				Box::box(0.05f, 0.05f, 0.1f);
			glPopMatrix();
		}
	glPopMatrix();
}

void Snake::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glPushMatrix();
	glTranslatef(0, 0, 36.75f);
	float x = cos(offset / 10.f);
	float y = sin(offset / 10.f);
	
	float val = atan2(y, x) * 180.f / 3.14159265f - 180;

	
	glRotatef(val, 0, 0, 1);
	drawHead();
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor4f(1, 1, 1, 1);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, snakeTex);

	for (int x = 0; x < 360; x++) {
		//Draw the top of the cube
		glBegin(GL_QUADS);
		glTexCoord2d(1,1);
		glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //RIGHT, TOP, FRONT
		glTexCoord2d(1, 0);
		glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //RIGHT, TOP, BACK
		glTexCoord2d(0, 0);
		glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //LEFT, TOP, BACK
		glTexCoord2d(0, 1);
		glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //LEFT, TOP, FRONT
		glEnd();

		//Draw the bottom of the cube
		glBegin(GL_QUADS);
		glTexCoord2d(1, 1);
		glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //RIGHT, BOTTOM, FRONT
		glTexCoord2d(0, 1);
		glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //LEFT, BOTTOM, FRONT		
		glTexCoord2d(0, 0);
		glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //LEFT, BOTTOM, BACK
		glTexCoord2d(0, 1);
		glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //RIGHT, BOTTOM, BACK
		glEnd();

		//Draw the right of the cube
		glBegin(GL_QUADS);
		glTexCoord2d(1, 1);
		glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //RIGHT, TOP, BACK
		glTexCoord2d(0, 1);
		glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //RIGHT, TOP, FRONT
		glTexCoord2d(0, 0);
		glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //RIGHT, BOTTOM, FRONT
		glTexCoord2d(1, 0);
		glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //RIGHT, BOTTOM, BACK
		glEnd();

		//Draw the left of the cube
		glBegin(GL_QUADS);
		glTexCoord2d(1, 1);
		glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //LEFT, TOP, FRONT
		glTexCoord2d(0, 1);
		glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //LEFT, TOP, BACK
		glTexCoord2d(0, 0);
		glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //LEFT, BOTTOM, BACK
		glTexCoord2d(1, 0);
		glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //LEFT, BOTTOM, FRONT
		glEnd();

		//Draw the front of the cube
		glBegin(GL_QUADS);
		glTexCoord2d(1, 1);
		glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //RIGHT, TOP, FRONT
		glTexCoord2d(0, 1);
		glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z + SCALE); //LEFT, TOP, FRONT
		glTexCoord2d(0, 0);
		glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //LEFT, BOTTOM, FRONT
		glTexCoord2d(1, 0);
		glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z + SCALE); //RIGHT, BOTTOM, FRONT
		glEnd();

		//Draw the back of the cube
		glBegin(GL_QUADS);
		glTexCoord2d(1, 1);
		glVertex3f(CALC_X + SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //LEFT, TOP, BACK
		glTexCoord2d(0, 1);
		glVertex3f(CALC_X + SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //LEFT, BOTTOM, BACK
		glTexCoord2d(0, 0);
		glVertex3f(CALC_X - SCALE, CALC_Y - SCALE, CALC_Z - SCALE); //LEFT, BOTTOM, BACK
		glTexCoord2d(1, 0);
		glVertex3f(CALC_X - SCALE, CALC_Y + SCALE, CALC_Z - SCALE); //LEFT, TOP, BACK
		
		glEnd();
	}

	glPopMatrix();

	glDisable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopMatrix();
}

void Snake::Update(const double& dT) {
	offset++;
}