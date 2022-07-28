#pragma once
#include "OnRailsObject.h"
#include "Framework/actor.h"

namespace tlr 
{
	class Blocker : public onRailsObject
	{
	public:
		Blocker() = default;
		Blocker(const vl::Model& model, const vl::Transform& transform, std::string tag, Lane lane = Lane::Middle) :
			onRailsObject{ model, transform, lane } 
		{
			GetTag() = tag;
		}

		void OnCollision(Actor* other) override;

	private:

	};
}