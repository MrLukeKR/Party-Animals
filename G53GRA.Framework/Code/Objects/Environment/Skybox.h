#pragma once

#include "DisplayableObject.h"
#include <string>
#include <Scene.h>

/*
Party Animals: Skybox (Header File)
Author: Luke K. Rose
April 2018
*/

class Skybox : public DisplayableObject
{
public:
	/*
	Public Constructors/Destructor
	*/
	Skybox() {}; 
	Skybox(std::string filePath[6]);
	~Skybox() {};
	
	/*
	Public methods
	*/
	void Display();
	GLuint loadSkybox(std::string& filePath) { return Scene::GetTexture(filePath); } ;

private :
	/*
	Private variables
	*/
	GLuint textureID[6] = { 0 };
};

