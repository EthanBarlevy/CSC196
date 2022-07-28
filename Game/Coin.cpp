#include "Coin.h"
#include "Player.h"
#include "engine.h"

namespace tlr
{
	void Coin::OnCollision(Actor* other)
	{
		if (dynamic_cast<Player*>(other) && m_transform.position.y < 450)
		{
			m_destroy = true;
			m_scene->GetGame()->addPoints(100);
			vl::g_audioSystem.PlayAudio("coin");
		}
	}
}
