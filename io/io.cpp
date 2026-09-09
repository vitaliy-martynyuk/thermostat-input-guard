#include "io.h"
#include <iostream>
#include <limits>
#include <string_view>

namespace io
{
	using std::cin;
	using std::cout;
	using std::numeric_limits;
	using std::streamsize;
	using std::string_view;

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

	void printConfig(double temp, string_view mode)
	{
		cout << "Target: " << temp << " degrees\n";
		cout << "Mode: " << mode << "\n\n";
		cout << "Thermostat set successfully.\n";
	}

	namespace helpers
	{
		bool recoverFromInputError()
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