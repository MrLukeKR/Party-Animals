#pragma once

#include "DisplayableObject.h"

/*
Party Animals: DJ Decks (Header File)
Author: Luke K. Rose
April 2018
*/

class DJDecks :
	public DisplayableObject
{
public:
	/*
	Public Constructor/Destructor
	*/
	DJDecks() {};
	~DJDecks() {};
	
	/*
	Public methods
	*/
	void Display();

private:
	/*
	Private methods
	*/
	void drawPodium();
	void drawTurntable();
	void drawVinyl();

	/*
	Private variables
	*/
	GLuint 	deskTex = Scene::GetTexture("./Textures/black-wood.bmp");
};

