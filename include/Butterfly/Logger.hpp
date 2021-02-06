#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

class Logger
{

public :

	Logger(std::string pName = "");
	
	virtual ~ Logger();

	virtual void Log(Level::Value pLevel, std::string pMessage) const = 0;

	virtual void Trace(std::string pMessage) const final;
	virtual void Error(std::string pMessage) const final;

protected :

	std::string mName;
	
}; // class Logger

} // namespace Butterfly