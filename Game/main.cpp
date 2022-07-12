#include "Math/mathUtils.h"
#include "Math/random.h"
#include "Core/memory.h"
#include "Core/file.h"
#include "Input/inputSystem.h"
#include "Renderer/renderer.h"
#include "Renderer/model.h"
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	cout << vl::GetFilePath() << endl;
	vl::SetFilePath("../Assets");
	cout << vl::GetFilePath() << endl;
	size_t size;
	vl::GetFileSize("Model.txt", size);
	cout << size << endl;

	std::string buffer;
	vl::ReadFile("Model.txt", buffer);
	cout << buffer << endl;

	float angle = 0;

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

	vl::Vector2 position{ 250, 250 };


	vl::InitializeMemory();

	vl::Renderer renderer;
	vl::InputSystem inputSystem;

	renderer.Initialize();
	inputSystem.Initialize();

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
			angle -= 0.03;
		}

		if (inputSystem.GetKeyDown(vl::key_right))
		{
			angle += 0.03;
		}

		float thrust = 0;
		if (inputSystem.GetKeyDown(vl::key_up))
		{
			thrust = 2;
		}

		vl::Vector2 direction{ 0, -1 };
		direction = vl::Vector2::Rotate(direction, angle);
		position += (direction * thrust);

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

		model.Draw(renderer, position, angle, 7);

		renderer.EndFrame();
	}

	renderer.Shutodwn();
}