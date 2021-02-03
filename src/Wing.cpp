#include <Butterfly/Loggers/Wing.hpp>

#include <iostream>

namespace Butterfly {

namespace Loggers
{

Wing::Wing():
	Logger{}
{}

Wing::Wing(std::string pName, Level::Value pLevel):
	Logger{pName},
	mLevel{pLevel}
{}

Wing::Wing(Level::Value pLevel):
	Logger{},
	mLevel{pLevel}
{}

Wing::~Wing()
{}


void Wing::Log(Level::Value pLevel, std::string pMessage)
{
	Write(mFormatter.Format(LogPackage(mName, pLevel, pMessage)));
}

void Wing::Write(std::string record)
{
	std::cout << record;
}

} // namespace Loggers

} // namespace Butterfly