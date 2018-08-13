#include <iostream>
#include <sstream>

#include "data_functions.h"

void bruglesco::stream_source_to_local(std::vector<student>& data, std::string file_name)
{
	std::ifstream source_file{ file_name };
	check_file(source_file);
	std::string row;
	std::string name;
	unsigned id;
	unsigned score;
	std::vector<std::string> raw_values;

	// the first row of a csv file are the column types and must be discarded
	source_file >> row;

	while (std::getline(source_file, row))
	{
		std::istringstream lineparse(row);
		std::string cell;

		while (std::getline(lineparse, cell, ','))
		{
			raw_values.push_back(cell);
		}
	}

	for (std::size_t i = 0; i < raw_values.size(); i += 3)
	{
		name = raw_values[i];
		id = std::stoi(raw_values[i + 1]);
		score = std::stoi(raw_values[i + 2]);

		data.emplace_back(student(name, id, score));
	}
}

void bruglesco::save_to_file(const std::vector<student>& data)
{
	std::cout << "Please provide a name for your file.\n"
		"Note: Data will be saved to current path.\n"
		"If file name exists it will be overwritten.\n";

	std::string file_name;
	std::cin >> file_name;
	std::ofstream write_file{ file_name };
	check_file(write_file);

	write_file << "NAME,ID,SCORE\n";
	for (auto& student : data)
	{
		write_file << student.name << ',' << student.id << ',' << student.score << '\n';
	}
}

void bruglesco::check_file(std::ifstream& source)
{
	if (!source)
	{
		std::cerr << "Failure to load file. Please re-enter file name.\n";
		std::string file_name;
		std::cin >> file_name;
		source.open(file_name);
		check_file(source);
	}
}

void bruglesco::check_file(std::ofstream & write_file)
{
	if (!write_file)
	{
		std::cerr << "Failure to create file. Please re-enter file name.\n";
		std::string file_name;
		std::cin >> file_name;
		write_file.open(file_name);
		check_file(write_file);
	}
}
