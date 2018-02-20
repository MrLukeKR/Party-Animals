#include "MyScene.h"
#include "..\Code\Objects\Tree.h"
#include "Objects\Skybox.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
}

void MyScene::Initialise()
{
	glClearColor(1.f, 1.0f, 1.0f, 1.0f);

	DisplayableObject* skybox = new Skybox(new string[6] { "./Textures/posz.bmp" , "./Textures/negx.bmp" ,"./Textures/negz.bmp" ,"./Textures/posx.bmp" ,"./Textures/posy.bmp" ,"./Textures/negy.bmp" });

	skybox->size(10000);
	AddObjectToScene(skybox);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 100000.0);
}
