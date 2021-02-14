
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

void CriticalTask()
{ 
	// I can retrieve the "main" logger from anywhere
	Trace("Engine", "Engine initialization complete"); // this is a trace so it won't Log
	Get("main")->Error("Engine", "Engine initialization failed"); // this is an error so it will Log
	
	// I can retrieve the "network" logger from anywhere
	Get("network")->Trace("Network", "Socket binded to port 80"); // this will print both it the file and in the console
	Get("network")->Error("Network", "Network service unavailable"); // this will print both it the file and in the console
}

void ButterflyInitialization()
{
	auto consoleLogger = CreateWing<ConsoleWing>("main", Level::warning); // "main" logger will Log in the console

	auto networklogger = CreateNet("network"); // "network" logger will Log both ...
	networklogger->Add(consoleLogger); // ... in the console
	networklogger->Add(
		CreateWing<FileWing>("", "log-advanced-usage.txt") // ... and in the file
	);

	SetDefaultLogger(consoleLogger);
}

int main() {

	ButterflyInitialization();

	CriticalTask();

	return 0;
}