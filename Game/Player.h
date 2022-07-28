#pragma once
#include "OnRailsObject.h"

namespace tlr
{
	class Player : public onRailsObject
	{
	public:
		Player() = default;
		Player(const vl::Model& model, const vl::Transform& transform, Lane lane = Lane::Middle) :
			onRailsObject{ model, transform, lane } {}
		

		void Update() override;

		void OnCollision(Actor* other) override;

	private:
		float m_health{ 10 };

		// you can not imagine how long i tried to combine these two variables without getting memory leaks
		float m_jumpTime{ 0 };
		float m_duckTime{ 0 };

		//float m_speed{ 0 };
		//float m_maxSpeed{ 400 };
	};
}