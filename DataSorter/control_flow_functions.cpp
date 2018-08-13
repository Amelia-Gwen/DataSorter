#include <algorithm>
#include <iomanip>
#include <iostream>

#include "sorting_functions.h"
#include "timing_function.h"

#include "control_flow_functions.h"

void bruglesco::run_program(std::string file_name)
{
	std::vector<student> data;
	data.reserve(100000);
	std::vector<student> sorted_data;
	sorted_data.reserve(100000);

	stream_source_to_local(data, file_name);

	sort_data(data, sorted_data);

	save_or_sort_again(data, sorted_data);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void bruglesco::sort_data(const std::vector<student>& data, std::vector<student>& sorted_data)
{
	std::cout << "Please select criteria to sort by.\n"
		<< "N for Name.\n"
		<< "I for Student ID.\n"
		<< "S for Score.\n";
	char choice;
	std::cin >> choice;
	sort_three_ways(data, sorted_data, choice);
}

void bruglesco::sort_three_ways(const std::vector<student>& data, std::vector<student>& sorted_data, char choice)
{
	switch (choice)
	{
	case 'n':
	case 'N':
		sort_by(data, sorted_data, sort_by_name);
		break;
	case 'i':
	case 'I':
		sort_by(data, sorted_data, sort_by_id);
		break;
	case 's':
	case 'S':
		sort_by(data, sorted_data, sort_by_score);
		break;
	default:
		std::cerr << "Invalid selection. Please try again.\n";
		sort_data(data, sorted_data);
		break;
	}
}

void bruglesco::sort_by(const std::vector<student>& data, std::vector<student>& sorted_data, bool(*func)(student, student))
{
	timer timer;

	auto bubble_data = data;
	auto merge_data = data;
	auto selection_data = data;
	auto std_data = data;

	timer.start();
	bubble_sort(data.begin(), data.end(), func);
	long long bubble_time = timer.stop();

	timer.start();
	merge_sort(data.begin(), data.end(), func);
	long long merge_time = timer.stop();

	timer.start();
	selection_sort(data.begin(), data.end(), func);
	long long selection_time = timer.stop();

	timer.start();
	std::sort(data.begin(), data.end(), func);
	long long std_time = timer.stop();

	sorted_data = merge_data;

	// display times
}

void bruglesco::save_or_sort_again(const std::vector<student>& data, std::vector<student>& sorted_data)
{
	std::cout << "Would you like to save the sorted data or sort again?\n"
		<< "S for Save.\n"
		<< "R for Retry sorting.\n";
	char choice;
	std::cin >> choice;
	post_sort_selection(data, sorted_data, choice);
}

void bruglesco::post_sort_selection(const std::vector<student>& data, std::vector<student>& sorted_data, char choice)
{
	switch (choice)
	{
	case 's':
	case 'S':
		save_to_file(sorted_data);
		sort_data(data, sorted_data);
		break;
	case 'r':
	case 'R':
		sort_data(data, sorted_data);
		break;
	default:
		std::cerr << "Invalid selection. Please try again.\n";
		save_or_sort_again(data, sorted_data);
		break;
	}
}
