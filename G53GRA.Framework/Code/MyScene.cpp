#include "MyScene.h"
#include "..\Code\Objects\Tree.h"
#include "Objects\Skybox.h"
#include "Objects\Lights\Sun.h"
#include "Objects\Lights\Moon.h"
#include "Objects\Animals\Giraffe.h"
#include "Objects\Terrain.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
}

void MyScene::Initialise()
{
	glClearColor(0.f, 0.0f, 0.0f, 1.0f);

	glDisable(GL_LIGHT0);

	DisplayableObject* skybox = new Skybox(new string[6] { "./Textures/skyboxes/bluecloud/bluecloud_bk.bmp" , "./Textures/skyboxes/bluecloud/bluecloud_lf.bmp" ,"./Textures/skyboxes/bluecloud/bluecloud_ft.bmp" ,"./Textures/skyboxes/bluecloud/bluecloud_rt.bmp" ,"./Textures/skyboxes/bluecloud/bluecloud_up.bmp" ,"./Textures/skyboxes/bluecloud/bluecloud_up.bmp" });
	skybox->size(10000);
	AddObjectToScene(skybox);

	DisplayableObject* sun = new Sun();

	sun->position(500, 0, 0);
	sun->size(10, 10, 10);

	AddObjectToScene(sun);
	
	DisplayableObject* moon = new Moon();

	moon->position(500, 0, 0);
	moon->size(10, 10, 10);

	AddObjectToScene(moon);
	
	DisplayableObject* giraffe = new Giraffe();

	giraffe->position(0, 0, 900);
	giraffe->size(5, 5, 5);

	AddObjectToScene(giraffe);

	/*for (int i = 0; i < 10; i++) {
		DisplayableObject* tree = new Tree();
		tree->size(1, 1, 1);
		tree->position(rand() % 100, 0, rand() % 100);

		AddObjectToScene(tree);
	}
	*/
	DisplayableObject* terrain = new Terrain();

	terrain->size(100, 100, 100);
	AddObjectToScene(terrain);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 100000.0);
}
