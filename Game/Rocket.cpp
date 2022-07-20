#include "engine.h"
#include "Rocket.h"

namespace tlr
{
	void Rocket::Update()
	{
		vl::Vector2 direction{ 1, 0 };
		direction = vl::Vector2::Rotate(direction, m_transform.rotation);

		m_transform.position += (direction * m_speed * vl::g_time.deltaTime);
	}
}
