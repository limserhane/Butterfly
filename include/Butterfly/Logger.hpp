#pragma once

#include <Butterfly/Common.hpp>

#include <string>

namespace Butterfly
{

class Logger
{
public :
	Logger();

	virtual ~ Logger();

	virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage) = 0;

	virtual void Trace(std::string pTag, std::string pMessage) final;
	virtual void Error(std::string pTag, std::string pMessage) final;

}; 

} 