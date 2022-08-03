#include <iostream>

int main(int argc, char** args)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			std::cout << args[i] << "\n";
	}
	else std::cout << "No arguments to print\n";
	return 0;
}