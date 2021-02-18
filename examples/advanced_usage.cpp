
#include <butterfly/butterfly.hpp>
#include <butterfly/wings/file_wing.hpp>
#include <butterfly/wings/console_wing.hpp>

#include <iostream>

using namespace butterfly;
using namespace std;

void critical_task()
{ 
	// "main" logger is the default logger
	trace("Engine", "Engine initialization complete"); // this is a trace so it won't log through main

	// I can retrieve the "main" logger from anywhere
	get("main")->error("Engine", "Engine initialization failed"); // this is an error so it will log through main
	
	// I can retrieve the "network" logger from anywhere
	get("network")->trace("Network", "Socket binded to port 80"); // this will print both it the file and in the console
	get("network")->error("Network", "Network service unavailable"); // this will print both it the file and in the console
}

void butterfly_initialization()
{
	auto consoleLogger = create_wing<console_wing>("main", level::warning, pattern::complete); // "main" logger will log in the console with a different pattern than the default

	auto networklogger = create_net("network", {consoleLogger, create_wing<file_wing>("", "log-advanced-usage.txt")}); // "network" logger will log both in the console and in the file (through a newly created logger)
	
	set_default_logger(consoleLogger);
}

int main() {

	butterfly_initialization();

	critical_task();

	return 0;
}