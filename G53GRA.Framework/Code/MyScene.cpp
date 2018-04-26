#include "MyScene.h"
#include "..\Code\Objects\Tree.h"
#include "Objects\Skybox.h"
#include "Objects\Lights\Sun.h"
#include "Objects\Lights\Moon.h"
#include "Objects\Animals\Giraffe.h"
#include "Objects\Animals\Elephant.h"
#include "Objects\Animals\Monkey.h"
#include "Objects\Terrain.h"
#include "Objects\Lights\DiscoLight.h"
#include "Objects\DJ Objects\Speaker.h"
#include "Objects\DJ Objects\Scaffolding.h"
#include "Objects\DJ Objects\DJDecks.h"
#include "Objects\DJ Objects\DanceFloor.h"
#include "SpecialFX\Confetti.h"
#include "SpecialFX\Smoke.h"
#include "Objects\Animals\Snake.h"
#include "Objects\DJ Objects\Screen.h"
#include "Objects\Animals\DiscoBallParrot.h"
#include "Objects\Cabana.h"
#include "Objects\DJ Objects\Meter.h"
#include "Objects\Rock.h"

#define MAX_ROCKS 40
#define MAX_CLIFFS 100

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight){}

void MyScene::Initialise()
{
	glClearColor(0.f, 0.0f, 0.0f, 1.0f);
	glDisable(GL_LIGHT0);
	prevTime = glutGet(GLUT_ELAPSED_TIME);

	DisplayableObject* skybox = new Skybox(new string[6] { 
		"./Textures/skyboxes/yellowcloud/yellowcloud_bk.bmp", 
		"./Textures/skyboxes/yellowcloud/yellowcloud_lf.bmp",
		"./Textures/skyboxes/yellowcloud/yellowcloud_ft.bmp",
		"./Textures/skyboxes/yellowcloud/yellowcloud_rt.bmp",
		"./Textures/skyboxes/yellowcloud/yellowcloud_up.bmp",
		"./Textures/skyboxes/yellowcloud/yellowcloud_up.bmp" });
	skybox->size(10000);
	AddObjectToScene(skybox);

	for (int i = 0; i < MAX_ROCKS; i++) {
		float radius = 200;
		float x = radius * sin((float)i / (float)MAX_ROCKS * 360.f),
			  y = radius * cos((float)i / (float)MAX_ROCKS * 360.f);
		Rock* rock = new Rock("./Textures/rock.bmp");
		rock->position(50 + x, -10, 900 + y);
		rock->size(2.5f, 2.5f, 2.5f);
		AddObjectToScene(rock);
	}

	for (int i = 0; i < MAX_CLIFFS; i++) {
		float radius = 2000;
		float x = radius * sin((float)i / (float) MAX_CLIFFS* 360.f),
			y = radius * cos((float)i / (float)MAX_CLIFFS * 360.f);
		Rock* rock = new Rock("./Textures/canyon.bmp");
		rock->position(50 + x, -10, 900 + y);
		rock->size(20, 40, 20);
		AddObjectToScene(rock);
	}

	Cabana* cabana = new Cabana();
	cabana->position(50, 0, 900);
	AddObjectToScene(cabana);
	
	DisplayableObject* sun = new Sun();
	sun->position(500, 0, 0);
	sun->size(10, 10, 10);
	AddObjectToScene(sun);

	Moon* moon = new Moon();
	moon->position(500, 0, 0);
	moon->size(10, 10, 10);
	AddObjectToScene(moon);
	
	Elephant* elephant = new Elephant();
	elephant->position(0, 0, 890);
	elephant->size(1, 1, 1);
	AddObjectToScene(elephant);
	
	Giraffe* giraffe = new Giraffe();
	giraffe->position(0, 0, 910);
	giraffe->size(1, 1, 1);
	AddObjectToScene(giraffe);
	
	Terrain* terrain = new Terrain();
	terrain->size(2, 1, 2);
	terrain->position(1, -10, 900);
	AddObjectToScene(terrain);

	DiscoLight* discoLight1 = new DiscoLight(-1,-1,1, GL_LIGHT3, 1);
	discoLight1->position(100, 13.5f, 870);
	AddObjectToScene(discoLight1);

	DiscoLight* discoLight2 = new DiscoLight(-1, -1, -1, GL_LIGHT4, 4);
	discoLight2->position(100, 13.5f, 930);
	AddObjectToScene(discoLight2);

	Speaker* speaker1 = new Speaker();
	speaker1->position(100, 10, 950);
	speaker1->size(2, 2, 2);
	AddObjectToScene(speaker1);

	Speaker* speaker2 = new Speaker();
	speaker2->position(100, 10, 850);
	speaker2->size(2, 2, 2);
	AddObjectToScene(speaker2);

	Scaffolding* djScaffolding = new Scaffolding();
	djScaffolding->position(100, 15, 900);
	djScaffolding->size(1, 1, 1);
	AddObjectToScene(djScaffolding);

	DJDecks* djDecks = new DJDecks();
	djDecks->position(100, -1, 900);
	djDecks->size(1, 1, 1);
	AddObjectToScene(djDecks);

	Meter* meter = new Meter();
	meter->position(96.99f, -10, 893.75f);
	meter->size(1, 7.5f, 12.5f);
	meter->orientation(0, -90, 0);
	AddObjectToScene(meter);

	DanceFloor* danceFloor = new DanceFloor();
	danceFloor->position(40, -9.9f, 900);
	danceFloor->size(5, 1, 5);
	AddObjectToScene(danceFloor);

	for (int i = 0; i < 250; i++) {
		Confetti* confetti = new Confetti(50, 10, 900);
		confetti->size(0.25f, 0.25f, 0.25f);
		AddObjectToScene(confetti);
	}

	Monkey* djMonkey= new Monkey();
	djMonkey->position(105, -1, 900);
	djMonkey->size(1, 1, 1);
	AddObjectToScene(djMonkey);
	
	Snake* snake = new Snake();
	snake->position(100, 12, 882.5f);
	AddObjectToScene(snake);

	Screen* screen1 = new Screen(true);
	screen1->position(100, 20, 875);
	AddObjectToScene(screen1);

	Screen* screen2 = new Screen(false);
	screen2->position(100, 20, 925);
	AddObjectToScene(screen2);

	DiscoBallParrot* parrot = new DiscoBallParrot();
	parrot->position(50, 30, 900);
	AddObjectToScene(parrot);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 100000.0);
}