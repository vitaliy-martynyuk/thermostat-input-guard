#include "input/input.h"
#include "consts/consts.h"

int main()
{
	double temperature{ input::setTemperature() };
	char mode{ input::setMode() };

	io::printConfig(temperature, consts::getModeLabel(mode));

	return 0;
}