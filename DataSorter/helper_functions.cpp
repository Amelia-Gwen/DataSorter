#include <iostream>
#include <string>

#include "helper_functions.h"
#include "sorting_functions.h"

void save_data_to_memory(std::vector<student>& data, std::string file_name)
{
	std::ifstream source_file{ file_name };
	check_file(source_file);
	std::string throw_away;
	std::string name;
	unsigned id;
	unsigned score;

	// the first row of a csv file are the column types and must be discarded
	source_file >> throw_away >> throw_away >> throw_away;

	while (source_file.peek() != EOF)
	{
		source_file >> name >> id >> score;
		data.emplace_back(student(name, id, score));
	}
}

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

void sort_data(const std::vector<student>& data)
{
	std::cout << "Please select criteria to sort by.\n"
		<< "N for name.\n"
		<< "I for student id.\n"
		<< "S for score.\n";
	char choice;
	std::cin >> choice;
	sort_three_ways(data, choice);
	// offer option to save or to sort again.
}

void sort_three_ways(const std::vector<student>& data, char choice)
{
	switch (choice)
	{
	case 'n':
	case 'N':
		sort_by(data, sort_type::name);
		break;
	case 'i':
	case 'I':
		sort_by(data, sort_type::id);
		break;
	case 's':
	case 'S':
		sort_by(data, sort_type::score);
		break;
	default:
		std::cerr << "Invalid selection. Please try again.\n";
		sort_data(data);
		break;
	}
}

void sort_by(const std::vector<student>& data, sort_type type)
{
	bubble_sort(data, type);
	bucket_sort(data, type);
	counting_sort(data, type);
}