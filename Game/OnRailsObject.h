#pragma once
#include "Framework/actor.h"

namespace tlr
{
	class onRailsObject : public vl::Actor
	{
	public:
		enum Lane 
		{
			Left,
			Middle,
			Right
		};
	public:
		onRailsObject() = default;
		onRailsObject(const vl::Model& model, const vl::Transform& transform, Lane lane = Lane::Middle) : 
			Actor{ model, transform }, 
			m_lane{ lane } {}

		virtual void Update() override;

		virtual void OnCollision(Actor* other) {}

	protected:
		Lane m_lane{ Lane::Middle };
	};
}