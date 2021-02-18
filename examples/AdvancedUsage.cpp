
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

void CriticalTask()
{ 
	// "main" logger is the default logger
	Trace("Engine", "Engine initialization complete"); // this is a trace so it won't Log through main

	// I can retrieve the "main" logger from anywhere
	Get("main")->Error("Engine", "Engine initialization failed"); // this is an error so it will Log through main
	
	// I can retrieve the "network" logger from anywhere
	Get("network")->Trace("Network", "Socket binded to port 80"); // this will print both it the file and in the console
	Get("network")->Error("Network", "Network service unavailable"); // this will print both it the file and in the console
}

void ButterflyInitialization()
{
	auto consoleLogger = CreateWing<ConsoleWing>("main", Level::warning, Pattern::complete); // "main" logger will Log in the console with a different pattern than the default

	auto networklogger = CreateNet("network", {consoleLogger, CreateWing<FileWing>("", "log-advanced-usage.txt")}); // "network" logger will Log both in the console and in the file (through a newly created logger)
	
	SetDefaultLogger(consoleLogger);
}

int main() {

	ButterflyInitialization();

	CriticalTask();

	return 0;
}