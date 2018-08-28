#include "control_flow_functions.h"

#include "sorting_functions.h"
#include "timing_function.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

void inline display_time(long long ms, std::string sort_name) { std::cout << sort_name << " took " << ms << "ms\n"; }

void bruglesco::run_program(std::string file_name)
{
	std::vector<student> data;
	data.reserve(100000);

	stream_source_to_local(data, file_name);

	std::vector<student> sorted_data = data;

	sort_data(data, sorted_data);

	save_or_sort_again(data, sorted_data);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void bruglesco::sort_data(std::vector<student>& data, std::vector<student>& sorted_data)
{
	std::cout << "Please select criteria to sort by.\n"
		"N for Name.\n"
	    "I for Student ID.\n"
		"S for Score.\n";
	char choice;
	std::cin >> choice;
	sort_three_ways(data, sorted_data, choice);
}

void bruglesco::sort_three_ways(std::vector<student>& data, std::vector<student>& sorted_data, char choice)
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

void bruglesco::sort_by(std::vector<student>& data, std::vector<student>& sorted_data, bool(*func)(student, student))
{
	timer timer;

	auto bubble_data = data;
	timer.start();
	bubble_sort(bubble_data.begin(), bubble_data.end(), func);
	long long bubble_time = timer.stop();

	auto selection_data = data;
	timer.start();
	selection_sort(selection_data.begin(), selection_data.end(), func);
	long long selection_time = timer.stop();

	auto merge_data = data;
	timer.start();
	merge_sort(merge_data.begin(), merge_data.end(), func);
	long long merge_time = timer.stop();

	auto std_data = data;
	timer.start();
	std::sort(std_data.begin(), std_data.end(), func);
	long long std_time = timer.stop();

	sorted_data = selection_data;

	std::map<long long, std::string> sorted_times;
	sorted_times.insert(std::pair<long long, std::string>(bubble_time, "bubble sort"));
	sorted_times.insert(std::pair<long long, std::string>(merge_time, "merge sort"));
	sorted_times.insert(std::pair<long long, std::string>(selection_time, "selection sort"));
	sorted_times.insert(std::pair<long long, std::string>(std_time, "std sort"));

	display_times(sorted_times);
}

void bruglesco::display_times(std::map<long long, std::string> times)
{
	for (auto& time : times)
	{
		display_time(time.first, time.second);
	}
}

void bruglesco::save_or_sort_again(std::vector<student>& data, std::vector<student>& sorted_data)
{
	std::cout << "Would you like to save the sorted data or sort again?\n"
	    "S for Save.\n"
		"R for Retry sorting.\n";
	char choice;
	std::cin >> choice;
	post_sort_selection(data, sorted_data, choice);
}

void bruglesco::post_sort_selection(std::vector<student>& data, std::vector<student>& sorted_data, char choice)
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
