#include <butterfly/wings/colored_console_wing.hpp>

#include <butterfly/details/package_formatters/colored_package_formatter.hpp>

namespace butterfly
{

colored_console_wing::colored_console_wing(level::value p_level, pattern p_pattern):
	console_wing(p_level, std::make_unique<colored_package_formatter>(create_package_formatter(p_pattern)))
{}

colored_console_wing::colored_console_wing(pattern p_pattern):
	colored_console_wing(level::minimal, p_pattern)
{}

colored_console_wing::~colored_console_wing()
{}

}