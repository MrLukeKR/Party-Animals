#pragma once

#include "DisplayableObject.h"

/*
Party Animals: Cactus (Header File)
Author: Luke K. Rose
April 2018
*/

class Cactus :
	public DisplayableObject
{
public:
	/*
	Public Constructor/Destructor
	*/
	Cactus();
	~Cactus() { delete[] armRotation;  };
	
	/*
	Public methods
	*/
	void Display();

private:
	/*
	Private variables
	*/
	GLuint cactusTex = Scene::GetTexture("./Textures/cactus.bmp");;
	float height = (float)rand() / (float)RAND_MAX * 7 + 3;
	float* armRotation;
};