#pragma once

#include <vector>

#include "helper_functions.h"

long long bubble_sort(std::vector<student> data, std::vector<student>& sorted_data, sort_type type);

long long bucket_sort(std::vector<student> data, sort_type type);

long long merge_sort(std::vector<student> data, sort_type type);

bool sort_by_name(student lhs, student rhs) { return lhs.name < rhs.name; }

bool sort_by_id(student lhs, student rhs) { return lhs.id < rhs.id; }

bool sort_by_score(student lhs, student rhs) { return lhs.score < rhs.score; }