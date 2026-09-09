#ifndef CONSTS_H
#define CONSTS_H

#include <string_view>

namespace consts
{
	using std::string_view;

	namespace modeLabel
	{
		inline constexpr string_view heat{ "Heat" };
		inline constexpr string_view cool{ "Cool" };
		inline constexpr string_view fan{ "Fan" };
	}

	namespace modeCode
	{
		inline constexpr char heat{ 'H' };
		inline constexpr char cool{ 'C' };
		inline constexpr char fan{ 'F' };
	}
}

#endif