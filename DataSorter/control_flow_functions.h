#ifndef BRUGLESCO_DATASORTER_CONTROL_FLOW_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_CONTROL_FLOW_FUNCTIONS_H

#include <string>
#include <vector>

#include "data_functions.h"

namespace bruglesco
{
	void run_program(std::string file_name);

	void sort_data(const std::vector<student>& data, std::vector<student>& sorted_data);

	void sort_three_ways(const std::vector<student>& data, std::vector<student>& sorted_data, char choice);

	void sort_by(const std::vector<student>& data, std::vector<student>& sorted_data, bool(*func)(student, student));

	void save_or_sort_again(const std::vector<student>& data, std::vector<student>& sorted_data);

	void post_sort_selection(const std::vector<student>& data, std::vector<student>& sorted_data, char choice);
}
#endif // !BRUGLESCO_DATASORTER_CONTROL_FLOW_FUNCTIONS_H
