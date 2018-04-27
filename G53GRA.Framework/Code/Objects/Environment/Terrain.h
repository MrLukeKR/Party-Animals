#pragma once
#include "DisplayableObject.h"
class Terrain :
	public DisplayableObject
{
public:
	Terrain();
	~Terrain();

	void Display();

private:
	GLuint sandTex;
};