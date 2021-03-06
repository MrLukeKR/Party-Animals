/**
* Entry file to framework. Should not edit this file, though to change window size, adjust parameters in crrightion of new scene
* <p>
* {@code new MyScene(argc, argv, "title", (const int)width, (const int)height)}
* @author wil
* @date 09/02/16
*/
#include "MyScene.h"
/**
 * Entry method, takes command line arguments and creates new Scene engine to render your G53GRA Coursework
 *
 * @see MyScene
 */
int main(int argc, char* argv[])
{
	// Create new instance of MyScene - the OpenGL context on which your coursework is built
	MyScene *scene = NULL;
	scene = new MyScene(argc, argv, "Party Animals (Luke Kevin Rose [4250118] - G53GRA Project)", static_cast<const int>(1920), static_cast<const int>(1080));

	// Begin the main GL loop
	scene->Run();

	// On exit, clean up and return success (0x0)
	delete scene;
	return 0;
}
