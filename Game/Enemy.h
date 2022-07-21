#pragma once
#include "Framework/actor.h"

namespace tlr 
{
	class Enemy : public vl::Actor
	{
	public:
		Enemy() = default;
		Enemy(const vl::Model& model, const vl::Transform& transform) : Actor{ model, transform } { Initalize(); }

		void Initalize();
		void Update() override;


	private:
		float m_speed{ 100 };
		float m_fire{ 0 };
	};
}