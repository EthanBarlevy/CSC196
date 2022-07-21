#pragma once
#include "Framework/actor.h"

namespace tlr
{
	class Player : public vl::Actor
	{
	public:
		Player() = default;
		Player(const vl::Model& model, const vl::Transform& transform) : Actor{ model, transform } {}
		
		void Update() override;


	private:
		float m_speed{ 0 };
		float m_maxSpeed{ 400 };
	};
}