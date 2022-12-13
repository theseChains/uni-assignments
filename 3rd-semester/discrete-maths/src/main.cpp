#include "Application.h"

#include <exception>
#include <iostream>

int main()
{
	try
	{
		Application application{};
		application.run();
	}
	catch (const std::exception& exception)
	{
		std::cerr << "\nException: " << exception.what() << '\n';
	}

	return 0;
}
