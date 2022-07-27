#pragma once
#include "Framework/actor.h"

namespace tlr 
{
	class Enemy : public vl::Actor
	{
	public:
		Enemy() = default;
		Enemy(const vl::Model& model, const vl::Transform& transform, float health = 1) : 
			Actor{ model, transform },
			m_health{ health }{ Initalize(); }

		void Initalize();
		void Update() override;

		void OnCollision(Actor* other) override;

	private:
		float m_health{ 1 };
		float m_speed{ 100 };
		float m_fire{ 0 };
	};
}