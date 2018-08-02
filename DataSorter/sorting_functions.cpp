#include <chrono>
#include <iostream>

#include "sorting_functions.h"

auto bubble_sort_timer(std::vector<student> data, std::vector<student>& sorted_data, sort_type type)
{
	std::cout << "Sorting with bubble sort. Press C to end sort.\n"
		<< "----------|Finished\n";

	auto start = std::chrono::steady_clock::now();

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
		break;
	};

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	sorted_data = data;
	return time_passed;
}

auto bucket_sort_timer(std::vector<student> data, sort_type type)
{
	std::cout << "Sorting with bucket sort. Press C to end sort.\n"
		<< "----------|Finished\n";
	auto start = std::chrono::steady_clock::now();

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
		break;
	};

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed;
}

auto counting_sort_timer(std::vector<student> data, sort_type type)
{
	std::cout << "Sorting with counting sort. Press C to end sort.\n"
		<< "----------|Finished\n";
	auto start = std::chrono::steady_clock::now();

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
		break;
	};

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed;
}
