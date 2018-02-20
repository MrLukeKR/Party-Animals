#include "MyScene.h"
#include "..\Code\Objects\Tree.h"
#include "Objects\Skybox.h"
#include "Objects\Lights\Sun.h"
#include "Objects\Terrain.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
}

void MyScene::Initialise()
{
	glClearColor(0.f, 0.0f, 0.0f, 1.0f);

	DisplayableObject* skybox = new Skybox(new string[6] { "./Textures/skyboxes/bluecloud/bluecloud_bk.bmp" , "./Textures/skyboxes/bluecloud/bluecloud_lf.bmp" ,"./Textures/skyboxes/bluecloud/bluecloud_ft.bmp" ,"./Textures/skyboxes/bluecloud/bluecloud_rt.bmp" ,"./Textures/skyboxes/bluecloud/bluecloud_up.bmp" ,"./Textures/skyboxes/bluecloud/bluecloud_up.bmp" });
	skybox->size(10000);
	AddObjectToScene(skybox);

	DisplayableObject* sun = new Sun();

	sun->position(0, 500, 0);
	sun->size(10, 10, 10);

	AddObjectToScene(sun);

	DisplayableObject* tree = new Tree();
	tree->size(1, 1, 1);

	AddObjectToScene(tree);

	DisplayableObject* terrain = new Terrain();

	terrain->size(100, 100, 100);
	AddObjectToScene(terrain);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 100000.0);
}
