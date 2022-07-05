#pragma once

struct SDL_Renderer;
struct SDL_Window;

namespace vl
{
	class Renderer
	{
	public:
		// new weird way to make a default constuctor / destuctor
		Renderer() = default;
		~Renderer() = default;

		void Initialize();
		void Shutodwn();

		void CreateWindow(const char* name, int width, int height);

		void BeginFrame();
		void EndFrame();

		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawPoint(float x, float y);

	private:
		SDL_Renderer* m_renderer{ nullptr };
		SDL_Window* m_window{ nullptr };
	};
}