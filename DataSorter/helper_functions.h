#pragma once

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

void sort_data();

void sort_three_ways(char choice);

bool sort_by_name(const student& lhs, const student& rhs) { return lhs.name > rhs.name; }

bool sort_by_id(const student& lhs, const student& rhs) { return lhs.id > rhs.id; }

bool sort_by_score(const student& lhs, const student& rhs) { return lhs.score > rhs.score; }