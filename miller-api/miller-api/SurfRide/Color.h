#pragma once

namespace SurfRide
{
	struct Color
	{
		unsigned char r{};
		unsigned char g{};
		unsigned char b{};
		unsigned char a{};

		Color operator*(const Color&);
	};

	struct Colorf
	{
		float a{};
		float r{};
		float g{};
		float b{};
	};
}
