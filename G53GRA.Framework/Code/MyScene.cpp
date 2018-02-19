#include "MyScene.h"
#include "..\Code\Objects\Tree.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
	Tree* myTree = new Tree(); //"fg+fh<g+fh<g+fh", 60.f
	
	AddObjectToScene(myTree);
}

void MyScene::Initialise()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}
