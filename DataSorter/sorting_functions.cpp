#include <conio.h>

#include <algorithm>
#include <chrono>
#include <iostream>

#include "sorting_functions.h"

void bubble_sort_timer(std::vector<student> data, std::vector<student>& sorted_data, sort_type type)
{
	std::cout << "Sorting with bubble sort. Press C to end sort.\n"
		<< "----------|Finished\n";

	auto start = std::chrono::steady_clock::now();

	auto last_unsorted{ data.size() - 1 };
	auto count = 0;
	bool stopped{ false };

	switch (type)
	{
	case sort_type::name:
		while (last_unsorted > 0 && !stopped)
		{
			for (auto i = 0; i < last_unsorted - 1; ++i)
			{
				if (data[i].name > data[i + 1].name)
				{
					std::swap(data[i], data[i + 1]);
				}

				if (_kbhit)
				{
					char key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}
			}
			--last_unsorted;
			++count;
			if (count == data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << '*';
		break;
	case sort_type::id:
		while (last_unsorted > 0 && !stopped)
		{
			for (auto i = 0; i < last_unsorted - 1; ++i)
			{
				if (data[i].id > data[i + 1].id)
				{
					std::swap(data[i], data[i + 1]);
				}

				if (_kbhit)
				{
					char key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}
			}
			--last_unsorted;
			++count;
			if (count == data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		break;
	case sort_type::score:
		while (last_unsorted > 0 && !stopped)
		{
			for (auto i = 0; i < last_unsorted - 1; ++i)
			{
				if (data[i].score > data[i + 1].score)
				{
					std::swap(data[i], data[i + 1]);
				}

				if (_kbhit)
				{
					char key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}
			}
			--last_unsorted;
			++count;
			if (count == data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		break;
	default:
		std::cerr << "Error selecting sort type. Aborting";
		break;
	};

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	sorted_data = data;
}

void bucket_sort_timer(std::vector<student> data, sort_type type)
{
	std::cout << "Sorting with bucket sort. Press C to end sort.\n"
		<< "----------|Finished\n";
	auto start = std::chrono::steady_clock::now();

	auto last_unsorted{ data.size() - 1 };
	auto count = 0;
	bool stopped{ false };

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
}

void counting_sort_timer(std::vector<student> data, sort_type type)
{
	std::cout << "Sorting with counting sort. Press C to end sort.\n"
		<< "----------|Finished\n";
	auto start = std::chrono::steady_clock::now();

	auto last_unsorted{ data.size() - 1 };
	auto count = 0;
	bool stopped{ false };

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
}
