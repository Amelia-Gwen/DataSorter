#include <iostream>
#include <string>

#include "helper_functions.h"

void check_file(std::ifstream& source_file)
{
	if (!source_file)
	{
		std::cerr << "Failure to load file. Please re-enter file name.\n";
		std::string file_name;
		std::cin >> file_name;
		source_file.open(file_name);
		check_file(source_file);
	}
}

void sort_data()
{
	std::cout << "Please select criteria to sort by.\n"
		<< "N for name.\n"
		<< "I for student id.\n"
		<< "S for score.\n";
	char choice;
	std::cin >> choice;
	sort_three_ways(choice);
	// offer option to save or to sort again.
}

void sort_three_ways(char choice)
{
	switch (choice)
	{
	case 'n':
	case 'N':
		// sort by name
		break;
	case 'i':
	case 'I':
		// sort by id
		break;
	case 's':
	case 'S':
		// sort by score
		break;
	default:
		std::cerr << "Invalid selection. Please try again.\n";
		sort_data();
		break;
	}
}
