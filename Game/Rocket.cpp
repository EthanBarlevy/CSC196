#include "engine.h"
#include "Rocket.h"
#include "Player.h"
#include "Enemy.h"

namespace tlr
{
	void Rocket::Update()
	{

		m_lifespan -= (float)vl::g_time.deltaTime;
		if (m_lifespan <= 0) { m_destroy = true; }

		vl::Vector2 direction{ 1, 0 };
		direction = vl::Vector2::Rotate(direction, m_transform.rotation);

		m_transform.position += (direction * m_speed * (float)vl::g_time.deltaTime);

			
	}
	void Rocket::OnCollision(Actor* other)
	{
		if (dynamic_cast<Player*>(other) && m_tag != "player")
		{
			m_destroy = true;
		}
		if (dynamic_cast<Enemy*>(other) && m_tag != "enemy")
		{
			m_destroy = true;
		}
	}
}
