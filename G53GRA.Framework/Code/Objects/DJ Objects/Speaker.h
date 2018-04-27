#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Speaker :
	public DisplayableObject, 
	public Animation
{
public:
	Speaker() {};
	~Speaker() {};
	void Display();
	void Update(const double& time);

private:
	void drawSpeaker();
	void drawStand();

	GLuint texID = Scene::GetTexture("./Textures/speaker.bmp");
	float speakerPump = 1, currentAnimationTime = 0, animationTime = 0.5f;
};

