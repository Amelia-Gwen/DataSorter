#include <iostream>
#include <functional>
#include <string>
#include <sstream>

#include "sorting_functions.h"
#include "timing_function.h"

#include "helper_functions.h"

namespace bruglesco {

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
			sort_data(data);
			break;
		}
	}

	void sort_by(const std::vector<student>& data, std::vector<student>& sorted_data, bool(*func)(student, student))
	{
		timer timer;

		timer.start();
		bubble_sort(data.begin(), data.end(), func);
		long long bubble_time = timer.stop();

		timer.start();
		merge_sort(data.begin(), data.end(), func);
		long long merge_time = timer.stop();

		timer.start();
		selection_sort(data.begin(), data.end(), func);
		long long selection_time = timer.stop();



		// rewrite this dynamically
		if (bubble_time > selection_time && bubble_time > merge_time)
		{
			if (selection_time < merge_time)
			{
				std::cout << "selection " << selection_time << "ms.\n"
					<< "merge " << merge_time << "ms.\n"
					<< "bubble " << bubble_time << "ms.\n";
			}
			else
			{
				std::cout << "merge " << merge_time << "ms.\n"
					<< "selection " << selection_time << "ms.\n"
					<< "bubble " << bubble_time << "ms.\n";
			}
		}
		else
		{
			if (selection_time < bubble_time)
			{
				std::cout << "selection " << selection_time << "ms.\n"
					<< "bubble " << bubble_time << "ms.\n"
					<< "merge " << merge_time << "ms.\n";
			}
			else if (merge_time < bubble_time)
			{
				std::cout << "merge " << merge_time << "ms.\n"
					<< "bubble " << bubble_time << "ms.\n"
					<< "selection " << selection_time << "ms.\n";
			}
			else
			{
				if (selection_time < merge_time)
				{
					std::cout << "bubble " << bubble_time << "ms.\n"
						<< "selection " << selection_time << "ms.\n"
						<< "merge " << merge_time << "ms.\n";
				}
				else
				{
					std::cout << "bubble " << bubble_time << "ms.\n"
						<< "merge " << merge_time << "ms.\n"
						<< "selection " << selection_time << "ms.\n";
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
			sort_data(data);
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
}
