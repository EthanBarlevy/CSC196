#include "Math/mathUtils.h"
#include "Math/random.h"
#include "Core/memory.h"
#include "Input/InputSystem.h"
#include "Renderer/renderer.h"
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	vector<vl::Vector2> model{
		{ 0.00, -6.00 },
		{ -4.00, 0.00 },
		{ -2.00, 2.00 },
		{ 0.00, 0.00 },
		{ 2.00, 2.00 },
		{ 4.00, 0.00 },
		{ 0.00, -6.00 }
	};

	vl::Vector2 position{ 250, 250 };


	vl::InitializeMemory();

	vl::Renderer renderer;
	vl::InputSystem inputSystem;

	renderer.Initialize();
	inputSystem.Initialize();

	renderer.CreateWindow("Gaming", 500, 500);
	renderer.setClearColor(vl::Color{ 51, 51, 51, 255 });
	
	vl::Color color;
	color.a = 255;

	while (1)
	{
		// update
		inputSystem.Update();

		if (inputSystem.GetKeyState(vl::key_left))
		{
			position.x -= 2.0;
		}
		if (inputSystem.GetKeyState(vl::key_right))
		{
			position.x += 2.0;
		}
		if (inputSystem.GetKeyState(vl::key_up))
		{
			position.y -= 2.0;
		}
		if (inputSystem.GetKeyState(vl::key_down))
		{
			position.y += 2.0;
		}

		//render
		renderer.BeginFrame();

		// draw
		color.r = vl::random(256);
		color.g = vl::random(256);
		color.b = vl::random(256);

		//for (auto& v : model)
		//{
		//	v += move;
		//}

		for (int i = 0; i < model.size(); i++) 
		{
			vl::Vector2 p1 = (model[i] * 5)+ position;
			vl::Vector2 p2 = (model[(i + 1) % model.size()] * 5) + position;
			renderer.DrawLine(p1, p2, color);
		}

		//renderer.DrawLine(vl::Vector2{ vl::randomf(500), vl::randomf(500) }, vl::Vector2{ vl::randomf(500), vl::randomf(500) }, color);
		//renderer.DrawPoint(vl::Vector2{ vl::randomf(500), vl::randomf(500) }, color);

		//v1 += move;
		renderer.EndFrame();
	}

	renderer.Shutodwn();
}