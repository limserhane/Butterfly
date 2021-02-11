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
	Wing();

	virtual ~Wing();

	virtual void Log(Level::Value pLevel, std::string pMessage) override;

protected :
	virtual void Write(std::string record);

	PackageFormatter mFormatter;

}; 

} 