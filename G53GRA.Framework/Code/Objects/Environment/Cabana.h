#pragma once

#include "DisplayableObject.h"

/*
Party Animals: Cabana (Header File)
Author: Luke K. Rose
April 2018
*/

class Cabana:
	public DisplayableObject
{
public:
	/*
	Public Constructor/Destructor
	*/
	Cabana(){};
	~Cabana() {};
	
	/*
	Public methods
	*/
	void Display();
	
private:
	/*
	Private methods
	*/
	void drawTop();
	void drawPillar();

	/*
	Private variables
	*/
	GLuint cabanaTex = Scene::GetTexture("./Textures/cabana.bmp");
};