#ifndef BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H

#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <utility>

#include <conio.h>

namespace bruglesco {
	template <typename Iterator, typename Comparator = std::less<typename std::iterator_traits<RandIterator>::value_type>>
	inline void bubble_sort(Iterator begin, Iterator end, Comparator cmp = Comparator())
	{
		std::cout << "Sorting with bubble sort. Press C to end sort.\n"
			"----------|Finished\n";

		bool stopped{ false };
		bool first_pass{ true };
		std::size_t size = 0;
		std::size_t count = 0;

		while (!stopped && begin != end)
		{
			bool changed{ false };
			for (auto temp_lhs = begin; temp_lhs != end; ++temp_lhs)
			{
				if (first_pass) { ++size; }
				auto temp_rhs = temp_lhs;
				++temp_rhs;
				if (temp_rhs != end && cmp(*temp_rhs, *temp_lhs))
				{
					changed = true;
					std::iter_swap(temp_lhs, temp_rhs);
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
			if (first_pass) { first_pass = false; }
			if (count > size / 10)
			{
				std::cout << '*';
				count = 0;
			}
			if (!changed) { stopped = true; }
		}
		std::cout << "*\n";
	}

	template <typename Iterator, typename Comparator = std::less<typename std::iterator_traits<RandIterator>::value_type>>
	inline void selection_sort(Iterator begin, Iterator end, Comparator cmp = Comparator())
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
			for (auto temp = begin; temp != end; ++temp)
			{
				if (cmp(*temp, *smallest))
				{
					smallest = temp;
				}
				if (first_pass) { ++count; }
			}
			std::rotate(begin, smallest, end);
			++begin;

			if (first_pass) { first_pass = false; }
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

	template <typename Iterator, typename Comparator = std::less<typename std::iterator_traits<RandIterator>::value_type>>
	inline void merge_sort(Iterator begin, Iterator end, Comparator cmp = Comparator())
	{
		std::cout << "Sorting with merge sort. Press C to end sort.\n"
			"----------|Finished\n";

		bool stopped{ false };
		if (begin == end) { stopped = true; }
		bool unsorted{ true };
		std::size_t size = 0;
		std::size_t sub_size = 1;

		while (!stopped && unsorted)
		{
			auto lhs = begin;
			auto rhs = begin;

			for (std::size_t i = 0; i < sub_size; ++i)
			{
				++rhs;
				if (sub_size == 1) { ++size; }
			}

			while (rhs != end)
			{
				std::size_t left_count = sub_size;
				std::size_t right_count = sub_size;
				while (left_count > 0 && right_count > 0)
				{
					if (rhs == end) { break; }
					if (cmp(*rhs, *lhs))
					{
						auto temp_lhs = rhs;
						auto temp_rhs = rhs;
						--temp_lhs;
						while (temp_rhs != lhs)
						{
							std::swap(*temp_lhs, *temp_rhs);
							--temp_lhs;
							--temp_rhs;
						}
						++lhs;
						if (rhs == end) { break; }
						++rhs;
						--right_count;
						if (sub_size == 1) { ++size; }
					}
					else
					{
						++lhs;
						--left_count;
					}
				}
				for (std::size_t i = 0; i < left_count; ++i)
				{
					++lhs;
				}
				for (std::size_t i = 0; i < right_count; ++i)
				{
					if (rhs == end || lhs == end) { break; }
					++lhs;
					++rhs;
					if (sub_size == 1) { ++size; }
				}
				for (std::size_t i = 0; i < sub_size; ++i)
				{
					if (rhs == end) { break; }
					++rhs;
					if (sub_size == 1) { ++size; }
				}
			}
			std::cout << '*';
			sub_size *= 2;
			if (sub_size > size) { unsorted = false; }
		}
		if (_kbhit())
		{
			auto key = _getch();
			if (key == 'c' || key == 'C')
			{
				stopped = true;
			}
		}
		std::cout << "*\n";
	}
}
#endif // !BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H
