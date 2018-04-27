#include "Box.h"

/*
Party Animals: Box
Author: Luke K. Rose
April 2018
*/

/*
Draw a cube given the x, y, and z values entered into the method (no texture)
*/
void Box::box(float sx, float sy, float sz) {
	Box::box(sx, sy, sz, NULL);
}

/*
Draw a cube given the x, y, and z values entered into the method (with texture)
*/
void Box::box(float sx, float sy, float sz, GLuint texID)
{
	glPushMatrix();
		glScalef(sx, sy, sz);  //Scale solid cube by size parameters
		glEnable(GL_TEXTURE_2D);
			glEnable(GL_COLOR_MATERIAL);
				glBindTexture(GL_TEXTURE_2D, texID);
					//FRONT FACE
					glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
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
					glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
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
					glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
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
					glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
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
					glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
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
					glBegin(DEBUG ? GL_LINE_LOOP : GL_QUADS);
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
				glBindTexture(GL_TEXTURE_2D, NULL);
			glDisable(GL_COLOR_MATERIAL);		
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}