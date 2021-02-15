#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

struct Package
{
	Package(Source pSource, Level::Value pLevel, std::string pTag, std::string pMessage);

	Source Location;
	Level::Value Level;
	std::string Tag;
	std::string Message;
}; 

} 