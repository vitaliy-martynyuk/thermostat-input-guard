#include "io.h"
#include <iostream>
#include <limits>

namespace io
{
	using std::cin;
	using std::cout;
	using std::numeric_limits;
	using std::streamsize;

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

	namespace helpers
	{
		bool checkInputExtractionErrors()
		{
			const bool hasUnextractedInput{ !cin.eof() && cin.peek() != '\n' };

			if (!cin || hasUnextractedInput) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				return true;
			}

			return false;
		}
	}
}