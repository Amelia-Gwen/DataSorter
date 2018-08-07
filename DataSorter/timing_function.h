#ifndef BRUGLESCO_DATASORTER_TIMING_FUNCTION_H
#define BRUGLESCO_DATASORTER_TIMING_FUNCTION_H

#include <chrono>

template <typename T, typename... Args>
inline long long timing_function(T timed_function, Args args...)
{
	auto start = std::chrono::steady_clock::now();

	timed_function(args...);

	auto end = std::chrono::steady_clock::now();
	std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	return time_passed.count();
};

#endif // !BRUGLESCO_DATASORTER_TIMING_FUNCTION_H