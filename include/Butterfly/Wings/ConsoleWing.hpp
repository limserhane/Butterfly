#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Wing.hpp>


namespace Butterfly
{

class ConsoleWing : public Wing
{
public :
	
	ConsoleWing(Level::Value pLevel = Level::minimal, PackageFormatter pFormatter = PackageFormatter::SimplePattern);
	ConsoleWing(PackageFormatter pFormatter);

	// copy constructor ?
	
	~ConsoleWing();

private :
	virtual void Write(std::string record) override;

};

}