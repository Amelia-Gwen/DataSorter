#include <chrono>
#include <iostream>

#include "sorting_functions.h"

std::chrono::milliseconds bubble_sort(std::vector<student> data, std::vector<student>& sorted_data, sort_type type)
{
	std::cout << "Sorting with bubble sort. Press C to end sort.\n"
		<< "----------|Finished\n";
	switch (type)
	{
	case sort_type::name:
		break;
	case sort_type::id:
		break;
	case sort_type::score:
		break;
	default:
		std::cerr << "Error selecting sort type. Aborting";
	}
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();


	std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	sorted_data = data;
	return time_passed;
}

std::chrono::milliseconds bucket_sort(std::vector<student> data, sort_type type)
{
	switch (type)
	{
	case sort_type::name:
		break;
	case sort_type::id:
		break;
	case sort_type::score:
		break;
	default:
		std::cerr << "Error selecting sort type. Aborting";
	}
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();


	std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed;
}

std::chrono::milliseconds counting_sort(std::vector<student> data, sort_type type)
{
	switch (type)
	{
	case sort_type::name:
		break;
	case sort_type::id:
		break;
	case sort_type::score:
		break;
	default:
		std::cerr << "Error selecting sort type. Aborting";
	}
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();


	std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed;
}
