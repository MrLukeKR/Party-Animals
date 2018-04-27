#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

/* 
Party Animals: Snake (Header File)
Author: Luke K. Rose
April 2018
*/
class Snake :
	public DisplayableObject,
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	Snake() {};
	~Snake() {};

	/*
	Public methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private methods
	*/
	void drawHead();
	void drawEye();
	void drawTongue();

	/*
	Private variables
	*/
	GLuint 	snakeTex = Scene::GetTexture("./Textures/snake.bmp");;
	float frequency = 10;
	int offset = 0;
};