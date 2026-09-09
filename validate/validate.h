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
		switch (mode) {
		case consts::modeCode::cool:
		case consts::modeCode::fan:
		case consts::modeCode::heat:
			return true;
		default:
			return false;
		}
	}
}

#endif
