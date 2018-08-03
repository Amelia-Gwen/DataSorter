#include <conio.h>

#include <algorithm>
#include <chrono>
#include <cstddef>
#include <iostream>

#include "sorting_functions.h"

bool sort_by_name(student lhs, student rhs) { return lhs.name > rhs.name; }

bool sort_by_id(student lhs, student rhs) { return lhs.id > rhs.id; }

bool sort_by_score(student lhs, student rhs) { return lhs.score > rhs.score; }

long long bubble_sort(std::vector<student> data, std::vector<student>& sorted_data, sort_type type)
{
	std::cout << "Sorting with bubble sort. Press C to end sort.\n"
		<< "----------|Finished\n";

	std::size_t last_unsorted{ data.size() - 1 };
	std::size_t count = 0;
	bool stopped{ false };

	auto start = std::chrono::steady_clock::now();

	if (type == sort_type::name)
	{
		while (!stopped && last_unsorted > 0)
		{
			for (std::size_t i = 0; i < last_unsorted; ++i)
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
			if (count > data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << "*\n";
	}
	else if (type == sort_type::id)
	{
		while (!stopped && last_unsorted > 0)
		{
			for (std::size_t i = 0; i < last_unsorted; ++i)
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
			if (count > data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << "*\n";
	}
	else
	{
		while (!stopped && last_unsorted > 0)
		{
			for (std::size_t i = 0; i < last_unsorted; ++i)
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
			if (count > data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << "*\n";
    }

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	sorted_data.clear();
	for (auto&& students : data)
	{
		sorted_data.emplace_back(student(students.name, students.id, students.score));
	}
	return time_passed.count();
}

long long bucket_sort(std::vector<student> data, sort_type type)
{
	std::cout << "Sorting with bucket sort. Press C to end sort.\n"
		<< "----------|Finished\n";
	
	bool stopped{ false };

	auto start = std::chrono::steady_clock::now();
	
	if (type == sort_type::name)
	{
		std::vector<student> a_c;
		std::vector<student> d_f;
		std::vector<student> g_i;
		std::vector<student> j_l;
		std::vector<student> m_o;
		std::vector<student> p_r;
		std::vector<student> s_t;
		std::vector<student> u_w;
		std::vector<student> x_z;
		if (!stopped)
		{
			for (auto&& student : data)
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
				};
			}
			if (_kbhit())
			{
				char key = _getch();
				if (key == 'c' || key == 'C')
				{
					stopped = true;
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
			std::cout << "*\n";
		}
	}
	else if (type == sort_type::id)
	{
		std::vector<student> ones;
		std::vector<student> tens;
		std::vector<student> twenties;
		std::vector<student> thirties;
		std::vector<student> fourties;
		std::vector<student> fifties;
		std::vector<student> sixties;
		std::vector<student> seventies;
		std::vector<student> eighties;
		std::vector<student> nineties;
		if (!stopped)
		{
			for (auto&& student : data)
			{
				if (student.id < 110)
				{
					ones.push_back(student);
				}
				else if (student.id < 120)
				{
					tens.push_back(student);
				}
				else if (student.id < 130)
				{
					twenties.push_back(student);
				}
				else if (student.id < 140)
				{
					thirties.push_back(student);
				}
				else if (student.id < 150)
				{
					fourties.push_back(student);
				}
				else if (student.id < 160)
				{
					fifties.push_back(student);
				}
				else if (student.id < 170)
				{
					sixties.push_back(student);
				}
				else if (student.id < 180)
				{
					seventies.push_back(student);
				}
				else if (student.id < 190)
				{
					eighties.push_back(student);
				}
				else
				{
					nineties.push_back(student);
				}
			}
			if (_kbhit())
				{
					char key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}

			std::sort(std::begin(ones), std::end(ones), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(tens), std::end(tens), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(twenties), std::end(twenties), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(thirties), std::end(thirties), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(fourties), std::end(fourties), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(fifties), std::end(fifties), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(sixties), std::end(sixties), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(seventies), std::end(seventies), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(eighties), std::end(eighties), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(nineties), std::end(nineties), sort_by_id);

			data.clear();
			data.insert(data.end(), ones.begin(), ones.end());
			data.insert(data.end(), tens.begin(), tens.end());
			data.insert(data.end(), twenties.begin(), twenties.end());
			data.insert(data.end(), thirties.begin(), thirties.end());
			data.insert(data.end(), fourties.begin(), fourties.end());
			data.insert(data.end(), fifties.begin(), fifties.end());
			data.insert(data.end(), sixties.begin(), sixties.end());
			data.insert(data.end(), seventies.begin(), seventies.end());
			data.insert(data.end(), eighties.begin(), eighties.end());
			data.insert(data.end(), nineties.begin(), nineties.end());
			std::cout << "*\n";
		}
	}
	else
	{
		std::vector<student> one_hundred;
		std::vector<student> two_hundred;
		std::vector<student> three_hundred;
		std::vector<student> four_hundred;
		std::vector<student> five_hundred;
		std::vector<student> six_hundred;
		std::vector<student> seven_hundred;
		std::vector<student> eight_hundred;
		std::vector<student> nine_hundred;
		std::vector<student> one_thousand;
		if (!stopped)
		{
			for (auto&& student : data)
			{
				if (student.score <= 100)
				{
					one_hundred.push_back(student);
				}
				else if (student.score <= 200)
				{
					two_hundred.push_back(student);
				}
				else if (student.score <= 300)
				{
					three_hundred.push_back(student);
				}
				else if (student.score <= 400)
				{
					four_hundred.push_back(student);
				}
				else if (student.score <= 500)
				{
					five_hundred.push_back(student);
				}
				else if (student.score <= 600)
				{
					six_hundred.push_back(student);
				}
				else if (student.score <= 700)
				{
					seven_hundred.push_back(student);
				}
				else if (student.score <= 800)
				{
					eight_hundred.push_back(student);
				}
				else if (student.score <= 900)
				{
					nine_hundred.push_back(student);
				}
				else
				{
					one_thousand.push_back(student);
				}
			}

			if (_kbhit())
			{
				char key = _getch();
				if (key == 'c' || key == 'C')
				{
					stopped = true;
				}
			}

			std::sort(std::begin(one_hundred), std::end(one_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(two_hundred), std::end(two_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(three_hundred), std::end(three_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(four_hundred), std::end(four_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(five_hundred), std::end(five_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(six_hundred), std::end(six_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(seven_hundred), std::end(seven_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(eight_hundred), std::end(eight_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(nine_hundred), std::end(nine_hundred), sort_by_id);
			std::cout << '*';
			std::sort(std::begin(one_thousand), std::end(one_thousand), sort_by_id);

			data.clear();
			data.insert(data.end(), one_hundred.begin(), one_hundred.end());
			data.insert(data.end(), two_hundred.begin(), two_hundred.end());
			data.insert(data.end(), three_hundred.begin(), three_hundred.end());
			data.insert(data.end(), four_hundred.begin(), four_hundred.end());
			data.insert(data.end(), five_hundred.begin(), five_hundred.end());
			data.insert(data.end(), six_hundred.begin(), six_hundred.end());
			data.insert(data.end(), seven_hundred.begin(), seven_hundred.end());
			data.insert(data.end(), eight_hundred.begin(), eight_hundred.end());
			data.insert(data.end(), nine_hundred.begin(), nine_hundred.end());
			data.insert(data.end(), one_thousand.begin(), one_thousand.end());
			std::cout << "*\n";
		}
	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed.count();
}

long long selection_sort(std::vector<student> data, sort_type type)
{
	std::cout << "Sorting with selection sort. Press C to end sort.\n"
		<< "----------|Finished\n";

	bool stopped{ false };
	std::size_t first_unsorted = 0;
	std::size_t count = 0;

	auto start = std::chrono::steady_clock::now();

	if (type == sort_type::name)
	{
		while (first_unsorted < data.size())
		{
			std::size_t index = first_unsorted;
			for (std::size_t i = first_unsorted; i < data.size(); ++i)
			{
				if (data[i].name < data[index].name)
				{
					index = i;
				}
			}
			if (index != first_unsorted)
			{
				std::swap(data[first_unsorted], data[index]);
			}
			++first_unsorted;
			++count;
			if (count > data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
	}
	else if (type == sort_type::id)
	{
		while (first_unsorted < data.size())
		{
			std::size_t index = first_unsorted;
			for (std::size_t i = first_unsorted; i < data.size(); ++i)
			{
				if (data[i].id < data[index].id)
				{
					index = i;
				}
			}
			if (index != first_unsorted)
			{
				std::swap(data[first_unsorted], data[index]);
			}
			++first_unsorted;
			++count;
			if (count > data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
	}
	else
	{
		while (first_unsorted < data.size())
		{
			std::size_t index = first_unsorted;
			for (std::size_t i = first_unsorted; i < data.size(); ++i)
			{
				if (data[i].score < data[index].score)
				{
					index = i;
				}
			}
			if (index != first_unsorted)
			{
				std::swap(data[first_unsorted], data[index]);
			}
			++first_unsorted;
			++count;
			if (count > data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed.count();
}
