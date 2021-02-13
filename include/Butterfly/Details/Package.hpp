#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

struct Package
{
	Package(Level::Value pLevel, std::string pTag, std::string pMessage);

	Level::Value Level;
	std::string Tag;
	std::string Message;

}; 

} 