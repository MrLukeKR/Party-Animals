#pragma once
#include "DisplayableObject.h"
class DJDecks :
	public DisplayableObject
{
public:
	DJDecks();
	~DJDecks();
	void Display();

private:
	void drawPodium();
	void drawTurntable();
	void drawVinyl();
	void box(float x, float y, float z);
};

