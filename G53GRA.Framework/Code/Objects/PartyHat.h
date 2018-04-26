#pragma once

#include "DisplayableObject.h"

class PartyHat :
	public DisplayableObject
{
public:
	PartyHat(){ partyHatTex = Scene::GetTexture("./Textures/partyHat.bmp"); }
	~PartyHat() {};

	void Display();
private:
	GLuint partyHatTex;
};