#include "player.h"
#include "engine.h"
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	vl::SetFilePath("../Assets");

	// transforms
	vl::Transform transform;
	transform.position = vl::Vector2{ 250, 250 };
	transform.rotation = 0;
	transform.scale = 7;
	
	// model
	vector<vl::Vector2> points{
		{ 7.00f, 0.00 },
		{ 0.00f, -4.00 },
		{ -2.00f, -2.00 },
		{ 0.00f, 0.00 },
		{ -2.00f, 2.00 },
		{ 0.00f, 4.00 }
	};
	//vl::Model model(points, vl::Color{ 255, 255, 255, 255 });
	vl::Model model;
	model.Load("Model.txt");

	tlr::Player player{ model, transform };

	vl::InitializeMemory();
	

	g_renderer.Initialize();
	g_inputSystem.Initialize();

	// create window
	g_renderer.CreateWindow("Gaming", 500, 500);
	g_renderer.setClearColor(vl::Color{ 51, 51, 51, 255 });
	

	bool quit = false;
	while (!quit)
	{
		// update
		g_inputSystem.Update();

		if (g_inputSystem.GetKeyDown(vl::key_escape)) quit = true;

		player.Update();

		//render
		g_renderer.BeginFrame();

		player.Draw(g_renderer);

		g_renderer.EndFrame();
	}

	g_renderer.Shutodwn();
}