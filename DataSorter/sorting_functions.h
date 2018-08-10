#ifndef BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H

#include <cstddef>
#include <iostream>

namespace bruglesco {

	template <typename T>
	bool default_comparison(T lhs, T rhs) { return lhs > rhs; }

	template <typename Iterator, typename Func>
	inline void bubble_sort(Iterator begin, Iterator end, Func func = default_comparison)
	{
		std::cout << "Sorting with bubble sort. Press C to end sort.\n"
			<< "----------|Finished\n";

		bool stopped{ false };
		std::size_t count = 0;

		while (!stopped && begin != end)
		{
			for (auto temp_rhs = begin; temp_rhs != end; ++temp_rhs)
			{
				auto temp_lhs = temp_rhs++;
				if (temp_lhs != end && func(*temp_lhs, *temp_rhs))
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

			++count;
			if (count > data.size() / 10)
			{
				std::cout << '*';
				count = 0;
			}
		}
		std::cout << "*\n";
	}

	template <typename Iterator, typename Func>
	inline void merge_sort(Iterator begin, Iterator end, Func func = default_comparison)
	{
		std::cout << "Sorting with merge sort. Press C to end sort.\n"
			<< "----------|Finished\n";

		bool stopped{ false };
	}

	template <typename Iterator, typename Func>
	inline void selection_sort(Iterator begin, Iterator end, Func func = default_comparison)
	{
		std::cout << "Sorting with selection sort. Press C to end sort.\n"
			<< "----------|Finished\n";

		bool stopped{ false };
		std::size_t count = 0;

		while (!stopped && begin != end)
		{
			auto smallest = begin;
			auto largest = begin;
			for (auto temp = begin; temp != end; ++temp)
			{
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
				std::swap(*smallest, *begin)
			}
			if (largest != --end)
			{
				std::swap(*largest, *end)
			}
			if (begin == end)
			{
				stopped = true;
			}
			++begin

			count += 2;
			if (count > data.size() / 10)
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
