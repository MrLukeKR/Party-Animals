#pragma once

#include "DisplayableObject.h"

/*
Turn on wireframes by setting this to 1:
*/
#define DEBUG 0

/*
Party Animals: Box (Header File)
Author: Luke K. Rose
April 2018
*/

class Box : public DisplayableObject {
public:
	/*
	Public methods
	*/
	static void box(float sx, float sy, float sz);
	static void box(float sx, float sy, float sz, GLuint texID);

private:
	/*
	Private Constructor/Destructor
	*/
	Box() {};
	~Box() {};
};