#ifndef BRUGLESCO_DATASORTER_CONTROL_FLOW_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_CONTROL_FLOW_FUNCTIONS_H

#include <functional>
#include <map>
#include <string>
#include <vector>

#include "data_functions.h"

namespace bruglesco
{
	void run_program(std::string file_name);

	void sort_data(std::vector<student>& data, std::vector<student>& sorted_data);

	void sort_three_ways(std::vector<student>& data, std::vector<student>& sorted_data, char choice);

	void sort_by(std::vector<student>& data, std::vector<student>& sorted_data, bool(*func)(student, student));

	void display_times(std::map<long long, std::string> times);

	void inline display_time(long long ms, std::string sort_name) { std::cout << sort_name << " took " << ms << "ms\n"; }

	void save_or_sort_again(std::vector<student>& data, std::vector<student>& sorted_data);

	void post_sort_selection(std::vector<student>& data, std::vector<student>& sorted_data, char choice);
}
#endif // !BRUGLESCO_DATASORTER_CONTROL_FLOW_FUNCTIONS_H
