#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

namespace Loggers
{

class Logger
{

public :

	Logger(std::string pName = "");
	
	virtual ~ Logger();

	virtual void Log(Level::Value pLevel, std::string pMessage) = 0;

	virtual void Trace(std::string pMessage);

protected :

	std::string mName;
	
}; // class Logger

} // namespace Loggers

} // namespace Butterfly