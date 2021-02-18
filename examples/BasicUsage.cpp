
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {

	auto consoleLogger = CreateWing<ConsoleWing>("", Level::warning); // Will only write in the console records that have a warning or higher level

	auto fileLogger = CreateWing<FileWing>("", "log-basic-usage.txt"); // Will write in the "log-basic-usage.txt" file all records (no level specified)

	auto logger = CreateNet("", {consoleLogger, fileLogger}); // Will log both in the console logger and in the file logger

	logger->Error("Network", "Network service unavailable"); // I can use logger to Log

	SetDefaultLogger(logger); // Or I can set logger as the default logger ...

	Info("Engine", "Engine initialization complete"); // ... and log

	return 0;
}