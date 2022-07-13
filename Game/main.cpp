#include "Math/mathUtils.h"
#include "Math/random.h"
#include "Core/memory.h"
#include "Core/file.h"
#include "Input/inputSystem.h"
#include "Renderer/renderer.h"
#include "Renderer/model.h"
#include "player.h"
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
		{ 0.00f, -6.00 },
		{ -4.00f, 0.00 },
		{ -2.00f, 2.00 },
		{ 0.00f, 0.00 },
		{ 2.00f, 2.00 },
		{ 4.00f, 0.00 },
		{ 0.00f, -6.00 }
	};
	vl::Model model(points, vl::Color{ 255, 255, 255, 255 });

	tlr::Player player{ model, transform };

	vl::InitializeMemory();

	// create systems
	vl::Renderer renderer;
	vl::InputSystem inputSystem;

	renderer.Initialize();
	inputSystem.Initialize();

	// create window
	renderer.CreateWindow("Gaming", 500, 500);
	renderer.setClearColor(vl::Color{ 51, 51, 51, 255 });
	
	

	bool quit = false;
	while (!quit)
	{
		// update
		inputSystem.Update();

		if (inputSystem.GetKeyDown(vl::key_escape)) quit = true;


		if (inputSystem.GetKeyDown(vl::key_left))
		{
			player.GetTransform().rotation -= 0.03;
		}

		if (inputSystem.GetKeyDown(vl::key_right))
		{
			player.GetTransform().rotation += 0.03;
		}

		float thrust = 0;
		if (inputSystem.GetKeyDown(vl::key_up))
		{
			thrust = 3;
		}

		// face target
		vl::Vector2 target = inputSystem.GetMousePosition();
		target -= player.GetTransform().position;
		player.GetTransform().rotation = target.GetAngle();

		vl::Vector2 direction{ 1, 0 };
		direction = vl::Vector2::Rotate(direction, player.GetTransform().rotation);

		player.GetTransform().position += (direction * thrust);

		//if (inputSystem.GetKeyDown(vl::key_down))
		//{
		//	position.y += 2.0;
		//}

		if (inputSystem.GetButtonDown(vl::button_left))
		{
			cout << inputSystem.GetButtonState(vl::button_left) << "  :  " << inputSystem.GetMousePosition().x << ", " << inputSystem.GetMousePosition().y << endl;
		}


		//render
		renderer.BeginFrame();

		player.Draw(renderer);

		renderer.EndFrame();
	}

	renderer.Shutodwn();
}