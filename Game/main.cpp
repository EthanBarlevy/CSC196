#include "ThreeLaneRuunner.h"
#include "engine.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vl::InitializeMemory();

	vl::SetFilePath("../Assets");

	// initialize engine
	vl::g_renderer.Initialize();
	vl::g_inputSystem.Initialize();
	vl::g_audioSystem.Initialize();

	// create window
	vl::g_renderer.CreateWindow("Gaming", 500, 500);
	vl::g_renderer.setClearColor(vl::Color{0, 0, 0, 255 });

	{
		// create game
		ThreeLaneRunner game;
		game.Initialize();

		bool quit = false;
		while (!quit)
		{
			// update
			vl::g_time.Tick();
			vl::g_inputSystem.Update();
			vl::g_audioSystem.Update();

			if (vl::g_inputSystem.GetKeyDown(vl::key_escape)) quit = true;

			game.Update();

			//render
			vl::g_renderer.BeginFrame();

			game.Draw(vl::g_renderer);

			vl::g_renderer.EndFrame();
		}
	}

	vl::g_renderer.Shutodwn();
	vl::g_audioSystem.Shutdown();
}