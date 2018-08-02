#include <chrono>
#include <iostream>

#include "sorting_functions.h"

void bubble_sort(std::vector<student> data, std::vector<student>& sorted_data, sort_type type)
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
	// start time

	// end time
	sorted_data = data;
}

void bucket_sort(std::vector<student> data, sort_type type)
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
	// start time

	// end time
}

void counting_sort(std::vector<student> data, sort_type type)
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
	// start time

	// end time
}
