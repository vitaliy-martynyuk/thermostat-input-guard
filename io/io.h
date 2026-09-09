#ifndef IO_H
#define IO_H

#include <string_view>

namespace io
{
	using std::string_view;

	double getTemperature();
	void printGetTemperatureError();
	char getMode();
	void printGetModeError();
	void printConfig(double temp, string_view mode);

	namespace helpers
	{
		bool recoverFromInputError();
	}
}

#endif