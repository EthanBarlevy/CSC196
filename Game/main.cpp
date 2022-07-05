#include "Math/mathUtils.h"
#include "Math/random.h"
#include "Core/memory.h"
#include "Renderer/renderer.h"
#include <iostream>


using namespace std;

int main()
{
	vl::seedRandom(8763243);
	for (int i = 0; i < 10; i++) {
		cout << vl::randomf(5, 10) << endl;
	}


	vl::InitializeMemory();

	vl::Renderer renderer;
	renderer.Initialize();

	renderer.CreateWindow("Gaming", 500, 500);
	
	while (1)
	{
		renderer.BeginFrame();
		// draw
		renderer.DrawLine(vl::randomf(500), vl::randomf(500), vl::randomf(500), vl::randomf(500));
		renderer.DrawPoint(vl::randomf(500), vl::randomf(500));
		renderer.EndFrame();
	}

	renderer.Shutodwn();
}