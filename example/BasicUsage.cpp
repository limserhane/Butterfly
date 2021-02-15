
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {

	auto consoleLogger = CreateWing<ConsoleWing>("", Level::warning); // will only log records that have a warning or higher level

	auto fileLogger = CreateWing<FileWing>("", "log-basic-usage.txt"); // will log all records (no level specified)

	auto logger = CreateNet("", {consoleLogger, fileLogger});

	logger->Error("Network", "Network service unavailable"); // I can use logger to Log

	SetDefaultLogger(logger); // Or I can set logger as the default logger ...

	Trace("Engine", "Engine initialization complete"); // ... and Log

	return 0;
}