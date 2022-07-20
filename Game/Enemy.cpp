#include "engine.h"
#include "Enemy.h"

namespace tlr
{
	void Enemy::Update()
	{
		vl::Vector2 direction{ 1, 0 };
		direction = vl::Vector2::Rotate(direction, m_transform.rotation);

		m_transform.position += (direction * m_speed * vl::g_time.deltaTime);

		if (m_transform.position.x > vl::g_renderer.GetWidth()) m_transform.position.x = 0;
		if (m_transform.position.x < 0) m_transform.position.x = vl::g_renderer.GetWidth();
		if (m_transform.position.y > vl::g_renderer.GetHeight()) m_transform.position.y = 0;
		if (m_transform.position.y < 0) m_transform.position.y = vl::g_renderer.GetHeight();

	}
}

