#include "engine.h"
#include "Player.h"
#include "Rocket.h"
#include "Blocker.h"

namespace tlr
{
	void Player::Update()
	{

		// swap between lanes
		if (vl::g_inputSystem.GetKeyState(vl::key_left) == vl::g_inputSystem.Pressed &&
			m_lane != Lane::Left)
		{
			m_transform.rotation += math::DegToRad(15);
			m_transform.position.x -= sin(math::DegToRad(15)) * 500;

			if (m_lane == Lane::Middle) m_lane = Lane::Left;
			if (m_lane == Lane::Right) m_lane = Lane::Middle;
		}

		if (vl::g_inputSystem.GetKeyState(vl::key_right) == vl::g_inputSystem.Pressed &&
			m_lane != Lane::Right)
		{
			m_transform.rotation -= math::DegToRad(15);
			m_transform.position.x += sin(math::DegToRad(15)) * 500;

			if (m_lane == Lane::Middle) m_lane = Lane::Right;
			if (m_lane == Lane::Left) m_lane = Lane::Middle;
		}

		// jump and duck
		if (vl::g_inputSystem.GetKeyState(vl::key_up) == vl::g_inputSystem.Pressed && m_tag != "jump")
		{
			m_tag = "jump";
			m_jumpTime = 45;

			if (m_tag == "duck") m_duckTime = 0;
		}
		else if (vl::g_inputSystem.GetKeyState(vl::key_down) == vl::g_inputSystem.Pressed && m_tag != "duck")
		{
			m_tag = "duck";
			m_duckTime = 45;

			if (m_tag == "jump") m_jumpTime = 0;
		}
		else 
		{
			m_jumpTime--;
			m_duckTime--;

			if(m_jumpTime <= 0 && m_duckTime <= 0) m_tag = "idle";
		}

		if (m_tag == "jump") m_model.GetColor() = { 255, 0, 0, 255 };
		if (m_tag == "duck") m_model.GetColor() = { 0, 0, 255, 255 };
		if (m_tag == "idle") m_model.GetColor() = { 255, 191, 255, 255 };

		/***Yah real unfortuante that I made a completely different game and none of this is needed***/

		// rotate with left-right
		//if (vl::g_inputSystem.GetKeyDown(vl::key_left))
		//{
		//	m_transform.rotation -= math::PI * (float)vl::g_time.deltaTime;
		//}

		//if (vl::g_inputSystem.GetKeyDown(vl::key_right))
		//{
		//	m_transform.rotation += math::PI * (float)vl::g_time.deltaTime;
		//}

		// face target (mouse)
		//vl::Vector2 target = g_inputSystem.GetMousePosition();
		//target -= m_transform.position;
		//m_transform.rotation = target.GetAngle();

		// move input
		//m_speed = 0;
		//if (vl::g_inputSystem.GetKeyDown(vl::key_up))
		//{
		//	m_speed = m_maxSpeed;
		//}

		// mouse input
		//if (g_inputSystem.GetButtonDown(vl::button_left))
		//{
		//	//cout << g_inputSystem.GetButtonState(vl::button_left) << "  :  " << g_inputSystem.GetMousePosition().x << ", " << g_inputSystem.GetMousePosition().y << endl;
		//}

		// force
		//vl::Vector2 direction{ 1, 0 };
		//direction = vl::Vector2::Rotate(direction, m_transform.rotation);
		//vl::Vector2 force = (direction * m_speed * (float)vl::g_time.deltaTime);
		//// acceleration
		//m_velocity += force;
		//// drag
		//m_damping = 1.50f;
		//m_velocity *= 1.0f / (1.0f + m_damping * (float)vl::g_time.deltaTime);

		//// move
		//m_transform.position += m_velocity * (float)vl::g_time.deltaTime;

		// shoot 
		//if (vl::g_inputSystem.GetKeyState(vl::key_space) == vl::g_inputSystem.Pressed)
		//{
		//	vl::Transform transform = m_transform;
		//	std::unique_ptr<tlr::Rocket> rocket = std::make_unique<tlr::Rocket>(vl::Model{ "Rocket.txt" }, transform, 3);
		//	rocket->GetTag() = "player";
		//	m_scene->Add(std::move(rocket));

		//	vl::g_audioSystem.PlayAudio("laser");
		//}

		//wrap
		//if (m_transform.position.x > vl::g_renderer.GetWidth()) m_transform.position.x = 0;
		//if (m_transform.position.x < 0) m_transform.position.x = (float)vl::g_renderer.GetWidth();
		//if (m_transform.position.y > vl::g_renderer.GetHeight()) m_transform.position.y = 0;
		//if (m_transform.position.y < 0) m_transform.position.y = (float)vl::g_renderer.GetHeight();
	}

	void Player::OnCollision(Actor* other)
	{
		//if (dynamic_cast<Rocket*>(other) && other->GetTag() == "enemy")
		//{
		//	m_health -= dynamic_cast<Rocket*>(other)->GetDamage();;
		//	if (m_health <= 0)
		//	{
		//		m_destroy = true;
		//	}
		//}

		if (dynamic_cast<Blocker*>(other))
		{
			if (m_tag != other->GetTag() && other->GetTransform().position.y < 450)
			{
				vl::g_audioSystem.PlayAudio("explosion"); 
				m_destroy = true;
			}
		}
	}
}