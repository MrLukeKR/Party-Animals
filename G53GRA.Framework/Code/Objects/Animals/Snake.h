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
	GLuint snakeTex;
	float segmentPos[5] = {0};
	int offset = 0;
};