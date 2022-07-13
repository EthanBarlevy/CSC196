#include "model.h"

namespace vl 
{
	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
	{
		// draw
		// 
		//vl::Color color;
		//color.a = 255;
		//color.r = vl::random(256);
		//color.g = vl::random(256);
		//color.b = vl::random(256);


		for (int i = 0; i < m_points.size(); i++)
		{
			vl::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			vl::Vector2 p2 = Vector2::Rotate((m_points[(i + 1) % m_points.size()] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}
	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		for (int i = 0; i < m_points.size(); i++)
		{
			vl::Vector2 p1 = Vector2::Rotate((m_points[i] * transform.scale), transform.rotation) + transform.position;
			vl::Vector2 p2 = Vector2::Rotate((m_points[(i + 1) % m_points.size()] * transform.scale), transform.rotation) + transform.position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}
}