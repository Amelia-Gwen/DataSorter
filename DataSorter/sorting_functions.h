#pragma once

#include <vector>

#include "helper_functions.h"

long long bubble_sort(std::vector<student> data, sort_type type);

long long bucket_sort(std::vector<student> data, std::vector<student>& sorted_data, sort_type type);

long long selection_sort(std::vector<student> data, sort_type type);
