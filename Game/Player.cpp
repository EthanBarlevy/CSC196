#include "engine.h"
#include "Player.h"

namespace tlr
{
	void Player::Update()
	{
		// rotate with left-right
		if (g_inputSystem.GetKeyDown(vl::key_left))
		{
			m_transform.rotation -= 0.03f;
		}

		if (g_inputSystem.GetKeyDown(vl::key_right))
		{
			m_transform.rotation += 0.03f;
		}

		// move input
		m_speed = 0;
		if (g_inputSystem.GetKeyDown(vl::key_up))
		{
			m_speed = m_maxSpeed;
		}

		// face target (mouse)
		vl::Vector2 target = g_inputSystem.GetMousePosition();
		target -= m_transform.position;
		m_transform.rotation = target.GetAngle();

		// move
		vl::Vector2 direction{ 1, 0 };
		direction = vl::Vector2::Rotate(direction, m_transform.rotation);

		m_transform.position += (direction * m_speed);

		// mouse input
		if (g_inputSystem.GetButtonDown(vl::button_left))
		{
			//cout << g_inputSystem.GetButtonState(vl::button_left) << "  :  " << g_inputSystem.GetMousePosition().x << ", " << g_inputSystem.GetMousePosition().y << endl;
		}
	}
}