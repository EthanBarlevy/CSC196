#include "scene.h"

namespace vl
{
	void Scene::Update()
	{
		for (auto& actor : m_actors) 
		{
			actor->Update();
		}
	}
	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : m_actors)
		{
			actor->Draw(renderer);
		}
	}
	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		m_actors.push_back(std::move(actor));
	}
}
