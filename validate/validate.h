#ifndef VALIDATE_H
#define VALIDATE_H

#include "../consts/consts.h"

namespace validate
{
	inline bool isTemperatureValid(double temp)
	{
		return (temp >= 0.0) && (temp <= 100.0);
	}

	inline bool isModeValid(char mode)
	{
		using namespace consts;

		switch (mode) {
		case modeCode::cool:
		case modeCode::fan:
		case modeCode::heat:
			return true;
		default:
			return false;
		}
	}
}

#endif
