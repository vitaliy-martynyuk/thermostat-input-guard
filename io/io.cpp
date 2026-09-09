#include "io.h"
#include <iostream>

namespace io
{
	using std::cin;
	using std::cout;

	double getTemperature()
	{
		cout << "Enter target temperature: ";
		double input{};
		cin >> input;

		return input;
	}

	void printGetTemperatureError()
	{
		cout << "Invalid input. Please enter a number.\n";
	}

	char getMode()
	{
		cout << "Enter mode (H = Heat, C = Cool, F = Fan): ";
		char input{};
		cin >> input;

		return input;
	}

	void printGetModeError()
	{
		cout << "Invalid mode. Please enter H, C, or F.\n";
	}

	void printConfig(double temp, char mode)
	{
		cout << "Target: " << temp << " degrees\n";
		cout << "Mode: " << mode << "\n\n";
		cout << "Thermostat set successfully.\n";
	}
}