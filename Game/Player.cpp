#include "engine.h"
#include "Player.h"
#include "Rocket.h"

namespace tlr
{
	void Player::Update()
	{
		// rotate with left-right
		if (vl::g_inputSystem.GetKeyDown(vl::key_left))
		{
			m_transform.rotation -= math::PI * vl::g_time.deltaTime;
		}

		if (vl::g_inputSystem.GetKeyDown(vl::key_right))
		{
			m_transform.rotation += math::PI * vl::g_time.deltaTime;
		}

		// face target (mouse)
		//vl::Vector2 target = g_inputSystem.GetMousePosition();
		//target -= m_transform.position;
		//m_transform.rotation = target.GetAngle();

		// move input
		m_speed = 0;
		if (vl::g_inputSystem.GetKeyDown(vl::key_up))
		{
			m_speed = m_maxSpeed;
		}

		// mouse input
		//if (g_inputSystem.GetButtonDown(vl::button_left))
		//{
		//	//cout << g_inputSystem.GetButtonState(vl::button_left) << "  :  " << g_inputSystem.GetMousePosition().x << ", " << g_inputSystem.GetMousePosition().y << endl;
		//}

		// move
		vl::Vector2 direction{ 1, 0 };
		direction = vl::Vector2::Rotate(direction, m_transform.rotation);

		m_transform.position += (direction * m_speed * vl::g_time.deltaTime);

		// shoot 
		if (vl::g_inputSystem.GetKeyState(vl::key_space) == vl::g_inputSystem.Pressed)
		{
			vl::Transform transform = m_transform;
			std::unique_ptr<tlr::Rocket> rocket = std::make_unique<tlr::Rocket>(vl::Model{ "Rocket.txt" }, transform);
			scene->Add(std::move(rocket));;
		}

		//wrap
		if (m_transform.position.x > vl::g_renderer.GetWidth()) m_transform.position.x = 0;
		if (m_transform.position.x < 0) m_transform.position.x = vl::g_renderer.GetWidth();
		if (m_transform.position.y > vl::g_renderer.GetHeight()) m_transform.position.y = 0;
		if (m_transform.position.y < 0) m_transform.position.y = vl::g_renderer.GetHeight();
	}
}