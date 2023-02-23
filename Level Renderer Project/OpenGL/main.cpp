// Simple basecode showing how to create a window and attatch a openglsurface
#define GATEWARE_ENABLE_CORE // All libraries need this
#define GATEWARE_ENABLE_SYSTEM // Graphics libs require system level libraries
#define GATEWARE_ENABLE_GRAPHICS // Enables all Graphics Libraries
#define GATEWARE_ENABLE_MATH 
#define GATEWARE_ENABLE_INPUT 
// Ignore some GRAPHICS libraries we aren't going to use
#define GATEWARE_DISABLE_GDIRECTX11SURFACE // we have another template for this
#define GATEWARE_DISABLE_GDIRECTX12SURFACE // we have another template for this
#define GATEWARE_DISABLE_GVULKANSURFACE // we have another template for this
#define GATEWARE_DISABLE_GRASTERSURFACE // we have another template for this
// With what we want & what we don't defined we can include the API
#include "../Gateware/Gateware.h"
//#include "renderer.h" // example rendering code (not Gateware code!)
#include "../../Level Renderer Project/OpenGL/load_object_oriented.h"

// open some namespaces to compact the code a bit
using namespace GW;
using namespace CORE;
using namespace SYSTEM;
using namespace GRAPHICS;
// lets pop a window and use OpenGL to render to a window
int main()
{
	GWindow win;
	GEventResponder msgs;
	GOpenGLSurface ogl;
	GlobalVar glb;
	if (+win.Create(0, 0, 800, 600, GWindowStyle::WINDOWEDBORDERED))
	{
		win.SetWindowName("Miguel Martinez - Level Renderer - OpenGL");
		float clr[] = { 200 / 255.0f,       90 / 255.0f,       150 / 255.0f, 1 };
		if (+ogl.Create(win, GW::GRAPHICS::DEPTH_BUFFER_SUPPORT))
		{
			glb.LoadExtensions(ogl);
			//Renderer renderer(win, ogl);
			GLog log; // handy for logging any messages/warning/errors
			// begin loading level
			log.Create("../LevelLoaderLog.txt");
			log.EnableConsoleLogging(false); // mirror output to the console
			log.Log("Start Program.");

			Level_Objects objectOrientedLoader;
			objectOrientedLoader.LoadLevel("../../CyberpunkGameLevel.txt", "../../Models", log, win);

			log.Log("End Program.");


			while (+win.ProcessWindowEvents())
			{
				glClearColor(clr[0], clr[1], clr[2], clr[3]);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				objectOrientedLoader.RenderLevel();
				//renderer.Render();
				ogl.UniversalSwapBuffers();


				if (GetAsyncKeyState(VK_F1) & 0x8000)
					objectOrientedLoader.LoadLevel("../../CyberpunkGameLevel.txt", "../../Models", log, win);
				else if (GetAsyncKeyState(VK_F2) & 0x8000)
					objectOrientedLoader.LoadLevel("../../DungeonGameLevel.txt", "../../Models", log, win);
			}
			objectOrientedLoader.UnloadLevel();
		}
	}

	return 0; // that's all folks
}