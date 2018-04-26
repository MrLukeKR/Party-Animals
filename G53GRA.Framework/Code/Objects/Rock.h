#pragma once
#include "DisplayableObject.h"

class Rock : 
	public DisplayableObject
{
public:
	Rock(const char* textureFile);
	~Rock() {};

	void Display();

private:
	GLuint texID;
	float rockSize = 5.f + (float)rand() / (float)RAND_MAX * 10.f;
};

