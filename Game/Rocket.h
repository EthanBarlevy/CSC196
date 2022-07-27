#pragma once
#include "Framework/actor.h"

namespace tlr
{
	class Rocket : public vl::Actor
	{
	public:
		Rocket() = default;
		Rocket(const vl::Model& model, const vl::Transform& transform, float damage = 1) : 
			Actor{ model, transform }, 
			m_damage{ damage } {}

		void Update() override;

		void OnCollision(Actor* other) override;

		float GetDamage() { return m_damage; }

	private:
		float m_damage{ 1 };
		float m_speed{ 200 };
		float m_lifespan{ 2 };
	};
}