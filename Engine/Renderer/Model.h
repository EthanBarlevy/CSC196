#pragma once
#include "renderer.h"
#include <vector>

namespace vl 
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<vl::Vector2>& points, const vl::Color& color) : m_points{ points }, m_color{ color } {}
		~Model() = default;

		void Draw(Renderer& renderer, const Vector2& position, float angle, float scale = 1);

	private:
		vl::Color m_color;
		std::vector<vl::Vector2> m_points;
	};
}