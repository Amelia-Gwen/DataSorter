#pragma once

#include <vector>

#include "helper_functions.h"

// templating and implementing the use of iterators will be non-trivial.
void bubble_sort(std::vector<student> data, std::vector<student>& sorted_data, sort_type type);

void bucket_sort(std::vector<student> data, sort_type type);

void counting_sort(std::vector<student> data, sort_type type);

bool sort_by_name(const student& lhs, const student& rhs) { return lhs.name > rhs.name; }

bool sort_by_id(const student& lhs, const student& rhs) { return lhs.id > rhs.id; }

bool sort_by_score(const student& lhs, const student& rhs) { return lhs.score > rhs.score; }