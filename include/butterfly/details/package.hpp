#pragma once

#include <butterfly/common.hpp>

#include <string>
#include <time.h>

namespace butterfly
{


/**
 * @brief A structure containing informations about a log record.
 */
struct package
{
	package(time_t p_time, level::value p_level, std::string_view p_tag, std::string_view p_message);

	time_t time;
	level::value level;
	std::string tag;
	std::string message;
}; 

} 