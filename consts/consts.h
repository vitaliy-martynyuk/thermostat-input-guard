#ifndef CONSTS_H
#define CONSTS_H

#include <string_view>
#include <cassert>

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

	// Precondition: modeCode has already been validated by validate::isModeValid().
	// Postcondition: returns the non-empty display label corresponding to modeCode.
	inline string_view getModeLabel(char mode)
	{
		switch (mode) {
		case modeCode::cool:
			return modeLabel::cool;
		case modeCode::fan:
			return modeLabel::fan;
		case modeCode::heat:
			return modeLabel::heat;
		default:
			assert(false && "Invalid mode code!");
			return "";
		}
	}
}

#endif