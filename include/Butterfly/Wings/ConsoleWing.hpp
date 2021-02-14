#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Wing.hpp>


namespace Butterfly
{

class ConsoleWing : public Wing
{
public :
	
	ConsoleWing(Level::Value pLevel = Level::minimal, std::string pPattern = "");

	ConsoleWing(std::string pPattern);

	// copy constructor ?
	
	~ConsoleWing();

private :
	virtual void Write(std::string record) override;

};

}