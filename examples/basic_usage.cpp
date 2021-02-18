
#include <butterfly/butterfly.hpp>
#include <butterfly/wings/file_wing.hpp>
#include <butterfly/wings/console_wing.hpp>

#include <iostream>

using namespace butterfly;
using namespace std;

int main() {

	auto consoleLogger = create_wing<console_wing>("", level::warning); // Will only write in the console records that have a warning or higher level

	auto fileLogger = create_wing<file_wing>("", "log-basic-usage.txt"); // Will write in the "log-basic-usage.txt" file all records (no level specified)

	auto logger = create_net("", {consoleLogger, fileLogger}); // Will log both in the console logger and in the file logger

	logger->error("Network", "Network service unavailable"); // I can use logger to log

	set_default_logger(logger); // Or I can set logger as the default logger ...

	info("Engine", "Engine initialization complete"); // ... and log

	return 0;
}