#pragma once
#include "DisplayableObject.h"

class Box : public DisplayableObject {
public:
	static void box(float sx, float sy, float sz);
	static void box(float sx, float sy, float sz, GLuint texID);

private:
	Box() {};
};