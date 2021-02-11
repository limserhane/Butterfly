#include <Butterfly/Wings/Wing.hpp>

#include <iostream>

namespace Butterfly
{

Wing::Wing():
	Logger{},
	mFormatter{}
{}

Wing::~Wing()
{}

void Wing::Log(Level::Value pLevel, std::string pMessage)
{
	Write(mFormatter.Format(Package(pLevel, pMessage)));
}

void Wing::Write(std::string record)
{
	std::cout << record;
}

} 