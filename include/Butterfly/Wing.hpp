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
	Wing(Level::Value pLevel = Level::minimal, PackageFormatter pFormatter = PackageFormatter::MinimalPattern);
	Wing(PackageFormatter pFormatter);

	virtual ~Wing();

	virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage, Source pSource = Source()) override;

protected :
	virtual void Write(std::string record) = 0;

	Level::Value mLevel;
	PackageFormatter mFormatter;

}; 

} 