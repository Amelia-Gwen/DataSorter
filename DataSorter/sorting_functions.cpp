#include <conio.h>

#include <algorithm>
#include <chrono>
#include <cstddef>
#include <iostream>

#include "sorting_functions.h"

long long bubble_sort(std::vector<student> data, std::vector<student>& sorted_data, sort_type type)
{
	std::cout << "Sorting with bubble sort. Press C to end sort.\n"
		<< "----------|Finished\n";

	auto start = std::chrono::steady_clock::now();

	std::size_t last_unsorted{ data.size() - 1 };
	std::size_t count = 0;
	bool stopped{ false };

	switch (type)
	{
	case sort_type::name:
		while (!stopped && last_unsorted > 0)
		{
			for (std::size_t i = 0; i < last_unsorted - 1; ++i)
			{
				if (data[i].name > data[i + 1].name)
				{
					std::swap(data[i], data[i + 1]);
				}

				if (_kbhit())
				{
					char key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}
			}
			--last_unsorted;
			++count;
			if (count == data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << '*';
		break;
	case sort_type::id:
		while (!stopped && last_unsorted > 0)
		{
			for (std::size_t i = 0; i < last_unsorted - 1; ++i)
			{
				if (data[i].id > data[i + 1].id)
				{
					std::swap(data[i], data[i + 1]);
				}

				if (_kbhit())
				{
					char key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}
			}
			--last_unsorted;
			++count;
			if (count == data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << '*';
		break;
	case sort_type::score:
		while (!stopped && last_unsorted > 0)
		{
			for (std::size_t i = 0; i < last_unsorted - 1; ++i)
			{
				if (data[i].score > data[i + 1].score)
				{
					std::swap(data[i], data[i + 1]);
				}

				if (_kbhit())
				{
					char key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}
			}
			--last_unsorted;
			++count;
			if (count == data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << '*';
		break;
	default:
		std::cerr << "Error selecting sort type. Aborting";
		break;
	};

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	sorted_data = data;
	return time_passed.count();
}

long long bucket_sort(std::vector<student> data, sort_type type)
{
	std::cout << "Sorting with bucket sort. Press C to end sort.\n"
		<< "----------|Finished\n";
	auto start = std::chrono::steady_clock::now();

	auto last_unsorted{ data.size() - 1 };
	auto count = 0;
	bool stopped{ false };
	std::vector<student> a_c;
	std::vector<student> d_f;
	std::vector<student> g_i;
	std::vector<student> j_l;
	std::vector<student> m_o;
	std::vector<student> p_r;
	std::vector<student> s_t;
	std::vector<student> u_w;
	std::vector<student> x_z;

	switch (type)
	{
	case sort_type::name:
		for (auto&& student : data)
		{
			if (!stopped)
			{
				switch (student.name[0])
				{
				case 'A':
				case 'B':
				case 'C':
					a_c.push_back(student);
					break;
				case 'D':
				case 'E':
				case 'F':
					d_f.push_back(student);
					break;
				case 'G':
				case 'H':
				case 'I':
					g_i.push_back(student);
					break;
				case 'J':
				case 'K':
				case 'L':
					j_l.push_back(student);
					break;
				case 'M':
				case 'N':
				case 'O':
					m_o.push_back(student);
					break;
				case 'P':
				case 'Q':
				case 'R':
					p_r.push_back(student);
					break;
				case 'S':
				case 'T':
					s_t.push_back(student);
					break;
				case 'U':
				case 'V':
				case 'W':
					u_w.push_back(student);
					break;
				case 'X':
				case 'Y':
				case 'Z':
					x_z.push_back(student);
					break;
				default:
					break;
				}

				if (_kbhit())
				{
					char key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}
			}
			std::sort(std::begin(a_c), std::end(a_c), sort_by_name);
			std::cout << '*';
			std::sort(std::begin(d_f), std::end(d_f), sort_by_name);
			std::cout << '*';
			std::sort(std::begin(g_i), std::end(g_i), sort_by_name);
			std::cout << '*';
			std::sort(std::begin(j_l), std::end(j_l), sort_by_name);
			std::cout << '*';
			std::sort(std::begin(m_o), std::end(m_o), sort_by_name);
			std::cout << '*';
			std::sort(std::begin(p_r), std::end(p_r), sort_by_name);
			std::cout << '*';
			std::sort(std::begin(s_t), std::end(s_t), sort_by_name);
			std::cout << '*';
			std::sort(std::begin(u_w), std::end(u_w), sort_by_name);
			std::cout << '*';
			std::sort(std::begin(x_z), std::end(x_z), sort_by_name);
			std::cout << '*';

			data.clear();
			data.insert(data.end(), a_c.begin(), a_c.end());
			data.insert(data.end(), d_f.begin(), d_f.end());
			data.insert(data.end(), g_i.begin(), g_i.end());
			data.insert(data.end(), j_l.begin(), j_l.end());
			data.insert(data.end(), m_o.begin(), m_o.end());
			data.insert(data.end(), p_r.begin(), p_r.end());
			data.insert(data.end(), s_t.begin(), s_t.end());
			data.insert(data.end(), u_w.begin(), u_w.end());
			data.insert(data.end(), x_z.begin(), x_z.end());
			std::cout << '*';
		}
		break;
	case sort_type::id:

		break;
	case sort_type::score:

		break;
	default:
		std::cerr << "Error selecting sort type. Aborting";
		break;
	};

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed.count();
}

long long merge_sort(std::vector<student> data, sort_type type)
{
	std::cout << "Sorting with counting sort. Press C to end sort.\n"
		<< "----------|Finished\n";
	auto start = std::chrono::steady_clock::now();

	auto last_unsorted{ data.size() - 1 };
	auto count = 0;
	bool stopped{ false };

	switch (type)
	{
	case sort_type::name:
		while (!stopped)
		{

		}
		break;
	case sort_type::id:
		while (!stopped)
		{

		}
		break;
	case sort_type::score:
		while (!stopped)
		{

		}
		break;
	default:
		std::cerr << "Error selecting sort type. Aborting";
		break;
	};

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed.count();
}
