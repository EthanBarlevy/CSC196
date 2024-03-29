#pragma once
#include <memory>

namespace vl
{
	class Renderer;
	class Scene;

	class Game
	{
	public:
		Game() = default;
		virtual ~Game() = default;

		// required implementaion with this
		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;

		virtual void Update() = 0;
		virtual void Draw(Renderer& renderer) = 0;

		int getScore() { return m_score; }
		void addPoints(int points) { m_score += points; }

	protected:
		std::unique_ptr<Scene> m_scene;
		int m_score = 0;
	};
}