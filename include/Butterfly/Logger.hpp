#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

class Logger
{
public :
	Logger(std::string pName);

	virtual ~ Logger();

	virtual void Log(Level::Value pLevel, std::string pMessage) = 0;

	virtual void Trace(std::string pMessage) final;
	virtual void Error(std::string pMessage) final;

protected :
	std::string mName;
	
}; 

} 