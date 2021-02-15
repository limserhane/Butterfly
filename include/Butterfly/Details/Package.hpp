#pragma once

#include <Butterfly/Common.hpp>

#include <string>
#include <time.h>

namespace Butterfly
{


/**
 * @brief A structure containing informations about a log record.
 */
struct Package
{
	Package(Source pSource, time_t pTime, Level::Value pLevel, std::string pTag, std::string pMessage);

	Source Location;
	time_t Time;
	Level::Value Level;
	std::string Tag;
	std::string Message;
}; 

} 