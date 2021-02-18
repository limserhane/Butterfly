
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>
#include <Butterfly/Wings/ColoredConsoleWing.hpp>

#include <iostream>
#include <thread>

using namespace Butterfly;
using namespace std;

int main() {

	SetDefaultLogger(CreateWing<ConsoleWing>("")); // 75k/s

	// SetDefaultLogger(CreateWing<ColoredConsoleWing>("")); // 10k/s

	// SetDefaultLogger(CreateWing<FileWing>("", "log-speed-test.txt")); // 230k/s

    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;

	size_t howmany = 10;

    auto start = high_resolution_clock::now();
	
    for (size_t i = 0; i < howmany; ++i)
    {
		Trace("speed", "this is a trace");
		Info("speed", "this is an info");
		Warning("speed", "this is a warning");
		Error("speed", "this is an error");
		Fatal("speed", "this is a fatal error");
		Debug("speed", "this is a debug info");
    }

    auto delta = high_resolution_clock::now() - start;
    auto delta_d = duration_cast<duration<double>>(delta).count();

	printf("%.2lf secs %d/sec\n", delta_d, int(howmany * 6 / delta_d));

	return 0;
}