#pragma once
#include "Framework/actor.h"



namespace tlr
{
	class Rocket : public vl::Actor
	{
	public:
		Rocket() = default;
		Rocket(const vl::Model& model, const vl::Transform& transform) : Actor{ model, transform } {}

		void Update() override;


	private:
		float m_speed{ 200 };
	};
}