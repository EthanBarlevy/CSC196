#include "engine.h"
#include "Enemy.h"
#include "Rocket.h"
#include "Player.h"

namespace tlr
{
	void Enemy::Initalize()
	{
		m_fire = vl::randomf(2, 6);
		m_speed = vl::randomf(20, 70);
	}

	void Enemy::Update()
	{
		//shoot
		m_fire -= (float)vl::g_time.deltaTime;
		if (m_fire <= 0)
		{
			vl::Transform transform = m_transform;
			std::unique_ptr<tlr::Rocket> rocket = std::make_unique<tlr::Rocket>(vl::Model{ "Rocket.txt" }, transform, 2.0f);
			rocket->GetTag() = "enemy";
			m_scene->Add(std::move(rocket));
			m_fire = vl::randomf(2, 6);
		}

		// rotate towards player
		Player* player = m_scene->GetActor<Player>();
		if (player)
		{
			vl::Vector2 direction = player->m_transform.position - m_transform.position;
			m_transform.rotation = direction.GetAngle();
		}

		vl::Vector2 direction{ 1, 0 };
		direction = vl::Vector2::Rotate(direction, m_transform.rotation);

		m_transform.position += (direction * m_speed * (float)vl::g_time.deltaTime);

		if (m_transform.position.x > vl::g_renderer.GetWidth()) m_transform.position.x = 0;
		if (m_transform.position.x < 0) m_transform.position.x = (float)vl::g_renderer.GetWidth();
		if (m_transform.position.y > vl::g_renderer.GetHeight()) m_transform.position.y = 0;
		if (m_transform.position.y < 0) m_transform.position.y = (float)vl::g_renderer.GetHeight();

	}
	void Enemy::OnCollision(Actor* other)
	{
		if (dynamic_cast<Rocket*>(other) && other->GetTag() == "player")
		{
			m_health -= dynamic_cast<Rocket*>(other)->GetDamage();;
			if (m_health <= 0) m_destroy = true;
		}
	}
}

