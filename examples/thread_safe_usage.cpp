
#include <butterfly/butterfly.hpp>
#include <butterfly/wings/file_wing.hpp>
#include <butterfly/wings/console_wing.hpp>

#include <iostream>
#include <thread>
#include <fstream>


using namespace butterfly;
using namespace std;

void foo() 
{
	for (int i = 0; i < 1000; ++i)
	{
		get("unsafe")->trace("network", "abcdefghij");
		get("safe")->trace("network", "abcdefghij");
	}
}

void bar()
{
	for (int i = 0; i < 1000; ++i)
	{
		get("unsafe")->trace("engine", "0123456789");
		get("safe")->trace("engine", "0123456789");
	}
}

int main() {

	// This logger is not safe to concurrent accesses
	auto unsafelogger = create_wing<file_wing>("unsafe", "log-unsafe-thread-safe-usage.txt");

	// This logger can be safely accessed by concurrent threads
	auto safelogger = create_safe_logger("safe", 
		create_wing<file_wing>("", "log-safe-thread-safe-usage.txt")
	);

	std::thread foothread(foo);
	std::thread barthread(bar);

	// Here foo() and bar() are concurrent; but the "logfile" logger will safely write in "bin/log.txt"

	foothread.join();
	barthread.join();

	return 0;
}