#ifndef IO_H
#define IO_H

namespace io
{
	double getTemperature();
	void printGetTemperatureError();
	char getMode();
	void printGetModeError();
	void printConfig(double temp, char mode);

	namespace helpers
	{
		bool checkInputExtractionErrors();
	}
}

#endif