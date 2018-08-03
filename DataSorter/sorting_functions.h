#pragma once

#include <vector>

#include "helper_functions.h"

void bubble_sort_timer(std::vector<student> data, std::vector<student>& sorted_data, sort_type type);

void bucket_sort_timer(std::vector<student> data, sort_type type);

void counting_sort_timer(std::vector<student> data, sort_type type);
