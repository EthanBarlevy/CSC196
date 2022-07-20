#include "Player.h"
#include "Enemy.h"
#include "engine.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vl::InitializeMemory();

	vl::SetFilePath("../Assets");

	vl::Scene scene;

	// transforms
	vl::Transform transform;
	transform.position = vl::Vector2{ 250, 250 };
	transform.rotation = 0;
	transform.scale = 7;
	
	//players
	std::unique_ptr<tlr::Player> player = std::make_unique<tlr::Player>(vl::Model{ "Player.txt" }, transform);
	scene.Add(std::move(player));

	// enemies
	for (int i = 0; i < 20; i++) 
	{
		transform.position.x = vl::randomf(500);
		transform.position.y = vl::randomf(500);
		transform.rotation = vl::randomf(math::TWOPI);
		transform.scale = vl::randomf(1, 7);

		std::unique_ptr<tlr::Enemy> enemy = std::make_unique<tlr::Enemy>(vl::Model{ "Enemy.txt" }, transform);
		scene.Add(std::move(enemy));
	
	}

	vl::g_renderer.Initialize();
	vl::g_inputSystem.Initialize();

	// create window
	vl::g_renderer.CreateWindow("Gaming", 500, 500);
	vl::g_renderer.setClearColor(vl::Color{ 51, 51, 51, 255 });
	

	bool quit = false;
	while (!quit)
	{
		// update
		vl::g_inputSystem.Update();
		vl::g_time.Tick();

		//cout << g_time.deltaTime << endl;

		if (vl::g_inputSystem.GetKeyDown(vl::key_escape)) quit = true;

		scene.Update();

		//render
		vl::g_renderer.BeginFrame();

		scene.Draw(vl::g_renderer);

		vl::g_renderer.EndFrame();
	}

	vl::g_renderer.Shutodwn();
}