#pragma once
#include "OnRailsObject.h"

namespace tlr
{
	class Coin : public onRailsObject
	{
	public:
		Coin() = default;
		Coin(const vl::Model& model, const vl::Transform& transform, Lane lane = Lane::Middle) :
			onRailsObject{ model, transform, lane } {}

		void OnCollision(Actor* other) override;
	private:
	};
}