#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

struct Package
{
	Package(std::string pName, Level::Value pLevel, std::string pMessage);

	std::string Name;
	Level::Value Level;
	std::string Message;

}; 

} 