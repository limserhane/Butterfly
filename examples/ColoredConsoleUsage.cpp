
#include <Butterfly/Butterfly.hpp>
#include <Butterfly/Wings/FileWing.hpp>
#include <Butterfly/Wings/ColoredConsoleWing.hpp>

#include <iostream>

using namespace Butterfly;
using namespace std;

int main() {

	SetDefaultLogger(CreateWing<ColoredConsoleWing>("", "[{level:}] {message:}\n"));

	Trace("ColoredConsoleWing", "this is a trace");
	Info("ColoredConsoleWing", "this is an info");
	Warning("ColoredConsoleWing", "this is a warning");
	Error("ColoredConsoleWing", "this is an error");
	Fatal("ColoredConsoleWing", "this is a fatal error");
	Debug("ColoredConsoleWing", BFLY_SOURCE.PrettyFunction + " : this is a debug info");

	return 0;
}