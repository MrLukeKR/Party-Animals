#pragma once

#define _USE_MATH_DEFINES
#include <DisplayableObject.h>
#include <cmath>
#include <string>

using namespace std;

class Tree :
	public DisplayableObject
{
public:
	Tree();
	Tree(string, float);
	~Tree() {};
	
	void Display();

private:
	void branch();
	string sequence;
	float angle;
};

