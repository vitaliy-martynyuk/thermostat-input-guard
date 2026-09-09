#include "io/io.h"
#include <iostream>

int main()
{
	io::getTemperature();
	io::getMode();

	io::printConfig(71.5, 'H');

	return 0;
}