#ifndef BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H
#define BRUGLESCO_DATASORTER_SORTING_FUNCTIONS_H

#include <iostream>
#include <vector>
namespace bruglesco {

	template <typename T, typename T>
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
		std::cout << "Sorting with bucket sort. Press C to end sort.\n"
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

		auto smallest = begin;
		auto largest = begin;

		while (!stopped && begin != end)
		{
			auto temp = begin;
			for (; temp != end; ++temp)
			{

			}
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
