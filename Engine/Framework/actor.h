#pragma once
#include "gameObject.h"
#include "../Renderer/model.h"

namespace vl
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : GameObject{ transform }, m_model{ model }, scene{ nullptr }{}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

	public:
		Scene* scene;

	protected:
		Model m_model;
	};
}