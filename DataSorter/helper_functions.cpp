#include <iostream>
#include <functional>
#include <string>

#include "helper_functions.h"

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
		<< "N for Name.\n"
		<< "I for Student ID.\n"
		<< "S for Score.\n";
	std::vector<student> sorted_data;
	sorted_data.reserve(100);
	char choice;
	std::cin >> choice;
	sort_three_ways(data, sorted_data, choice);
	save_or_sort_again(data, sorted_data);
}

void sort_three_ways(const std::vector<student>& data, std::vector<student>& sorted_data, char choice)
{
	switch (choice)
	{
	case 'n':
	case 'N':
		sort_by(data, sorted_data, sort_type::name);
		break;
	case 'i':
	case 'I':
		sort_by(data, sorted_data, sort_type::id);
		break;
	case 's':
	case 'S':
		sort_by(data, sorted_data, sort_type::score);
		break;
	default:
		std::cerr << "Invalid selection. Please try again.\n";
		sort_data(data);
		break;
	}
}

void sort_by(const std::vector<student>& data, std::vector<student>& sorted_data, sort_type type)
{
	long long bubble_time = bubble_sort(data, sorted_data, type);
	long long bucket_time = bucket_sort(data, type);
	long long merge_time = merge_sort(data, type);

	if (bubble_time < merge_time && bubble_time < bucket_time)
	{
		if (merge_time > bucket_time)
		{
			std::cout << "merge " << merge_time << "ms.\n"
				<< "bucket " << bucket_time << "ms.\n"
				<< "bubble " << bubble_time << "ms.\n";
		}
		else
		{
			std::cout << "bucket " << bucket_time << "ms.\n"
				<< "merge " << merge_time << "ms.\n"
				<< "bubble " << bubble_time << "ms.\n";
		}
	}
	else
	{
		if (merge_time > bubble_time)
		{
			std::cout << "merge " << merge_time << "ms.\n"
				<< "bubble " << bubble_time << "ms.\n"
				<< "bucket " << bucket_time << "ms.\n";
		}
		else if (bucket_time > bubble_time)
		{
			std::cout << "bucket " << bucket_time << "ms.\n"
				<< "bubble " << bubble_time << "ms.\n"
				<< "merge " << merge_time << "ms.\n";
		}
		else
		{
			if (merge_time > bucket_time)
			{
				std::cout << "bubble " << bubble_time << "ms.\n"
					<< "merge " << merge_time << "ms.\n"
					<< "bucket " << bucket_time << "ms.\n";
			}
			else
			{
				std::cout << "bubble " << bubble_time << "ms.\n"
					<< "bucket " << bucket_time << "ms.\n"
					<< "merge " << merge_time << "ms.\n";
			}
		}
	}
}

void save_or_sort_again(const std::vector<student>& data, const std::vector<student>& sorted_data)
{
	std::cout << "Would you like to save the sorted data or sort again?\n"
		<< "S for Save.\n"
		<< "R for Retry sorting.\n";
	char choice;
	std::cin >> choice;
	post_sort_selection(data, sorted_data, choice);
}

void post_sort_selection(const std::vector<student>& data, const std::vector<student>& sorted_data, char choice)
{
	switch (choice)
	{
	case 's':
	case 'S':
		save_to_file(sorted_data);
		break;
	case 'r':
	case 'R':
		sort_data(data);
		break;
	default:
		std::cerr << "Invalid selection. Please try again.\n";
		save_or_sort_again(data, sorted_data);
		break;
	}
}

void save_to_file(const std::vector<student>& data)
{
	std::cout << "Please provide a name for your file.\n"
		<< "Note: Data will be saved to current path.\n"
		<< "If file name exists it will be overwritten.\n";
	std::string file_name;
	std::cin >> file_name;
	std::ofstream write_file{ file_name };
	if (!write_file)
	{
		std::cerr << "File could not be opened. Please try again.\n";
		save_to_file(data);
	}
	write_file << "NAME,ID,SCORE\n";
	for (auto&& student : data)
	{
		write_file << student.name << ','
			<< student.id << ','
			<< student.score << '\n';
	}
	sort_data(data);
}
