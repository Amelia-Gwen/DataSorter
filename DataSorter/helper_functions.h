#ifndef BRUGLESCO_DATASORTER_HELP_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_HELP_FUNCTIONS_H

#include <fstream>
#include <string>
#include <vector>

namespace bruglesco {

	void sort_data(const std::vector<student>& data);

	void sort_three_ways(const std::vector<student>& data, std::vector<student>& sorted_data, char choice);

	void sort_by(const std::vector<student>& data, std::vector<student>& sorted_data, bool(*func)(student, student));

	void save_or_sort_again(const std::vector<student>& data, const std::vector<student>& sorted_data);

	void post_sort_selection(const std::vector<student>& data, const std::vector<student>& sorted_data, char choice);
}
#endif // !BRUGLESCO_DATASORTER_HELP_FUNCTIONS_H
