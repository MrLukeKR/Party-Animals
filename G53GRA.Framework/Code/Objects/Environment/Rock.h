#pragma once

#include "DisplayableObject.h"

/*
Party Animals: Rock (Header File)
Author: Luke K. Rose
April 2018
*/

class Rock : 
	public DisplayableObject
{
public:
	/*
	Public Constructor/Destructor
	*/
	Rock(const char* textureFile);
	~Rock() {};

	/*
	Public methods
	*/
	void Display();

private:
	/*
	Private variables
	*/
	GLuint texID;
	float rockSize = 5.f + (float)rand() / (float)RAND_MAX * 10.f;
};

