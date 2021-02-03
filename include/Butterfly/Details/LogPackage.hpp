#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

struct LogPackage
{
	LogPackage(std::string pName, Level::Value pLevel, std::string pMessage);

	std::string Name;
	Level::Value Level;
	std::string Message;

}; // struct LogPackage


} // namespace Butterfly