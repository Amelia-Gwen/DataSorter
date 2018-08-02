#pragma once

#include <vector>

#include "helper_functions.h"

void bubble_sort(const std::vector<student>& source, sort_type type);

void bucket_sort(const std::vector<student>& source, sort_type type);

void counting_sort(const std::vector<student>& source, sort_type type);

bool sort_by_name(const student& lhs, const student& rhs) { return lhs.name > rhs.name; }

bool sort_by_id(const student& lhs, const student& rhs) { return lhs.id > rhs.id; }

bool sort_by_score(const student& lhs, const student& rhs) { return lhs.score > rhs.score; }