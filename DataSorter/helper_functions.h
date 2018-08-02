#pragma once

#include <fstream>
#include <string>

struct student
{
	std::string name;
	unsigned id;
	unsigned score;

	student(std::string name, unsigned id, unsigned score) : name{ name }, id{ id }, score{ score } {}
};

void check_file(std::ifstream& source_file);

void sort_data();

void sort_three_ways(char choice);

