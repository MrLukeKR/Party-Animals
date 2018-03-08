#pragma once
#include "DisplayableObject.h"
class Scaffolding :
	public DisplayableObject
{
public:
	Scaffolding();
	~Scaffolding();

	void Display();
private:
	void drawScaffolding();
	void drawHalf();
};

