#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

/* Party Animals: Disco Ball Parrot (Header File)
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
	GLuint discoBallTex;
	bool reverseAltitude = false, reverseFlap = false;
	float *degree, *x, *y, *z;
	float discoBallRotation = 0, altitudeChange = 0, wingAngle = 0;
};