#include "Math/mathUtils.h"
#include "Math/random.h"
#include "Core/memory.h"
#include "Core/file.h"
#include "Input/InputSystem.h"
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

	vector<vl::Vector2> points{
		{ 0.00, -6.00 },
		{ -4.00, 0.00 },
		{ -2.00, 2.00 },
		{ 0.00, 0.00 },
		{ 2.00, 2.00 },
		{ 4.00, 0.00 },
		{ 0.00, -6.00 }
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
			position.x -= 2.0;
		}
		if (inputSystem.GetKeyDown(vl::key_right))
		{
			position.x += 2.0;
		}
		if (inputSystem.GetKeyDown(vl::key_up))
		{
			position.y -= 2.0;
		}
		if (inputSystem.GetKeyDown(vl::key_down))
		{
			position.y += 2.0;
		}

		//render
		renderer.BeginFrame();

		model.Draw(renderer, position, 7.0);

		renderer.EndFrame();
	}

	renderer.Shutodwn();
}