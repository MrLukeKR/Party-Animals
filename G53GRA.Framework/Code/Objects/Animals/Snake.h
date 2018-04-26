#pragma once

#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Snake :
	public DisplayableObject,
	public Animation
{
public:
	Snake() ;
	~Snake() {};

	void Display();
	void Update(const double& dT);

private:
	void drawHead();
	void drawEye();
	void drawTongue();

	GLuint snakeTex;
	float frequency = 10;
	int offset = 0;
};