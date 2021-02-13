#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Wing.hpp>


namespace Butterfly
{

class ConsoleWing : public Wing
{
public :
	ConsoleWing(Level::Value pLevel);
	ConsoleWing();

	~ConsoleWing();

private :
	virtual void Write(std::string record) override;

};

}