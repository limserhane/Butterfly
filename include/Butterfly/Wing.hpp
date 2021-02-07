#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Logger.hpp>
#include <Butterfly/Details/PackageFormatter.hpp>


#include <string>

namespace Butterfly
{

class Wing : public Logger
{
public :
	Wing(Level::Value pLevel);
	Wing(std::string pName = "", Level::Value pLevel = Level::trace);

	virtual ~Wing();

	virtual void Log(Level::Value pLevel, std::string pMessage) const override;

protected :
	virtual void Write(std::string record) const = 0;

	Level::Value mLevel;
	PackageFormatter mFormatter;

}; 

} 