// DataSorter.cpp : Defines the entry point for the console application.
//
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "helper_functions.h"

int main(int argc, char* argv[])
{
	std::string file_name;
	if (argc == 0 || argc == 1)
	{
		std::cout << "Please enter a filename.\n";
		std::cin >> file_name;
	}
	if (argc == 2)
	{
		file_name = argv[2];
	}
	else
	{
		std::cerr << "Too many command line arguments.\n";
		std::cout << "Please enter a file name.\n";
		std::cin >> file_name;
	}

	std::ifstream source_file{ file_name };

	check_file(source_file);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
