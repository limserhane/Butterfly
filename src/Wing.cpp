#include <Butterfly/Wing.hpp>

#include <iostream>

namespace Butterfly
{

Wing::Wing():
	Logger(),
	mFormatter()
{}

Wing::~Wing()
{}

void Wing::Log(Level::Value pLevel, std::string pTag, std::string pMessage)
{
	Write(mFormatter.Format(Package(pLevel, pTag, pMessage)));
}

} 