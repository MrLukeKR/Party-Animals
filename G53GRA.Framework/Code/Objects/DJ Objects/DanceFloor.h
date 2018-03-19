#pragma once
#include "DisplayableObject.h"
class DanceFloor :
	public DisplayableObject
{
public:
	DanceFloor();
	~DanceFloor();

	void Display();
private:
	int animTime = 0;
	float red[6] = {0,0,0,1,1,1};
	float green[6] = {0,1,1,0,0,1};
	float blue[6] = {1,0,1,0,1,0};

};