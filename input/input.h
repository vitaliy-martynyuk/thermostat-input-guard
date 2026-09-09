#ifndef INPUT_H
#define INPUT_H

#include "../io/io.h"
#include "../validate/validate.h"
#include <iostream>
#include <cstdint>
#include <cassert>

namespace
{
	constexpr int16_t maxInputTries{ 99 };
}

namespace input
{
	using std::cout;
	using std::int16_t;

	inline double setTemperature()
	{
		int count{ 0 };
		while (count < maxInputTries) {
			++count;
			double input{ io::getTemperature() };
			if (io::helpers::recoverFromInputError() || !validate::isTemperatureValid(input)) {
				io::printGetTemperatureError();
				continue;
			}

			cout << '\n';
			return input;
		}

		cout << "\nMaximum amount of attempts reached!\n";
		std::exit(0);
	}

	inline char setMode()
	{
		int count{ 0 };
		while (count < maxInputTries) {
			++count;
			char input{ io::getMode() };
			if (io::helpers::recoverFromInputError() || !validate::isModeValid(input)) {
				io::printGetModeError();
				continue;
			}

			cout << '\n';
			return input;
		}

		cout << "\nMaximum amount of attempts reached!\n";
		std::exit(0);
	}
}

#endif