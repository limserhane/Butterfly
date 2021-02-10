#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Wing.hpp>

namespace Butterfly
{

class ConsoleWing : public Wing
{
public :
	ConsoleWing(Level::Value pLevel);
	ConsoleWing(std::string pName = "", Level::Value pLevel = Level::trace);

	virtual ~ConsoleWing();

protected :
	virtual void Write(std::string record) override;

}; 

} 