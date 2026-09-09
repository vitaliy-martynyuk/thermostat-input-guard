#include "io/io.h"
#include "validate/validate.h"
#include <iostream>

static double setTemperature()
{
	while (true) {
		double input{ io::getTemperature() };
		if (io::helpers::checkInputExtractionErrors() || !validate::isTemperatureValid(input)) {
			io::printGetTemperatureError();
			continue;
		}

		std::cout << '\n';
		return input;
	}
}

static char setMode()
{
	while (true) {
		char input{ io::getMode() };
		if (io::helpers::checkInputExtractionErrors() || !validate::isModeValid(input)) {
			io::printGetModeError();
			continue;
		}

		std::cout << '\n';
		return input;
	}
}

int main()
{
	[[maybe_unused]] double temperature{ setTemperature() };
	[[maybe_unused]] char mode{ setMode() };

	io::printConfig(71.5, 'H');

	return 0;
}