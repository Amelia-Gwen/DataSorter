#ifndef BRUGLESCO_DATASORTER_TIMING_FUNCTION_H
#define BRUGLESCO_DATASORTER_TIMING_FUNCTION_H

#include <chrono>

namespace bruglesco {

	class timer
	{
	public:
		void start() { begin = std::chrono::steady_clock::now(); }
		long long stop() {
			end = std::chrono::steady_clock::now();
			std::chrono::milliseconds time_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			return time_passed.count();
		}
	private:
		std::chrono::time_point<std::chrono::steady_clock> begin{ std::chrono::steady_clock::now() };
		std::chrono::time_point<std::chrono::steady_clock> end{ std::chrono::steady_clock::now() };
	};

}
#endif // !BRUGLESCO_DATASORTER_TIMING_FUNCTION_H