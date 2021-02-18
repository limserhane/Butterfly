
#include <butterfly/butterfly.hpp>
#include <butterfly/wings/file_wing.hpp>
#include <butterfly/wings/colored_console_wing.hpp>

#include <iostream>

using namespace butterfly;
using namespace std;

int main() {

	set_default_logger(create_wing<colored_console_wing>("", pattern::report));

	trace("colored_console_wing", "this is a trace");
	info("colored_console_wing", "this is an info");
	warning("colored_console_wing", "this is a warning");
	error("colored_console_wing", "this is an error");
	fatal("colored_console_wing", "this is a fatal error");
	debug("colored_console_wing", BFLY_SOURCE.pretty_function + " : this is a debug info");

	return 0;
}