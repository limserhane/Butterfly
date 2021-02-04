#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Logger.hpp>
#include <Butterfly/Details/Formatter.hpp>


#include <string>

namespace Butterfly
{

class Wing : public Logger
{

public :
	Wing(Level::Value pLevel);
	Wing(std::string pName = "", Level::Value pLevel = Level::trace);

	virtual ~Wing();

	virtual void Log(Level::Value pLevel, std::string pMessage) override;

protected :

	virtual void Write(std::string record); /*TO BE ABSTRACT !!!*/

	Level::Value mLevel;
	Formatter mFormatter;

}; // class Wing

} // namespace Butterfly