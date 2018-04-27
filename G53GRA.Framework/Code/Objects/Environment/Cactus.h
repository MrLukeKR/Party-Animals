#pragma once
#include "DisplayableObject.h"

class Cactus :
	public DisplayableObject
{
public:
	Cactus();
	~Cactus() { delete[] armRotation;  };
	void Display();

private:
	GLuint cactusTex = Scene::GetTexture("./Textures/cactus.bmp");;
	float height = (float)rand() / (float)RAND_MAX * 7 + 3;
	float* armRotation;
};