#pragma once
#include <DisplayableObject.h>
#include <string>
#include <Scene.h>

using namespace std;

class Skybox : public DisplayableObject
{
public:
	Skybox() {}; 
	Skybox(string filePath[6]);
	~Skybox() {};
	
	void Display();
	GLuint loadSkybox(string& filePath) { return Scene::GetTexture(filePath); } ;

private :
	GLuint textureID[6] = { 0 };
};

