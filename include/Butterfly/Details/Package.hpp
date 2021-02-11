#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

struct Package
{
	Package(Level::Value pLevel, std::string pMessage);

	Level::Value Level;
	std::string Message;

}; 

} 