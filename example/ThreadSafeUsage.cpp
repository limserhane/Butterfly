
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>

#include <iostream>
#include <thread>
#include <fstream>


using namespace Butterfly;
using namespace std;

void foo() 
{
	for (int i = 0; i < 1000; ++i)
	{
		Get("unsafe")->Trace("network", "abcdefghij");
		Get("safe")->Trace("network", "abcdefghij");
	}
}

void bar()
{
	for (int i = 0; i < 1000; ++i)
	{
		Get("unsafe")->Trace("engine", "0123456789");
		Get("safe")->Trace("engine", "0123456789");
	}
}

int main() {

	auto unsafelogger = CreateWing<FileWing>("unsafe", "log-unsafe-thread-safe-usage.txt");

	auto safelogger = CreateSafeLogger("safe", 
		CreateWing<FileWing>("", "log-safe-thread-safe-usage.txt")
	);

	std::thread foothread(foo);
	std::thread barthread(bar);

	// Here foo() and bar() are concurrent; but the "logfile" logger will safely write in "bin/log.txt"

	foothread.join();
	barthread.join();

	return 0;
}