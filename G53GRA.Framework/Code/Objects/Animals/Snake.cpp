#include "Snake.h"

#define CALC_X cos((x + offset) / 10.0f)
#define CALC_Y sin((x + offset) / 10.0f)
#define CALC_Z (x / 10.0f)
#define SCALE .25f

Snake::Snake() {
	snakeTex = Scene::GetTexture("./Textures/snake.bmp");
}

void Snake::Display() {
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.f, 0.f, 0.f);
	glRotatef(rotation[1], 0.f, 1.f, 0.f);
	glRotatef(rotation[2], 0.f, 0.f, 1.f);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, snakeTex);
	
	
	GLUquadric* quadric = gluNewQuadric();
	gluQuadricTexture(quadric, true);

	glPushMatrix();

	for (int x = 0; x <= 360; x++) {
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
	
	//glTranslatef(0, segmentPos[0],0);
	//gluCylinder(quadric, 1,1,5,10,10);
	

	glDisable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
	glPopMatrix();
}

void Snake::Update(const double& dT) {
	offset++;
}