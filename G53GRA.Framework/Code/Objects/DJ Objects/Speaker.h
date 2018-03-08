#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Speaker :
	public DisplayableObject, public Animation
{
public:
	Speaker();
	~Speaker();
	void Display();
	void Update(const double& time);

private:
	void drawSpeaker();
	float speakerPump = 1;
	float currentAnimationTime = 0;
	float animationTime = 0.5f;
};

