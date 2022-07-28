#include "OnRailsObject.h"
#include "engine.h"
#include "Player.h"

namespace tlr 
{
	void onRailsObject::Update()
	{
		m_transform.position.y += (float)vl::g_time.deltaTime * (m_transform.position.y / 2.5f);
		m_transform.scale = math::map(m_transform.position.y, 150, 500, 1, 5.5);

		// i am just going to hard code this
		// the window cant be resized so its fine
		switch (m_lane) 
		{
		case Lane::Left:
			m_transform.position.x = 230 - (sin(math::DegToRad(15)) * m_transform.position.y);
			break;
		case Lane::Middle:
			break;
		case Lane::Right:
			m_transform.position.x = 270 + (sin(math::DegToRad(15)) * m_transform.position.y);
			break;
		default:
			break;
		}

		if (m_transform.position.y >= 550) m_destroy = true;
	}
}
