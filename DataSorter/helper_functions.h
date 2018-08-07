#ifndef BRUGLESCO_DATASORTER_HELP_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_HELP_FUNCTIONS_H

#include <fstream>
#include <string>
#include <vector>

struct student
{
	std::string name;
	unsigned id;
	unsigned score;

	student(std::string name, unsigned id, unsigned score) : name{ name }, id{ id }, score{ score } {}
};

void save_data_to_memory(std::vector<student>& data, std::string file_name);

void check_file(std::ifstream& source_file);

void sort_data(const std::vector<student>& data);

void sort_three_ways(const std::vector<student>& data, std::vector<student>& sorted_data, char choice);

void sort_by(const std::vector<student>& data, std::vector<student>& sorted_data, sort_type type);

void save_or_sort_again(const std::vector<student>& data, const std::vector<student>& sorted_data);

void post_sort_selection(const std::vector<student>& data, const std::vector<student>& sorted_data, char choice);

void save_to_file(const std::vector<student>& data);


#endif // !BRUGLESCO_DATASORTER_HELP_FUNCTIONS_H
