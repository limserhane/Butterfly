
#include <butterfly/butterfly.hpp>
#include <butterfly/wings/file_wing.hpp>
#include <butterfly/wings/console_wing.hpp>
#include <butterfly/wings/colored_console_wing.hpp>

#include <iostream>
#include <thread>

using namespace butterfly;
using namespace std;

int main() {

	//set_default_logger(create_wing<console_wing>("")); // 75k/s

	// set_default_logger(create_wing<colored_console_wing>("")); // 10k/s

	 set_default_logger(create_wing<file_wing>("", "log-speed-test.txt")); // 230k/s

	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;

	size_t howmany = 1000;

	auto start = high_resolution_clock::now();
	
	for (size_t i = 0; i < howmany; ++i)
	{
		trace("speed", "this is a trace");
		info("speed", "this is an info");
		warning("speed", "this is a warning");
		error("speed", "this is an error");
		fatal("speed", "this is a fatal error");
		debug("speed", "this is a debug info");
	}

	auto delta = high_resolution_clock::now() - start;
	auto delta_d = duration_cast<duration<double>>(delta).count();

	printf("%.2lf secs %d/sec\n", delta_d, int(howmany * 6 / delta_d));

	return 0;
}