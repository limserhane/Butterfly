
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
		Get("network")->Trace("network", "abcdefghij");
	}
}

void bar()
{
	for (int i = 0; i < 1000; ++i)
	{
		Get("engine")->Error("engine", "0123456789");
	}
}

int main() {

	auto logfile = CreateSafeLogger("", 
		CreateWing<FileWing>("", "bin/log.txt")
	);

	auto enginelogger = CreateNet("engine");
	enginelogger->Add(logfile);

	auto networklogger = CreateNet("network");
	networklogger->Add(logfile);

	SetDefaultLogger(enginelogger);

	std::thread foothread(foo);
	std::thread barthread(bar);

	foothread.join();
	barthread.join();

	return 0;
}