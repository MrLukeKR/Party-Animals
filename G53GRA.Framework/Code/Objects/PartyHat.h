#pragma once

#include "DisplayableObject.h"

/*
Party Animals: Party Hat (Header File)
Author: Luke K. Rose
April 2018
*/

class PartyHat :
	public DisplayableObject
{
public:
	/*
	Public Constructor/Destructor
	*/
	PartyHat() {};
	~PartyHat() {};

	/*
	Public methods
	*/
	void Display();

private:
	/*
	Private variables
	*/
	GLuint partyHatTex = Scene::GetTexture("./Textures/partyHat.bmp");
};