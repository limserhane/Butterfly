#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Wings/ConsoleWing.hpp>


namespace Butterfly
{

/**
 * @brief A concrete Wing used to log colored records into the standard output, depending on the level.
 */
class ColoredConsoleWing : public ConsoleWing
{
public :
	ColoredConsoleWing(Level::Value pLevel = Level::minimal, const char* pPattern = PackageFormatter::SimplePattern);
	ColoredConsoleWing(const char* pPattern);
	
	virtual ~ColoredConsoleWing();
};


}