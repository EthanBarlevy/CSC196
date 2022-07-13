#pragma once
#include "gameObject.h"
#include "../Renderer/model.h"

namespace vl
{
	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(Model model, Transform transform) : GameObject{ transform }, m_model{ model } {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

	protected:
		Model m_model;
	};
}