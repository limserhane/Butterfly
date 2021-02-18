#include <butterfly/details/package.hpp>



namespace butterfly
{

package::package(time_t p_time, level::value p_level, std::string_view p_tag, std::string_view p_message):
	time(p_time),
	level(p_level),
	tag(p_tag),
	message(p_message)
{}

} 