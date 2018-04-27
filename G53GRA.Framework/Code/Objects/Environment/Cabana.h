#pragma once
#include "DisplayableObject.h"

class Cabana:
	public DisplayableObject
{
public:
	Cabana() : cabanaTex(Scene::GetTexture("./Textures/cabana.bmp")) {};
	~Cabana() {};
	
	void Display();
	void drawTop();
	void drawPillar();

	GLuint cabanaTex;
};