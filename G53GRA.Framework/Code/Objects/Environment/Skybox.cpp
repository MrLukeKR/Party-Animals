#include "Skybox.h"
#include "GL\freeglut_ext.h"

/*
Party Animals: Skybox
Author: Luke K. Rose
April 2018
*/

/*
Initialise the skybox with a set of cube map images
*/
Skybox::Skybox(std::string filePath[6]) {
	for (int i = 0; i < 6; i++)
		textureID[i] = Scene::GetTexture(filePath[i]);
}

/*
Draws the object
*/
void Skybox::Display() {
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glTranslatef(pos[0], pos[1], pos[2]);
			glScalef(scale[0], scale[1], scale[2]);
			glRotatef(rotation[1], 0.f, 1.f, 0.f);
			glRotatef(rotation[0], 1.f, 0.f, 0.f);
			glRotatef(rotation[2], 0.f, 0.f, 1.f);

			glColor4f(1, 1, 1, 1); //Set the colour to opaque white
		
			glEnable(GL_TEXTURE_2D);
				glEnable(GL_COLOR_MATERIAL);
					//BACK FACE
					glBindTexture(GL_TEXTURE_2D, textureID[0]);
						glBegin(GL_QUADS);	
							glNormal3f(0,0,1);
								glTexCoord2f(0.0f, 1.0f);
									glVertex3f(-1, 1, -1);
								glTexCoord2f(0.0f, 0.0f);
									glVertex3f(-1, -1, -1);
								glTexCoord2f(1.0f, 0.0f);
									glVertex3f(1, -1, -1);
								glTexCoord2f(1.0f, 1.0f);
									glVertex3f(1, 1, -1);
						glEnd();

					//LEFT FACE
					glBindTexture(GL_TEXTURE_2D, textureID[1]);
						glBegin(GL_QUADS);
							glNormal3f(1, 0, 0);
								glTexCoord2f(0.0f, 1.0f);
									glVertex3f(-1, 1, 1);
								glTexCoord2f(0.0f, 0.0f);
									glVertex3f(-1, -1, 1);
								glTexCoord2f(1.0f, 0.0f);
									glVertex3f(-1, -1, -1);
								glTexCoord2f(1.0f, 1.0f);
									glVertex3f(-1, 1, -1);
						glEnd();

					//FRONT FACE
					glBindTexture(GL_TEXTURE_2D, textureID[2]);
						glBegin(GL_QUADS);
							glNormal3f(0, 0, -1);
								glTexCoord2f(0.0f, 1.0f);
									glVertex3f(1, 1, 1);
								glTexCoord2f(0.0f, 0.0f);
									glVertex3f(1, -1, 1);
								glTexCoord2f(1.0f, 0.0f);
									glVertex3f(-1, -1, 1);
								glTexCoord2f(1.0f, 1.0f);
									glVertex3f(-1, 1, 1);
						glEnd();

					//RIGHT FACE	
					glBindTexture(GL_TEXTURE_2D, textureID[3]);
						glBegin(GL_QUADS);
							glNormal3f(-1, 0, 0);
								glTexCoord2f(0.0f, 1.0f);
									glVertex3f(1, 1, -1);
								glTexCoord2f(0.0f, 0.0f);
									glVertex3f(1, -1, -1);
								glTexCoord2f(1.0f, 0.0f);
									glVertex3f(1, -1, 1);
								glTexCoord2f(1.0f, 1.0f);
									glVertex3f(1, 1, 1);
						glEnd();

						//TOP FACE
						glBindTexture(GL_TEXTURE_2D, textureID[4]);
							glBegin(GL_QUADS);
								glNormal3f(0, -1, 0);
									glTexCoord2f(0.0f, 1.0f);
										glVertex3f(-1, 1, 1);
									glTexCoord2f(0.0f, 0.0f);
										glVertex3f(-1, 1, -1);
									glTexCoord2f(1.0f, 0.0f);
										glVertex3f(1, 1, -1);
									glTexCoord2f(1.0f, 1.0f);
										glVertex3f(1, 1, 1);
							glEnd();
				
					//BOTTOM FACE
					glBindTexture(GL_TEXTURE_2D, textureID[5]);
						glBegin(GL_QUADS);		
							glNormal3f(0, 1, 0);
								glTexCoord2f(0.0f, 1.0f);
									glVertex3f(-1, -1, -1);
								glTexCoord2f(0.0f, 0.0f);
									glVertex3f(-1, -1, 1);
								glTexCoord2f(1.0f, 0.0f);
									glVertex3f(1, -1, 1);
								glTexCoord2f(1.0f, 1.0f);
									glVertex3f(1, -1, -1);
						glEnd();
					glBindTexture(GL_TEXTURE_2D, NULL);
				glDisable(GL_COLOR_MATERIAL);
			glDisable(GL_TEXTURE_2D);
		glPopAttrib();
	glPopMatrix();
}