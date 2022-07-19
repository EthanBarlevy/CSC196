#include "player.h"
#include "engine.h"
#include <iostream>
#include <vector>


using namespace std;

int main()
{

	vl::SetFilePath("../Assets");

	vl::Scene scene;

	// transforms
	vl::Transform transform;
	transform.position = vl::Vector2{ 250, 250 };
	transform.rotation = 0;
	transform.scale = 7;
	
	// model
	for (int i = 0; i < 20; i++) 
	{
		transform.position.x = vl::randomf(500);
		transform.position.y = vl::randomf(500);
		transform.scale = vl::randomf(1, 7);

		std::unique_ptr<tlr::Player> player = std::make_unique<tlr::Player>(vl::Model{ "Enemy.txt" }, transform);
		scene.Add(std::move(player));
	
	}

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
		g_time.Tick();

		//cout << g_time.deltaTime << endl;

		if (g_inputSystem.GetKeyDown(vl::key_escape)) quit = true;

		scene.Update();

		//render
		g_renderer.BeginFrame();

		scene.Draw(g_renderer);

		g_renderer.EndFrame();
	}

	g_renderer.Shutodwn();
}