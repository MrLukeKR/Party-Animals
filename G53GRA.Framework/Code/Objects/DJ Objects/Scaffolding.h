#pragma once

#include "DisplayableObject.h"

/*
Party Animals: Scaffolding (Header File)
Author: Luke K. Rose
April 2018
*/

class Scaffolding :
	public DisplayableObject
{
public:
	/*
	Public Constructor/Destructor
	*/
	Scaffolding() {};
	~Scaffolding() {};

	/*
	Public methods
	*/
	void Display();

private:
	/*
	Private methods
	*/
	void drawScaffolding();
	void drawHalf();
};

