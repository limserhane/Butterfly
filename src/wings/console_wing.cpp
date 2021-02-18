#include <butterfly/wings/console_wing.hpp>


namespace butterfly
{


console_wing::console_wing(level::value p_level, std::unique_ptr<package_formatter> p_formatter):
	wing(p_level, std::move(p_formatter))
{}

console_wing::console_wing(level::value p_level, pattern p_pattern):
	console_wing(p_level, create_package_formatter(p_pattern))
{}

console_wing::console_wing(pattern p_pattern):
	console_wing(level::minimal, p_pattern)
{}

console_wing::~console_wing()
{}

}