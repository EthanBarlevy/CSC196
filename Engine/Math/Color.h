#pragma once
#include <cstdint>

namespace vl
{
	//typedef unsigned char u8_t
	//using u8_t = unsigned char
	struct Color 
	{
		uint8_t r, g, b, a;
	};
	inline std::istream& operator >> (std::istream& stream, Color& c)
	{
		std::string line;
		std::getline(stream, line);

		c.r = 255;
		c.g = 255;
		c.b = 255;

		c.a = 255;

		return stream;
	}
}