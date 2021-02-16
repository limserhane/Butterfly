
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>
#include <Butterfly/Wings/ColoredConsoleWing.hpp>

#include <iostream>
#include <thread>

using namespace Butterfly;
using namespace std;

int main() {

	// SetDefaultLogger(CreateWing<ConsoleWing>("")); // 200k/s

	// SetDefaultLogger(CreateWing<ColoredConsoleWing>("")); // 10k/s

	SetDefaultLogger(CreateWing<FileWing>("", "log-speed-test.txt")); // 210k/s

    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;

	size_t howmany = 100000;

    auto start = high_resolution_clock::now();
	
    for (size_t i = 0; i < howmany; ++i)
    {
		Trace("ColoredConsoleWing", "this is a trace");
		Info("ColoredConsoleWing", "this is an info");
		Warning("ColoredConsoleWing", "this is a warning");
		Error("ColoredConsoleWing", "this is an error");
		Fatal("ColoredConsoleWing", "this is a fatal error");
		Debug("ColoredConsoleWing", "this is a debug info");
    }

    auto delta = high_resolution_clock::now() - start;
    auto delta_d = duration_cast<duration<double>>(delta).count();

	printf("%.2lf secs %d/sec\n", delta_d, int(howmany * 6 / delta_d));

	return 0;
}