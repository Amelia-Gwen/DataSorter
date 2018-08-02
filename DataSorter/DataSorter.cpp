// DataSorter.cpp : Defines the entry point for the console application.
//
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "helper_functions.h"

int main(int argc, char* argv[])
{

	std::string file_name;
	if (argc == 0 || argc == 1)
	{
		std::cout << "Please enter a filename.\n";
		std::cin >> file_name;
	}
	else if (argc == 2)
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

	std::string name;
	unsigned id;
	unsigned score;
	std::vector<student> data;
	data.reserve(100000);
	while (!source_file.eofbit)
	{
		source_file >> name >> id >> score;
		data.emplace_back(student(name, id, score));
	}

	std::cout << "Please select criteria to sort by.\n"
		<< "N for name.\n"
		<< "I for student id.\n"
		<< "S for score.\n";

	// take input selection

	// sort column via algorithm one
	// sort by algorithm two
	// sort by algorithm three

	// display results

	// offer user opportunity to save

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
