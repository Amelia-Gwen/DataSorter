#include <iomanip>
#include <iostream>
#include <vector>

#include "data_functions.h"
#include "sorting_functions.h"
#include "timing_function.h"

#include "control_flow_functions.h"

void bruglesco::run_program(std::string file_name)
{
	std::vector<student> data;
	data.reserve(100000);

	save_data_to_memory(data, file_name);

	sort_data(data);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
