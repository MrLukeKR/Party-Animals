#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

#define NUMBER_OF_RAYS 50.f //The number of rays to reflect off of the mirrorball
#define ALTITUDE_RANGE 2.f //The distance to float up and down
#define ALTITUDE_CHANGE_FREQUENCY 0.1f //How fast to float up and down
#define FEATHER_SEGMENT_LENGTH 0.5f //Length of each colour in feathers

/* 
Party Animals: Disco Ball Parrot (Header File)
Author: Luke K. Rose
Written: April 2018
*/

class DiscoBallParrot :
	public DisplayableObject, 
	public Animation
{
public:
	/*
	Public Constructor/Destructor
	*/
	DiscoBallParrot();
	~DiscoBallParrot() ;

	/*
	Public Methods
	*/
	void Display();
	void Update(const double& dT);

private:
	/*
	Private Methods
	*/
	void drawDiscoBall();
	void drawParrot();
	void drawRays();
	void drawTailFeathers();
	void drawFeather();
	void drawBody();
	void drawWing(bool invert);
	void drawHead();
	void drawBeak();
	void drawFeet();
	void drawString();

	/*
	Private Variables
	*/
	GLuint discoBallTex = Scene::GetTexture("./Textures/discoball.bmp");
	bool reverseAltitude = false, reverseFlap = false;
	float *degree = new float[NUMBER_OF_RAYS], 
		  *x = new float[NUMBER_OF_RAYS],
		  *y = new float[NUMBER_OF_RAYS],
		  *z = new float[NUMBER_OF_RAYS];
	float discoBallRotation = 0, altitudeChange = 0, wingAngle = 0;
};