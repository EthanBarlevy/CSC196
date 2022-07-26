#include "engine.h"
#include "Rocket.h"

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
}
