#ifndef CONSTS_H
#define CONSTS_H

#include <string_view>

namespace consts
{
	using std::string_view;

	namespace modeLabel
	{
		constexpr string_view heat{ "Heat" };
		constexpr string_view cool{ "Cool" };
		constexpr string_view fan{ "Fan" };
	}

	namespace modeCode
	{
		constexpr char heat{ 'H' };
		constexpr char cool{ 'C' };
		constexpr char fan{ 'F' };
	}
}

#endif