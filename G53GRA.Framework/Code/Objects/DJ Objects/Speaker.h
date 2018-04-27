#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/*
Party Animals: Speaker (Header File)
Author: Luke K. Rose
April 2018
*/

class Speaker :
	public DisplayableObject, 
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Speaker() {};
	~Speaker() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& time);

private:
	/*
	Private methods
	*/
	void drawSpeaker();
	void drawStand();

	/*
	Private variables
	*/
	GLuint texID = Scene::GetTexture("./Textures/speaker.bmp");
	float speakerPump = 1, currentAnimationTime = 0, animationTime = 0.5f;
};

