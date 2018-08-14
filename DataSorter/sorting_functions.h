#ifndef BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H

#include <cstddef>
#include <iostream>
#include <utility>

#include <conio.h>

namespace bruglesco {

	template <typename T>
	bool default_comparison(T lhs, T rhs) { return lhs > rhs; }

	template <typename Iterator, typename Func>
	inline void bubble_sort(Iterator begin, Iterator end, Func func = default_comparison)
	{
		std::cout << "Sorting with bubble sort. Press C to end sort.\n"
			"----------|Finished\n";

		bool stopped{ false };
		bool first_pass{ true };
		std::size_t size = 0;
		std::size_t count = 0;

		while (!stopped && begin != end)
		{
			for (auto temp_rhs = begin; temp_rhs != end; ++temp_rhs)
			{
				if (first_pass) { ++size; }
				auto temp_lhs = temp_rhs++;
				if (temp_rhs != end && func(*temp_lhs, *temp_rhs))
				{
					std::swap(*temp_lhs, *temp_rhs);
				}

				if (_kbhit())
				{
					auto key = _getch();
					if (key == 'c' || key == 'C')
					{
						stopped = true;
					}
				}
				if (stopped)
				{
					break;
				}
			}
			--end;
			if (first_pass) { first_pass = false; }
			++count;
			if (count > size / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << "*\n";
	}

	// bugged. need to move not swap when rhs is smaller
	template <typename Iterator, typename Func>
	inline void merge_sort(Iterator begin, Iterator end, Func func = default_comparison)
	{
		std::cout << "Sorting with merge sort. Press C to end sort.\n"
			"----------|Finished\n";

		bool stopped{ false };
		std::size_t sub_size = 1;
		std::size_t size = 0;
		std::size_t count = 0;

		do
		{
			auto it_lhs = begin;
			auto it_rhs = begin;
			std::size_t left_count = sub_size;
			std::size_t right_count = sub_size;

			while (it_rhs != end)
			{
				for (std::size_t i = 0; i < sub_size; ++i)
				{
					++it_rhs;
					if (sub_size == 1)
					{
						++size;
					}
					if (it_rhs == end)
					{
						break;
					}
				}
				while (left_count > 0 && right_count > 0)
				{
					if (it_rhs == end || func(*it_lhs, *it_rhs))
					{
						--left_count;
						++it_lhs;
					}
					else
					{
						std::swap(*it_lhs, *it_rhs);
						--right_count;
						++it_rhs;
						if (sub_size == 1)
						{
							++size;
						}
					}
				}
				for (std::size_t i = 0; i < left_count; ++i)
				{
					++it_lhs;
				}
				for (std::size_t i = 0; i < right_count; ++i)
				{
					if (it_rhs == end)
					{
						break;
					}
					++it_rhs;
					if (sub_size == 1)
					{
						++size;
					}
				}
			}

			sub_size *= 2;
			++count;
			if (count > size / 10)
			{
				std::cout << '*';
				count = 0;
			}
			if (_kbhit())
			{
				auto key = _getch();
				if (key == 'c' || key == 'C')
				{
					stopped = true;
				}
			}
		}
		while (!stopped && sub_size < size);
		std::cout << '*\n';
	}

	template <typename Iterator, typename Func>
	inline void selection_sort(Iterator begin, Iterator end, Func func = default_comparison)
	{
		std::cout << "Sorting with selection sort. Press C to end sort.\n"
			"----------|Finished\n";

		bool stopped{ false };
		bool first_pass{ true };
		std::size_t size = 0;
		std::size_t count = 0;

		while (!stopped && begin != end)
		{
			auto smallest = begin;
			auto largest = begin;
			for (auto temp = begin; temp != end; ++temp)
			{
				if (first_pass) { ++size; }
				if (func(*temp, *smallest))
				{
					smallest = temp;
				}
				if (func(*largest, *temp))
				{
					largest = temp;
				}
			}
			if (smallest != begin)
			{
				std::swap(*smallest, *begin);
			}
			if (largest != --end)
			{
				std::swap(*largest, *end);
			}
			if (begin == end)
			{
				stopped = true;
			}
			++begin;
			if (first_pass) { first_pass = false; }
			count += 2;
			if (count > size / 10)
			{
				std::cout << '*';
				count = 0;
			}

			if (_kbhit())
			{
				auto key = _getch();
				if (key == 'c' || key == 'C')
				{
					stopped = true;
				}
			}
		}

		std::cout << "*\n";
	}

}
#endif // !BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H
