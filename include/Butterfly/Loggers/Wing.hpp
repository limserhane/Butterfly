#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Loggers/Logger.hpp>
#include <Butterfly/Details/Formatter.hpp>

namespace Butterfly
{

namespace Loggers
{

class Wing : public Logger
{

public :
	Wing(Level::Value pLevel);
	Wing(std::string pName = "", Level::Value pLevel = Level::trace);

	virtual ~Wing();

	virtual void Log(Level::Value pLevel, std::string pMessage);

protected :

	virtual void Write(std::string record); /*TO BE ABSTRACT !!!*/

	Level::Value mLevel;
	Formatter mFormatter;

}; // class LoggerWing

} // namespace Loggers

} // namespace Butterfly