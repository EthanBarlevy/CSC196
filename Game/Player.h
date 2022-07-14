#pragma once
#include "Framework/actor.h"

using namespace vl;

namespace tlr
{
	class Player : public vl::Actor
	{
	public:
		Player() = default;
		Player(const Model& model, const Transform& transform) : Actor{ model, transform } {}
		
		void Update() override;


	private:
		float m_speed{ 0 };
		float m_maxSpeed{ 5 };
	};
}