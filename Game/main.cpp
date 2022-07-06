#include "Math/mathUtils.h"
#include "Math/random.h"
#include "Core/memory.h"
#include "Renderer/renderer.h"
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	vl::seedRandom(8763243);
	for (int i = 0; i < 10; i++) {
		cout << vl::randomf(5, 10) << endl;
	}

	vl::Vector2 v1;
	v1.x = 30;
	v1.y = 121;

	vl::Vector2 move{ 3,0 };

	vector<vl::Vector2> model;
	model.push_back(vl::Vector2(34, 97));
	model.push_back(vl::Vector2(35, 42));
	model.push_back(vl::Vector2(85, 35));
	model.push_back(vl::Vector2(17, 94));
	model.push_back(vl::Vector2(45, 39));


	vl::InitializeMemory();

	vl::Renderer renderer;
	renderer.Initialize();

	renderer.CreateWindow("Gaming", 500, 500);
	renderer.setClearColor(vl::Color{ 51, 51, 51, 255 });
	
	vl::Color color;
	color.a = 255;

	while (1)
	{
		renderer.BeginFrame();

		// draw
		color.r = vl::random(256);
		color.g = vl::random(256);
		color.b = vl::random(256);
		renderer.DrawPoint(v1, color);

		for (auto& v : model)
		{
			v += move;
		}

		for (int i = 0; i < model.size(); i++) 
		{
			renderer.DrawLine(model[i], model[(i + 1) % model.size()], color);
		}

		//renderer.DrawLine(vl::Vector2{ vl::randomf(500), vl::randomf(500) }, vl::Vector2{ vl::randomf(500), vl::randomf(500) }, color);
		//renderer.DrawPoint(vl::Vector2{ vl::randomf(500), vl::randomf(500) }, color);

		//v1 += move;
		renderer.EndFrame();
	}

	renderer.Shutodwn();
}