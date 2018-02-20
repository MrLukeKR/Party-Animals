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
	void leaf();
	string sequence;
	float angle;
	string genRandSeq(int maxBranchLength, int branchRate, int depth, int trunkHeight, int level);
	float color[3] = { .65f, .16f, .16f };
};

