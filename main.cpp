#include "io/io.h"
#include "validate/validate.h"
#include "consts/consts.h"
#include <iostream>
#include <string_view>

static std::string_view getModeLabel(char modeCode)
{
	switch (modeCode) {
	case consts::modeCode::cool:
		return consts::modeLabel::cool;
	case consts::modeCode::fan:
		return consts::modeLabel::fan;
	case consts::modeCode::heat:
		return consts::modeLabel::heat;
	default:
		return "";
	}
}

static double setTemperature()
{
	while (true) {
		double input{ io::getTemperature() };
		if (io::helpers::recoverFromInputError() || !validate::isTemperatureValid(input)) {
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
		if (io::helpers::recoverFromInputError() || !validate::isModeValid(input)) {
			io::printGetModeError();
			continue;
		}

		std::cout << '\n';
		return input;
	}
}

int main()
{
	double temperature{ setTemperature() };
	char mode{ setMode() };

	io::printConfig(temperature, getModeLabel(mode));

	return 0;
}