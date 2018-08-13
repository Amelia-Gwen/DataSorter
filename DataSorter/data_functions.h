#ifndef BRUGLESCO_DATASORTER_DATA_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_DATA_FUNCTIONS_H

#include <fstream>
#include <string>
#include <vector>

namespace bruglesco
{
	struct student
	{
		std::string name;
		unsigned id;
		unsigned score;

		student(std::string name, unsigned id, unsigned score) : name{ name }, id{ id }, score{ score } {}
	};

	bool sort_by_name(student lhs, student rhs) { return lhs.name > rhs.name; }

	bool sort_by_id(student lhs, student rhs) { return lhs.id > rhs.id; }

	bool sort_by_score(student lhs, student rhs) { return lhs.score > rhs.score; }

	void stream_source_to_local(std::vector<student>& data, std::string file_name);

	void save_to_file(const std::vector<student>& data);

	void check_file(std::ifstream& source);

	void check_file(std::ofstream& write_file);
}
#endif // !BRUGLESCO_DATASORTER_DATA_FUNCTIONS_H
