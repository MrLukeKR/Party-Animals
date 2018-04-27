#pragma once

#include "DisplayableObject.h"

/*
Party Animals: Terrain (Header File)
Author: Luke K. Rose
April 2018
*/

class Terrain :
	public DisplayableObject
{
public:
	/*
	Public Constructor/Destructor
	*/
	Terrain() {};
	~Terrain() {};

	/*
	Public methods
	*/
	void Display();

private:
	/*
	Private variables
	*/
	GLuint sandTex = Scene::GetTexture("./Textures/sand.bmp");
};