#pragma once
#include "engine.h"
#include "Coin.h"
#include "Blocker.h"
#include <algorithm>

namespace tlr
{
	//std::unique_ptr<tlr::Coin> coinLeft = std::make_unique<Coin>(vl::Model{ "Coin.txt" }, trans, Coin::Lane::Left);
	//std::unique_ptr<tlr::Coin> coinMid = std::make_unique<Coin>(vl::Model{ "Coin.txt" }, trans, Coin::Lane::Middle);
	//std::unique_ptr<tlr::Coin> coinRight = std::make_unique<Coin>(vl::Model{ "Coin.txt" }, trans, Coin::Lane::Right);

	//std::unique_ptr<tlr::Blocker> jumpLeft = std::make_unique<tlr::Blocker>(vl::Model{ "Jump.txt" }, trans, tlr::Blocker::Lane::Left);
	//std::unique_ptr<tlr::Blocker> jumpMid = std::make_unique<tlr::Blocker>(vl::Model{ "Jump.txt" }, trans, tlr::Blocker::Lane::Middle);
	//std::unique_ptr<tlr::Blocker> jumpRight = std::make_unique<tlr::Blocker>(vl::Model{ "Jump.txt" }, trans, tlr::Blocker::Lane::Right);

	//std::unique_ptr<tlr::Blocker> duckLeft = std::make_unique<tlr::Blocker>(vl::Model{ "Duck.txt" }, trans, tlr::Blocker::Lane::Left);
	//std::unique_ptr<tlr::Blocker> duckMid = std::make_unique<tlr::Blocker>(vl::Model{ "Duck.txt" }, trans, tlr::Blocker::Lane::Middle);
	//std::unique_ptr<tlr::Blocker> duckRight = std::make_unique<tlr::Blocker>(vl::Model{ "Duck.txt" }, trans, tlr::Blocker::Lane::Right);

	void generateRandom()
	{
		vl::Transform trans = { vl::Vector2{ 0, 150 }, -math::HALFPI, 0 };
		int pattern = vl::random(2);

		if (pattern == 0)
		{
			scene.Add(std::move(std::make_unique<Coin>(vl::Model{ "Coin.txt" }, trans, Coin::Lane::Left)));
		}
		//if (pattern == 1)
		//{
		//	scene.Add(std::move(std::make_unique<Blocker>(vl::Model{ "Jump.txt" }, trans, Blocker::Lane::Left)));
		//	scene.Add(std::move(std::make_unique<Blocker>(vl::Model{ "Jump.txt" }, trans, Blocker::Lane::Middle)));
		//	scene.Add(std::move(std::make_unique<Blocker>(vl::Model{ "Jump.txt" }, trans, Blocker::Lane::Right)));
		//}
		//if (pattern == 2)
		//{
		//	std::unique_ptr<tlr::Blocker> duckLeft = std::make_unique<tlr::Blocker>(vl::Model{ "Duck.txt" }, trans, tlr::Blocker::Lane::Left);
		//	std::unique_ptr<tlr::Blocker> duckMid = std::make_unique<tlr::Blocker>(vl::Model{ "Duck.txt" }, trans, tlr::Blocker::Lane::Middle);
		//	std::unique_ptr<tlr::Coin> coinRight = std::make_unique<Coin>(vl::Model{ "Coin.txt" }, trans, Coin::Lane::Right);

		//	scene.Add(std::move(duckLeft));
		//	scene.Add(std::move(duckMid));
		//	scene.Add(std::move(coinRight));
		//}

		/**i tried my best to make this work but it doesnt**/
		//switch (pattern)
		//{
		//case 0:
		//	scene.Add(std::move(coinLeft));
		//	break;
		//case 1:
		//	scene.Add(std::move(jumpLeft));
		//	scene.Add(std::move(jumpMid));
		//	scene.Add(std::move(jumpRight));
		//	break;
		//case 2:
		//	scene.Add(std::move(duckLeft));
		//	scene.Add(std::move(duckMid));
		//	scene.Add(std::move(coinRight));
		//	break;
		//case 3:
		//	scene.Add(std::move(coinLeft));
		//	scene.Add(std::move(coinMid));
		//	scene.Add(std::move(coinRight));
		//	break;
		//case 4:
		//	scene.Add(std::move(jumpLeft));
		//	scene.Add(std::move(duckMid));
		//	scene.Add(std::move(jumpRight));
		//	break;
		//}
	}
}