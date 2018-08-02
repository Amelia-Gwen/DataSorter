#pragma once

#include <vector>

#include "helper_functions.h"

auto bubble_sort_timer(std::vector<student> data, std::vector<student>& sorted_data, sort_type type);

auto bucket_sort_timer(std::vector<student> data, sort_type type);

auto counting_sort_timer(std::vector<student> data, sort_type type);
