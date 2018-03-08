#pragma once
#include "Z:\Year 3\G53GRA-Project\G53GRA.Framework\Framework\Interface\DisplayableObject.h"
class Terrain :
	public DisplayableObject
{
public:
	Terrain();
	~Terrain();

	void Display();

private:
	GLuint sandTex;
};