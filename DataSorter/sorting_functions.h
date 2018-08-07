#ifndef BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H

#include <vector>

#include "helper_functions.h"

void bubble_sort(std::vector<student> data, sort_type type);

void bucket_sort(std::vector<student> data, std::vector<student>& sorted_data, sort_type type);

void selection_sort(std::vector<student> data, sort_type type);

#endif // !BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H
